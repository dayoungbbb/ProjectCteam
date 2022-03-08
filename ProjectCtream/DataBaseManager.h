#pragma once

class DataBaseManager {
public:
	DataBaseManager();
	~DataBaseManager();
	void operate(std::string inputFileName, std::string outputFileName);
private:
	void operateSearcher(int cmdType, const void* cmdString, unordered_set<string>& searchList);
	void operateOperator(int cmdType, void* cmdString, unordered_set<string>& searchList);

	CmdParameter cmdParameter;
	
	OperatorManager* operatorManager;
	SearcherManager* searcherManager;

	Printer* printer;

	map<string, Employee> dataBase;
	vector<map<string, unordered_set<string>>> columnMap;
};