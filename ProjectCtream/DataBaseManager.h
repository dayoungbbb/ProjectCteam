#pragma once

class DataBaseManager {
public:
	DataBaseManager();
	~DataBaseManager();
	void operate(std::string inputFileName, std::string outputFileName);
private:
	void operateSearcher(int cmdType, const void* cmdString, vector<string>& searchList);
	void operateOperator(int cmdType, void* cmdString, vector<string>& searchList);

	CmdParameter cmdParameter;
	
	OperatorManager* operatorManager;
	SearcherManager* searcherManager;
	Searcher* dataBaseSearcher;
	Operator* dataBaseOperator;

	Printer* printer;

	map<string, Employee> dataBase;
	vector<multimap<string, string>> columnMap;
};