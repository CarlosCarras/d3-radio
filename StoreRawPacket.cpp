/*
 * StoreRawPacket.cpp
 * @author        : Carlos Carrasquillo
 * @contact       : c.carrasquillo@ufl.edu
 * @date created  : October 13, 2020
 * @date modified : October 13, 2020
 * @description   : stores incoming characters into a .txt file.
 *
 * Property of ADAMUS lab, University of Florida.
 */

#include "StoreRawPacket.h"

void storePacket() {
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    char input;

    std::ofstream rawfile;
    rawfile.open ("./../rawfile.txt");

    if (rawfile.is_open()) {
        while (std::chrono::steady_clock::now() - start <= std::chrono::seconds(35)) {
            input = std::cin.get();
            rawfile << input;
        }
    }

    rawfile.close();
}
