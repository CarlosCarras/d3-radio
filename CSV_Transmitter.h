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


#ifndef CSV_TRANSMITTER_H
#define CSV_TRANSMITTER_H


#include <iostream>
#include <fstream>                  // read/write file operations
#include "CPUT_Transceiver.h"


#define CSV_PATH         "./../test"


class CSV_Transmitter {

private:
    int trans_cnt;

    std::string get_csv_path();


public:
    CSV_Transmitter();
    int transmit_csv();

    //virtual ~CSV_Transmitter();
};


#endif //CSV_TRANSMITTER_H
