/*
 * SendFile.cpp
 * @author        : Carlos Carrasquillo
 * @contact       : c.carrasquillo@ufl.edu
 * @date created  : April 24, 2020
 * @date modified : May 1, 2020
 * @description   : reads the contents of a file and sends them over the i2c bus.
 *
 * Property of ADAMUS lab, University of Florida.
 */

#include "SendFile.h"


SendFile::SendFile() {
    trans_cnt = 0;
}


/*
 * SendFile::get_extension(const std::string &filename) : gets the extension of a file to define the file type
 *
 * @Param:
 *      - const std::string &filename : the name of the file (including the file path) to be transmitted
 * @Return:
 *      - std::string ext : the extension of the file (i.e. "csv", "c", "py", etc.)
 */
std::string SendFile::getExtension(const std::string &filename) {
    auto pos = filename.find_last_of ( '.' );

    if (pos == std::string::npos) return "";

    std::string ext (filename.substr(pos + 1));
    if (std::regex_search (ext, std::regex("[^A-Za-z0-9]") )) return "" ;

    return ext;
}


/*
 * SendFile::addFileIdentifierStart() : attaches a message identifying the type of file to be transmitted. Useful when
 *                                      decoding the string of characters after the file has been transmitted.
 *
 * @Param :
 *      - const std::string &ext : the file's extension (i.e. "csv", "c", "py", etc.)
 * @Return :
 *      - N/A
 */
void SendFile::addFileIdentifier(CPUT_Transceiver &transceiver, const std::string &filename, std::string ext, bool start_file) {
    int op_code;
    std::string data;

    if      (ext == "csv")  op_code = CSV_FILE_CODE;
    else if (ext == "py")   op_code = PY_FILE_CODE;
    else if (ext == "c")    op_code = C_FILE_CODE;
    else return;

    if (start_file) {
        data += ">>  Receiving File: " + filename + "\n";
        data += std::to_string((op_code << 4) | (0x1 & START_FILE));
    } else {
        data = std::to_string((op_code << 4) | (0x1 & END_FILE));
        data += "\n>>  Done Receiving File: " + filename + "\n";
    }

    transceiver.transmitString(data);
}


/*
 * SendFile::send(std::string filename) : transmits the latest CSV file line by line by making calls to the CPUT_Transceiver
 *
 * @Param:
 *      - std::string filename : the name of the file (including the file path) to be transmitted
 * @Return:
 *      - 0 if successful, 1 if error
 */
int SendFile::send(std::string filename) {

    CPUT_Transceiver transceiver;
    std::ifstream csv(filename);     // opens CSV file

    // if the file is not open, transmit an error over I2C
    if(!csv.is_open()) {
        std::string err_msg = "\nERROR 404: The file " + filename + " was unable to be opened.\n";
        transceiver.transmitString(err_msg);
        return 1;
    }

    std::string ext = getExtension(filename);      // gets file extension

    addFileIdentifier(transceiver, filename, ext, START_FILE);
    std::string data;
    while(csv.good()) {                             // transmits each line of the CSV over I2C
        getline(csv, data);
        transceiver.transmitString(data);
    }
    addFileIdentifier(transceiver, filename, ext, END_FILE);

    trans_cnt++;;

    return 0;
}
