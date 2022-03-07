#include "pch.h"
#include <string>
#include <fstream>

#include "TestUtil.h"

unsigned long long getOutputFileCheckSum(std::string fileName) {
    std::ifstream outputFile;
    outputFile.open(fileName);
    if (outputFile.fail()) {
        throw std::invalid_argument("file open failed");
    }

    unsigned long long checkSum = 0;
    char c;
    while (outputFile.get(c)) {
        if (c == '\n') continue;
        checkSum += static_cast<unsigned long long>(c);
    }
    outputFile.close();

    return checkSum;
}