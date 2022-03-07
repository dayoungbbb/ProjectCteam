#pragma once

class Printer {
public:
	Printer(map<string, Employee>& dataBase_);
	void setOutputFileName(const std::string& outputFileName);
	void print(int cmdType, std::string op1, vector<string> searchList, bool &isFirst);
private:
	std::string outputFileName;
	map<string, Employee>& dataBase;
};