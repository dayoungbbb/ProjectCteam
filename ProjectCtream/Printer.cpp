#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Define.h"
#include "Printer.h"

static constexpr int MAX_PRINT_CNT = 5;

Printer::Printer(map<string, Employee>& dataBase_) : dataBase(dataBase_) {
	outputFileName = "";
	firstWrite = true;
}

void Printer::setOutputFileName(const std::string &outputFileName) {
	this->outputFileName = outputFileName;
}

string  Printer::getPrintOptionString(int cmdType, unordered_set<string>& searchList) {
	std::string result("");
	int writeCount = 0;
	set<string> orderedList;
	for (auto a : searchList) {
		orderedList.insert(addStr(a));
	}

	for (auto searchList : orderedList) {
		auto employeeNum = searchList.substr(2, 8);

		result += CmdTypeStr[cmdType] + ",";
		result += dataBase[employeeNum].employeeNum + ",";
		result += dataBase[employeeNum].name.firstName + " " + dataBase[employeeNum].name.lastName + ",";
		result += dataBase[employeeNum].cl + ",";
		result += "010-" + dataBase[employeeNum].phoneNum.middle + "-" + dataBase[employeeNum].phoneNum.last + ",";
		result += dataBase[employeeNum].bday.year + dataBase[employeeNum].bday.month + dataBase[employeeNum].bday.day + ",";
		result += dataBase[employeeNum].certi + "\n";

		writeCount++;
		if (writeCount == MAX_PRINT_CNT) break;
	}

	return result;
}

void Printer::print(int cmdType, void* cmdString, unordered_set<string>& searchList) {
	if (cmdType == ADD) {
		return;
	}

	std::string result("");
	ofstream outputFile;
	std::ios_base::open_mode openMode = firstWrite ?
		std::ios::out : (std::ios::out | std::ios::app);

	if (outputFileName.size() == 0) {
		outputFileName = "output.txt";
	}

	outputFile.open(outputFileName, openMode);
	if (!outputFile.is_open()) {
		throw invalid_argument("output.txt file open failed");
	}
	SchCmd* schCmd = (SchCmd*)cmdString;
	if (schCmd->printOption == ENABLE) {
		result = getPrintOptionString(cmdType, searchList);
	}

	if (!result.size()) {
		result = CmdTypeStr[cmdType] + "," + (searchList.size() > 0 ?
			to_string(searchList.size()) : "NONE") + "\n";
	}

	firstWrite = false;
	outputFile.write(result.c_str(), result.size());
	outputFile.close();
}
