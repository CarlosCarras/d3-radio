/*
 * ReceiveFile.cpp
 * @author        : Carlos Carrasquillo
 * @contact       : c.carrasquillo@ufl.edu
 * @date created  : October 9, 2020
 * @date modified : October 9, 2020
 * @description   : reads the contents of a file and sends them over the i2c bus.
 *
 * Property of ADAMUS lab, University of Florida.
 */

#include "ReceiveFile.h"

ReceiveFile::ReceiveFile() {
    rawfile = "./../incoming.txt";
}

/*
 * ReceiveFile::createFile(std::string &filepath) : creates a fileData struct and creates the directory
 *                                                 for an incoming file.
 *
 * @Param:
 *      - const std::string &filename : the name of the file (including the file path) to be written
 * @Return:
 *      - ReceiveFile::fileData : the filename, filepath, and filedir strings in a struct
 */
ReceiveFile::fileData ReceiveFile::createFile(std::string &filepath) {
    fileData newFile_data;
    newFile_data.filepath = filepath;

    auto pos = filepath.find_last_of ( '/' );

    if (pos == std::string::npos) {
        newFile_data.filedir = "./";
        newFile_data.filename = filepath;
    } else {
        newFile_data.filedir = filepath.substr(0, pos);
        newFile_data.filename = filepath.substr(pos + 1);

        bool status = _mkdir(newFile_data.filedir.c_str());
        if (!status) {
            std::cout << "Successfully created directory: " + newFile_data.filedir << std::endl;
        } else {
            std::cout << "The directory: " + newFile_data.filedir << " was not created." << std::endl;
        }
    }

    return newFile_data;
}

/*
 * ReceiveFile::writeFile() : writes the contents of the incoming.txt file into a new directory.
 *
 * @Param:
 *      - N/A
 * @Return:
 *      - 0 if successful, 1 if error
 */
bool ReceiveFile::writeFile() {
    std::ifstream incoming(rawfile);

    if (incoming.is_open()) {
        std::string line;
        std::getline(incoming, line);
        fileData newFile_data = createFile(line);

        std::ofstream newFile;
        newFile.open(newFile_data.filepath);
        while (std::getline(incoming, line)) {
            newFile << line << "\n";
        }

        incoming.close();
        newFile.close();
        std::cout << "Successfully saved file: " + newFile_data.filename << std::endl;
    } else return 1;

    return 0;
}



