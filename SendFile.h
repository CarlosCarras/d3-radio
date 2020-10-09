/*
 * SendFile.h
 * @author        : Carlos Carrasquillo
 * @contact       : c.carrasquillo@ufl.edu
 * @date created  : April 24, 2020
 * @date modified : May 1, 2020
 * @description   : reads the contents of a csv file and sends them over the i2c bus.
 *
 * Property of ADAMUS lab, University of Florida.
 */


#ifndef SEND_FILE_H
#define SEND_FILE_H

#include <iostream>
#include <fstream>                  // read/write file operations
#include <regex>
#include "CPUT_Transceiver.h"


#define CSV_FILE_CODE   0xFFF0
#define PY_FILE_CODE    0xFFF1
#define C_FILE_CODE     0xFFF2

#define START_FILE      1
#define END_FILE        0


class SendFile {

private:
    int bus;
    int trans_cnt;
    std::string getExtension(const std::string &filename);
    void addFileIdentifier(CPUT_Transceiver &transceiver, const std::string &filename, std::string ext, bool start_file);

public:
    explicit SendFile(int bus);
    int send(std::string filename);

    //virtual ~CSV_Transmitter();
};


#endif //SEND_FILE_H
