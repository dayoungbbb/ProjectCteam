#include "Operator.h"

void AddOperator::operate(priority_queue<vector<Employee>::iterator>& searchQ, CmdString& cmdString)
{
    Employee employee;
    employee.employeeNum = cmdString.col1;
    parseName(cmdString.col2, employee.firstName, employee.lastName);
    employee.cl = cmdString.col3;
    parsePhoneNum(cmdString.col4, employee.middleOfPhoneNum, employee.backOfPhoneNum);
    parseBirthday(cmdString.col5, employee.yearOfBday, employee.monthOfBday, employee.dateOfBday);
    employee.certi = cmdString.col6;
    dataBase->push_back(employee);
}

void ModOperator::operate(priority_queue<vector<Employee>::iterator>& searchQ, CmdString& cmdString)
{
    while (!searchQ.empty()) {
        vector<Employee>::iterator iter = searchQ.top();

        if (cmdString.col3 == "employeeNum") {
            iter->employeeNum = cmdString.col4;
        }
        else if (cmdString.col3 == "name") {
            parseName(cmdString.col4, iter->firstName, iter->lastName);
        }
        else if (cmdString.col3 == "cl") {
            iter->cl = cmdString.col4;
        }
        else if (cmdString.col3 == "phoneNum") {
            parsePhoneNum(cmdString.col4, iter->middleOfPhoneNum, iter->backOfPhoneNum);
        }
        else if (cmdString.col3 == "birthday") {
            parseBirthday(cmdString.col4, iter->yearOfBday, iter->monthOfBday, iter->dateOfBday);
        }
        else if (cmdString.col3 == "certi") {
            iter->certi = cmdString.col4;
        }
        else {
            throw invalid_argument("Column 이름 확인해주세요");
        }

        searchQ.pop();
    }
}

void DelOperator::operate(priority_queue<vector<Employee>::iterator>& searchQ, CmdString& cmdString)
{
    while (!searchQ.empty()) {
        vector<Employee>::iterator iter = searchQ.top();

        dataBase->erase(iter);

        searchQ.pop();
    }
}