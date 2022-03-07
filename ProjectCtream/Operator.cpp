#include "Operator.h"

void AddOperator::operate(prioirtyQ& searchQ, CmdString& cmdString)
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

void ModOperator::operate(prioirtyQ& searchQ, CmdString& cmdString)
{
    while (!searchQ.empty()) {
        list<Employee>::iterator iter = searchQ.top();

        if (cmdString.col3 == "employeeNum") {
            throw invalid_argument("�����ȣ�� �ٲ� �� �����ϴ�");
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
            throw invalid_argument("Column �̸� Ȯ�����ּ���");
        }

        searchQ.pop();
    }
}

void DelOperator::operate(prioirtyQ& searchQ, CmdString& cmdString)
{
    while (!searchQ.empty()) {
        list<Employee>::iterator iter = searchQ.top();

        dataBase->erase(iter);

        searchQ.pop();
    }
}