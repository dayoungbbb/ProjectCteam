#include "Employee.h"
#include "DelOperator.h"
#include <iostream>

void delFromDataBase(string &condition, string &param, int &recordCount, int &index) {
	if (condition == param) {
		recordCount++;
		dataBase.erase(dataBase.begin() + index);
		index--;
	}
}

void delNameColumn(std::string& op2, std::string& param, int &recordCount) {
	for (int i = 0; i < dataBase.size(); i++) {
		string condition;
		if (op2 == "-f") {
			condition = dataBase[i].firstName;
		}
		else if (op2 == "-l") {
			condition = dataBase[i].lastName;
		}
		else {
			condition = dataBase[i].lastName + " " + dataBase[i].firstName;
		}

		delFromDataBase(condition, param, recordCount, i);
	}
}

void delClColumn(std::string& param, int& recordCount) {
	for (int i = 0; i < dataBase.size(); i++) {
		string condition = dataBase[i].cl;

		delFromDataBase(condition, param, recordCount, i);
	}
}

void delPhoneNumColumn(std::string& op2, std::string& param, int& recordCount) {
	for (int i = 0; i < dataBase.size(); i++) {
		string condition;
		if (op2 == "-m") {
			condition = dataBase[i].middleOfPhoneNum;
		}
		else if (op2 == "-l") {
			condition = dataBase[i].backOfPhoneNum;
		}
		else {
			condition = "010-" + dataBase[i].middleOfPhoneNum + "-" + dataBase[i].backOfPhoneNum;
		}

		delFromDataBase(condition, param, recordCount, i);
	}
}

void delBirthDayColumn(std::string& op2, std::string& param, int& recordCount) {
	for (int i = 0; i < dataBase.size(); i++) {
		string condition;
		if (op2 == "-y") {
			condition = dataBase[i].yearOfBday;
		}
		else if (op2 == "-m") {
			condition = dataBase[i].monthOfBday;
		}
		else if (op2 == "-d") {
			condition = dataBase[i].dateOfBday;
		}
		else {
			condition = dataBase[i].yearOfBday + dataBase[i].monthOfBday + dataBase[i].dateOfBday;
		}

		delFromDataBase(condition, param, recordCount, i);
	}
}

void delEmployeeColumn(std::string& param, int& recordCount) {
	for (int i = 0; i < dataBase.size(); i++) {
		string condition = dataBase[i].employeeNum;

		delFromDataBase(condition, param, recordCount, i);
	}
}

void delCertiColumn(std::string& param, int& recordCount) {
	for (int i = 0; i < dataBase.size(); i++) {
		string condition = dataBase[i].certi;

		delFromDataBase(condition, param, recordCount, i);
	}
}

std::string del(std::string op1, std::string op2, std::string column, std::string param) {
	std::string result = "0";
	int recordCount = 0;

	if (column == "name") {
		delNameColumn(op2, param, recordCount);
	}
	else if (column == "cl") {
		delClColumn(param, recordCount);
	}
	else if (column == "phoneNum") {
		delPhoneNumColumn(op2, param, recordCount);
	}
	else if (column == "birthDay") {
		delBirthDayColumn(op2, param, recordCount);
	}
	else if (column == "employeeNum") {
		delEmployeeColumn(param, recordCount);
	}
	else if (column == "certi") {
		delCertiColumn(param, recordCount);
	}
	else {
		throw invalid_argument("Invalid Column Name");
	}

	if (recordCount == 0) {
		result = "DEL,NONE";
	}
	else {
		if (op1 == "-p") {
			// TODO
		}
		else {
			result = "DEL," + to_string(recordCount);
		}

	}

	return result;
}