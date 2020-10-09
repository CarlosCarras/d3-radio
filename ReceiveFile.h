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

#ifndef RECEIVEFILE_H
#define RECEIVEFILE_H

#include <iostream>
#include <fstream>                  // read/write file operations
#include <string>
#include <direct.h>


class ReceiveFile {

private:
    struct fileData {
        std::string filepath;
        std::string filename;
        std::string filedir;
    };

    std::string rawfile;
    std::string createFile();
    fileData createFile(std::string &filepath);

public:
    explicit ReceiveFile();
    bool writeFile();

};

#endif //RECEIVEFILE_H