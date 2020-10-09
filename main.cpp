/*
 * i2c_write_str
 * @author        : Carlos Carrasquillo
 * @contact       : c.carrasquillo@ufl.edu
 * @date created  : April 14, 2020
 * @date modified : April 14, 2020
 * @description   : reads the contents of a csv file and sends them over the i2c bus.
 *
 * Property of ADAMUS lab, University of Florida.
 */


#include "CSV_Transmitter.h"

#define loops           3

int main() {
    CSV_Transmitter csv_transmitter;

    // this is supposed to work once and fail twice (only one CSV file called "test0.csv")
    // NOTE:  fix the  'CSV_PATH' define in CSV_Transmitter.h
    for (int i = 0; i < loops; i++) {
        csv_transmitter.transmit_csv();
    }
}