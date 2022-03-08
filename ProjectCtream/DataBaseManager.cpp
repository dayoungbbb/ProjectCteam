#include <queue>
#include <vector>
#include <fstream>
#include <list>
#include "Define.h"
#include "Printer.h"
#include "ParserManager.h"
#include "Operator.h"
#include "Searcher.h"
#include "DataBaseManager.h"

DataBaseManager::DataBaseManager() {
	columnMap.resize(MAX_COLUMNTYPE);

	operatorManager = new OperatorManager(&dataBase, &columnMap);
	searcherManager = new SearcherManager(&dataBase, &columnMap);
	printer = new Printer(dataBase);
}

DataBaseManager::~DataBaseManager() {
	delete operatorManager;
	operatorManager = nullptr;
	delete searcherManager;
	searcherManager = nullptr;
	delete printer;
	printer = nullptr;
}

void DataBaseManager::operateSearcher(int cmdType, const void* cmdString, vector<string> &searchList) {
	if (cmdType == ADD)
		return;

	dataBaseSearcher = searcherManager->getSearcher(cmdString);
	if (dataBaseSearcher == nullptr) {
		throw invalid_argument("dataBaseSearcher is NULL");
	}

	searchList = dataBaseSearcher->search(cmdString);
}

void DataBaseManager::operateOperator(int cmdType, void* cmdString, vector<string>& searchList) {
	if (cmdType == SCH)
		return;

	dataBaseOperator = operatorManager->getOperator(static_cast<CmdType>(cmdType));
	if (dataBaseOperator == nullptr) {
		throw invalid_argument("dataBaseSearcher is NULL");
	}

	dataBaseOperator->operate(searchList, cmdString);
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
		void* cmdString = cmdParameter.getCmdString();
		
		vector<string> searchList;
		operateSearcher(cmdType, cmdString, searchList);

		printer->setOutputFileName(outputFileName);
		printer->print(cmdType, cmdString, searchList, isFirst);

		operateOperator(cmdType, cmdString, searchList);
	}

	inputFile.close();
}