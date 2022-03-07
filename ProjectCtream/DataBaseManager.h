#pragma once

class DataBaseManager {
public:
	DataBaseManager();
	~DataBaseManager();
	void operate(std::string inputFileName, std::string outputFileName);
private:
	void operateSearcher(int cmdType, const void* cmdString, prioirtyQ& searchQ);
	void operateOperator(int cmdType, void* cmdString, prioirtyQ& searchQ);

	CmdParameter cmdParameter;
	
	OperatorManager* operatorManager;
	SearcherManager* searcherManager;
	Searcher* dataBaseSearcher;
	Operator* dataBaseOperator;

	Printer printer;

	std::list<Employee> dataBase;
};