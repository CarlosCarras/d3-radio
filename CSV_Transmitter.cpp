/*
 * CSV_Transmitter
 * @author        : Carlos Carrasquillo
 * @contact       : c.carrasquillo@ufl.edu
 * @date created  : April 24, 2020
 * @date modified : April 24, 2020
 * @description   : reads the contents of a csv file and sends them over the i2c bus.
 *
 * Property of ADAMUS lab, University of Florida.
 */

#include "CSV_Transmitter.h"


CSV_Transmitter::CSV_Transmitter() {
    trans_cnt = 0;
}


/*
 * CSV_Transmitter::get_csv_path() : returns the relative file path of the latest CSV file
 *
 * @Param:
 *      - N/A
 * @Return:
 *      - csv_path : the relative file path of the latest CSV file
 */
std::string CSV_Transmitter::get_csv_path() {
    std::string csv_path = CSV_PATH + std::to_string(trans_cnt) + ".csv";
    return csv_path;
}


/*
 * CSV_Transmitter::transmit_csv() : transmits the latest CSV file line by line by making calls to the CPUT_Transceiver
 *
 * @Param:
 *      - N/A
 * @Return:
 *      - 0 if successful, 1 if error
 */
int CSV_Transmitter::transmit_csv() {

    CPUT_Transceiver transceiver(1, 2);
    std::ifstream csv(get_csv_path());     // opens CSV file

    // if the file is not open, transmit an error over I2C
    if(!csv.is_open()) {
        std::string err_msg("\nERROR 404: The csv file was unable to be opened.\n");
        transceiver.transmit_str(err_msg);
        return 1;
    }

    std::string data;

    // transmits each line of the CSV over I2C
    while(csv.good()) {
        getline(csv, data);
        transceiver.transmit_str(data);
    }

    trans_cnt++;;

    return 0;
}
