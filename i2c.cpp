/*
 * i2c.cpp
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


#include "i2c.h"


/*
 * i2c_write_char
 *
 * @Param:
 *      - c : A char to be output over I2C.
 * @Return:
 *      - N/A
 */
void i2c_write_char(char const &c) {
    std::cout << c;
}


/*
 * i2c_write_str
 *
 * @Param:
 *      - str : A string to be output over I2C.
 * @Return:
 *      - N/A
 */
void i2c_write_str(std::string const &str) {
    // for-each loop: transmits each char over i2c
    std::for_each(str.begin(), str.end(), i2c_write_char);
}