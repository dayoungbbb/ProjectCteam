#include <queue>
#include <vector>
#include <fstream>
#include <list>
#include "define.h"
#include "Employee.h"
#include "Printer.h"
#include "cmdParameter.h"
#include "Operator.h"
#include "Searcher.h"
#include "DataBaseManager.h"

DataBaseManager::DataBaseManager() {
	multimap<string, string> employNumMap, nameMap, clMap, phoneNumMap, bDayMap, certiMap, 
		FirstNameMap, LastNameMap,  middlePhoneNumMap, backPhoneNumMap, yearBdayMap, monthBdayMap, dateBdayMap;

	columnMap.push_back(employNumMap);
	columnMap.push_back(nameMap);
	columnMap.push_back(clMap);
	columnMap.push_back(phoneNumMap);
	columnMap.push_back(bDayMap);
	columnMap.push_back(certiMap);
	columnMap.push_back(FirstNameMap);
	columnMap.push_back(LastNameMap);
	columnMap.push_back(middlePhoneNumMap);
	columnMap.push_back(backPhoneNumMap);
	columnMap.push_back(yearBdayMap);
	columnMap.push_back(monthBdayMap);
	columnMap.push_back(dateBdayMap);

	operatorManager = new OperatorManager(&dataBase, &columnMap);
	searcherManager = new SearcherManager(&dataBase, &columnMap);
}

DataBaseManager::~DataBaseManager() {
	delete operatorManager;
	operatorManager = nullptr;
	delete searcherManager;
	searcherManager = nullptr;
}

void DataBaseManager::operateSearcher(int cmdType, const CmdString cmdString, prioirtyQ&searchQ) {
	if (cmdType == ADD)
		return;

	dataBaseSearcher = searcherManager->getSearcher(cmdString);
	if (dataBaseSearcher == nullptr) {
		throw invalid_argument("dataBaseSearcher is NULL");
	}

	searchQ = dataBaseSearcher->search(cmdString);
}

void DataBaseManager::operateOperator(int cmdType, CmdString cmdString, prioirtyQ& searchQ) {
	if (cmdType == SCH)
		return;

	dataBaseOperator = operatorManager->getOperator(static_cast<CmdType>(cmdType));
	if (dataBaseOperator == nullptr) {
		throw invalid_argument("dataBaseSearcher is NULL");
	}

	vector<string> temp;

	dataBaseOperator->operate(temp, cmdString);
}


void DataBaseManager::operate(std::string inputFileName, std::string outputFileName) {

	ifstream inputFile;
	inputFile.open(inputFileName);

	if (!inputFile.is_open()) {
		throw invalid_argument("input file open failed");
	}

	bool isFirst = true;
	int cnt = 0;
	while (!inputFile.eof()) {
		string cmd;
		getline(inputFile, cmd);
		if (!cmd.size()) break;

		if (!cmdParameter.parse(cmd)) {
			throw invalid_argument("parse CmdParameter failed");
		}

		int cmdType = cmdParameter.getCmdType();
		CmdString cmdString = cmdParameter.getCmdString();
		
		prioirtyQ searchQ;
		operateSearcher(cmdType, cmdString, searchQ);

		printer.setOutputFileName(outputFileName);
		printer.print(cmdType, cmdString.op1, searchQ, isFirst);

		operateOperator(cmdType, cmdString, searchQ);
	}

	inputFile.close();
}