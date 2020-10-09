/*
 * i2c.h
 * @author        : Carlos Carrasquillo
 * @contact       : c.carrasquillo@ufl.edu
 * @date created  : April 16, 2020
 * @date modified : April 16, 2020
 * @description   : sends strings and characters over the i2c bus.
 *
 * Modifications Needed: Adding functionality to I2C_WRITE_CHAR().
 *
 * Property of ADAMUS lab, University of Florida.
 */


#ifndef I2C_H
#define I2C_H


#include <iostream>

void i2c_write_char(char const &c);
void i2c_write_str(std::string const &str);


#endif //I2C_H