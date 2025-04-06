#include "file.h"
#include <iostream>
void open(std::ifstream& input, std::ofstream& output) {
    input.open("text.txt");
    if (!input.is_open()) {
        std::cerr << "input file is not open\n"; 
        return;
    }
    output.open("result.txt");
    if (!output.is_open()) {
        std::cerr << "output file is not open\n";
        return;
    }
}
void close(std::ifstream& input, std::ofstream& output) {
    input.close();
    output.close();
}