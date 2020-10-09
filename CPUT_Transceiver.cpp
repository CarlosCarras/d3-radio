/*
 * CPUT_Transceiver.cpp
 * @author        : Carlos Carrasquillo
 * @contact       : c.carrasquillo@ufl.edu
 * @date created  : April 17, 2020
 * @date modified : April 17, 2020
 * @description   : controls CPUT transiver operations over the I2 bus.
 * @hardware      : CPUT Transeiver (Cape Peninsula University of Technology)
 *
 * Property of ADAMUS lab, University of Florida.
 */

#include "CPUT_Transceiver.h"


CPUT_Transceiver::CPUT_Transceiver(int bus, int address){
    I2CBus = bus;
    I2CAddress = address;
}


/*
 * CPUT_Transceiver::transmitString : sends a string of data to the antenna over I2C
 *
 * @Param:
 *      - data : the string to write over I2C
 * @Return:
 *      - N/A
 */
void CPUT_Transceiver::transmitString(std::string data) {
    i2c_write_str(data + '\n');
}