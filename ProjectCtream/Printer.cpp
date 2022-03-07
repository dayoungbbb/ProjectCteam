#include <vector>
#include <string>
#include <fstream>

#include "define.h"
#include "Employee.h"
#include "Printer.h"

#include <iostream>

static constexpr int MAX_PRINT_CNT = 5;

Printer::Printer() {
	outputFileName = "";
}

void Printer::setOutputFileName(const std::string &outputFileName) {
	this->outputFileName = outputFileName;
}

void Printer::print(int cmdType, void* cmdString, prioirtyQ searchQ, bool &isFirst) {
	if (cmdType == ADD) {
		return;
	}
	SchCmd* schCmd = (SchCmd*)cmdString;
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

	if (schCmd->firstOptionType == PRINT) {
		while (!searchQ.empty() && writeCount < MAX_PRINT_CNT) {
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
		}
	}

	if (!writeCount) {
		result = CmdTypeStr[cmdType] + "," + (searchQ.size() > 0 ?
			to_string(searchQ.size()) : "NONE") + "\n";
	}

	isFirst = false;
	outputFile.write(result.c_str(), result.size());
	outputFile.close();
}