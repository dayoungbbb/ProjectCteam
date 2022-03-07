#include <vector>
#include <string>
#include <fstream>

#include "define.h"
#include "Employee.h"
#include "Printer.h"

#include <iostream>

static constexpr int MAX_PRINT_CNT = 5;

Printer::Printer(map<string, Employee>& dataBase_) : dataBase(dataBase_) {
	outputFileName = "";
}

void Printer::setOutputFileName(const std::string &outputFileName) {
	this->outputFileName = outputFileName;
}

void Printer::print(int cmdType, std::string op1, vector<string> searchList, bool &isFirst) {
	if (cmdType == ADD) {
		return;
	}

	std::string result("");
	ofstream outputFile;
	std::ios_base::open_mode openMode = isFirst ?
		std::ios::out : (std::ios::out | std::ios::app);

	if (outputFileName.size() == 0) {
		outputFileName = "output.txt";
	}

	outputFile.open(outputFileName, openMode);
	if (!outputFile.is_open()) {
		throw invalid_argument("output.txt file open failed");
	}

	int writeCount = 0;
	if (op1 == "-p") {
		while (!searchList.empty() && writeCount < MAX_PRINT_CNT) {
#if 0 // TODO: Modify
			list<Employee>::iterator iter = searchQ.top();
			searchQ.pop();

			result += CmdTypeStr[cmdType] + ",";
			result += (*iter).employeeNum + ",";
			result += (*iter).name.firstName + " " + (*iter).name.lastName + ",";
			result += (*iter).cl + ",";
			result += "010-" + (*iter).phoneNum.middle + "-" + (*iter).phoneNum.last + ",";
			result += (*iter).bday.year + (*iter).bday.month + (*iter).bday.day + ",";
			result += (*iter).certi + "\n";

			writeCount++;
#endif
		}
	}

	if (!writeCount) {
		result = CmdTypeStr[cmdType] + "," + (searchList.size() > 0 ?
			to_string(searchList.size()) : "NONE") + "\n";
	}

	isFirst = false;
	outputFile.write(result.c_str(), result.size());
	outputFile.close();
}