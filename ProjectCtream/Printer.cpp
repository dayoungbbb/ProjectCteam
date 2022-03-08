#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Define.h"
#include "Printer.h"

static constexpr int MAX_PRINT_CNT = 5;

Printer::Printer(map<string, Employee>& dataBase_) : dataBase(dataBase_) {
	outputFileName = "";
}

void Printer::setOutputFileName(const std::string &outputFileName) {
	this->outputFileName = outputFileName;
}

void Printer::print(int cmdType, void* cmdString, vector<string> searchList, bool &isFirst) {
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
	SchCmd* schCmd = (SchCmd*)cmdString;
	int writeCount = 0;
	if (schCmd->printOption == PRINT) {
		auto comp = [](string a, string b) {
			cmp cmp;
			string aStr = cmp.addStr(a);
			string bStr = cmp.addStr(b);

			return stoi(aStr) < stoi(bStr);
		};
		sort(searchList.begin(),searchList.end(), comp);

		for (auto searchList : searchList) {
			result += CmdTypeStr[cmdType] + ",";
			result += dataBase[searchList].employeeNum + ",";
			result += dataBase[searchList].name.firstName + " " + dataBase[searchList].name.lastName + ",";
			result += dataBase[searchList].cl + ",";
			result += "010-" + dataBase[searchList].phoneNum.middle + "-" + dataBase[searchList].phoneNum.last + ",";
			result += dataBase[searchList].bday.year + dataBase[searchList].bday.month + dataBase[searchList].bday.day + ",";
			result += dataBase[searchList].certi + "\n";

			writeCount++;
			if (writeCount == MAX_PRINT_CNT) break;
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