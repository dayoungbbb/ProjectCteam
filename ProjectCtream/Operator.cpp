#include "Operator.h"

void AddOperator::operate(prioirtyQ& searchQ, CmdString& cmdString)
{
    Employee employee;
    employee.employeeNum = cmdString.col1;
    parseName(cmdString.col2, employee.name.firstName, employee.name.lastName);
    employee.cl = cmdString.col3;
    parsePhoneNum(cmdString.col4, employee.phoneNum.middle, employee.phoneNum.last);
    parseBirthday(cmdString.col5, employee.bday.year, employee.bday.month, employee.bday.day);
    employee.certi = cmdString.col6;
    dataBase->push_back(employee);
}

void ModOperator::operate(prioirtyQ& searchQ, CmdString& cmdString)
{
    while (!searchQ.empty()) {
        list<Employee>::iterator iter = searchQ.top();

        if (cmdString.col3 == "employeeNum") {
            throw invalid_argument("사원번호는 바꿀 수 없습니다");
        }
        else if (cmdString.col3 == "name") {
            parseName(cmdString.col4, iter->name.firstName, iter->name.lastName);
        }
        else if (cmdString.col3 == "cl") {
            iter->cl = cmdString.col4;
        }
        else if (cmdString.col3 == "phoneNum") {
            parsePhoneNum(cmdString.col4, iter->phoneNum.middle, iter->phoneNum.last);
        }
        else if (cmdString.col3 == "birthday") {
            parseBirthday(cmdString.col4, iter->bday.year, iter->bday.month, iter->bday.day);
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

void DelOperator::operate(prioirtyQ& searchQ, CmdString& cmdString)
{
    while (!searchQ.empty()) {
        list<Employee>::iterator iter = searchQ.top();

        dataBase->erase(iter);

        searchQ.pop();
    }
}