#include <vector>
#include <string>
#include <fstream>

#include "define.h"
#include "Employee.h"
#include "Printer.h"

#include <iostream>

static constexpr int MAX_PRINT_CNT = 5;

void Printer::print(int cmdType, std::string op1, prioirtyQ searchQ, bool &isFirst) {
	if (cmdType == ADD) {
		return;
	}

	std::string result("");
	ofstream outputFile;
	std::ios_base::open_mode openMode = isFirst ?
		std::ios::out : (std::ios::out | std::ios::app);

	outputFile.open("output.txt", openMode);
	if (!outputFile.is_open()) {
		throw invalid_argument("output.txt file open failed");
	}

	int writeCount = 0;
	if (op1 == "-p") {
		while (!searchQ.empty() && writeCount < MAX_PRINT_CNT) {
			vector<Employee>::iterator iter = searchQ.top();
			searchQ.pop();

			result += CmdTypeStr[cmdType] + ",";
			result += (*iter).employeeNum + ",";
			result += (*iter).lastName + " " + (*iter).firstName + ",";
			result += (*iter).cl + ",";
			result += "010-" + (*iter).middleOfPhoneNum + "-" + (*iter).backOfPhoneNum + ",";
			result += (*iter).yearOfBday + (*iter).monthOfBday + (*iter).dateOfBday + ",";
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