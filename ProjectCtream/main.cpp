#include <string>
#include <iostream>

#include "define.h"
#include "Printer.h"
#include "cmdParameter.h"
#include "Operator.h"
#include "Searcher.h"
#include "DataBaseManager.h"

static constexpr int INPUT_PARAM_NUM = 2;

static bool isValidFileName(const std::string &fileName) {
    if (fileName.substr(fileName.size() - 4, 4) != ".txt") {
        return false;
    }

    if (fileName[0] == '/' || fileName.find("../") != -1) {
        std::cout << "Upper directory not allowed" << std::endl;
        return false;
    }

    return true;
}

int main(int argc, char **argv)
{
    if (argc != (INPUT_PARAM_NUM + 1)) {
        std::cout << "input parameter num not correct" << std::endl;
        std::cout << "Usage: *.exe <inputFileName> <outputFileName>" << std::endl;
        exit(EXIT_FAILURE);
    }

    const std::string inputFileName = argv[1];
    const std::string outputFileName = argv[2];

    if (!isValidFileName(inputFileName) || !isValidFileName(outputFileName)) {
        std::cout << "Filename not correct" << std::endl;
        exit(EXIT_FAILURE);
    }

    DataBaseManager* dataBaseManager = new DataBaseManager();
    dataBaseManager->operate(inputFileName, outputFileName);

    delete dataBaseManager;

    return 0;
}