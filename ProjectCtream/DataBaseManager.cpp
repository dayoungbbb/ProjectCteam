#include <queue>
#include <vector>
#include <fstream>
#include <unordered_map>
#include "define.h"
#include "Employee.h"
#include "Printer.h"
#include "cmdParameter.h"
#include "Operator.h"
#include "Searcher.h"
#include "DataBaseManager.h"

DataBaseManager::DataBaseManager() {
	operatorManager = new OperatorManager(&dataBase);
	searcherManager = new SearcherManager(&dataBase);

}

DataBaseManager::~DataBaseManager() {
	delete operatorManager;
	delete searcherManager;
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

	dataBaseOperator->operate(searchQ, cmdString);
}


void DataBaseManager::operate(std::string inputFileName) {

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

		printer.print(cmdType, cmdString.op1, searchQ, isFirst);

		operateOperator(cmdType, cmdString, searchQ);
	}

	inputFile.close();
}