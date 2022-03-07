#pragma once

struct cmp {
    string addStr(string str) {
        string ret = "";
        if (stoi(str.substr(0, 1)) <= 2)
            return ret = "20" + str;
        else if (stoi(str.substr(0, 1)) >= 6)
            return ret = "19" + str;
        else
            return ret;
    }

    bool operator()(list<Employee>::iterator a, list<Employee>::iterator b) {
        string aStr = addStr(a->employeeNum);
        string bStr = addStr(b->employeeNum);
        return stoi(aStr) > stoi(bStr);
    }
};

class Printer {
public:
	Printer(map<string, Employee>& dataBase_);
	void setOutputFileName(const std::string& outputFileName);
	void print(int cmdType, void* cmdString, vector<string> searchList, bool &isFirst);
private:
	std::string outputFileName;
	map<string, Employee>& dataBase;
};