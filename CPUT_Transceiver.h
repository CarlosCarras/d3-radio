/*
 * transeiver.h
 * @author        : Carlos Carrasquillo
 * @contact       : c.carrasquillo@ufl.edu
 * @date created  : April 17, 2020
 * @date modified : April 17, 2020
 * @description   : controls CPUT transiver operations over the I2C 2C bus.
 * @hardware      : CPUT Transeiver (Cape Peninsula University of Technology)
 *
 * Property of ADAMUS lab, University of Florida.
 */


#ifndef CSV_2_I2C_I2C_H
#define CSV_2_I2C_I2C_H

#include <iostream>
#include "i2c.h"


#define CPUT_TRANSCEIVER_I2C_ADDR           0x25


class CPUT_Transceiver {

private:
    int I2CBus, I2CAddress;
    char dataBuffer[CPUT_TRANSCEIVER_I2C_ADDR];

public:
    CPUT_Transceiver(int bus, int address);
    void transmit_str(std::string data);

    //virtual ~CPUT_Transceiver();
};


#endif //CSV_2_I2C_I2C_H