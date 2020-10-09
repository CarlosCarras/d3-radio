#include "SendFile.h"

#define CSV_PATH         "./../test"

volatile int trans_cnt = 0;


/*
 * CSV_Transmitter::get_csv_path() : returns the relative file path of the latest CSV file
 *
 * @Param:
 *      - N/A
 * @Return:
 *      - csv_path : the relative file path of the latest CSV file
 */
std::string get_csv_path() {
    std::string csv_path = CSV_PATH + std::to_string(trans_cnt) + ".csv";
    return csv_path;
}



int main() {
    int bus = 5;
    SendFile sendFile(bus);

    // this is supposed to work once and fail twice (only one CSV file called "test0.csv")
    // NOTE:  fix the  'CSV_PATH' define in CSV_Transmitter.h
    for (int i = 0; i < 3; i++) {
        sendFile.send(get_csv_path());
        trans_cnt++;
    }
}