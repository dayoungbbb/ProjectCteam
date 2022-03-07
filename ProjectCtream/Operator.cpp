#include "Operator.h"

void AddOperator::operate(vector<string>& searchQ, CmdString& cmdString)
{
    Employee employee;
    employee.employeeNum = cmdString.col1;
    parseName(cmdString.col2, employee.name.firstName, employee.name.lastName);
    employee.cl = cmdString.col3;
    parsePhoneNum(cmdString.col4, employee.phoneNum.middle, employee.phoneNum.last);
    parseBirthday(cmdString.col5, employee.bday.year, employee.bday.month, employee.bday.day);
    employee.certi = cmdString.col6;

    addColumnMap(employee);
}

void Operator::addColumnMap(Employee& employee)
{
    dataBase->insert(make_pair(employee.employeeNum, employee));
    (*columnMap)[NAME].insert(make_pair(employee.name.firstName + " " + employee.name.lastName, employee.employeeNum));
    (*columnMap)[CL].insert(make_pair(employee.cl, employee.employeeNum));
    (*columnMap)[PHONENUM].insert(make_pair("010-" + employee.phoneNum.middle + "-" + employee.phoneNum.last, employee.employeeNum));
    (*columnMap)[BIRTHDAY].insert(make_pair(employee.bday.year + employee.bday.month + employee.bday.day, employee.employeeNum));
    (*columnMap)[CERTI].insert(make_pair(employee.certi, employee.employeeNum));
    (*columnMap)[NAME_FIRST].insert(make_pair(employee.name.firstName, employee.employeeNum));
    (*columnMap)[NAME_LAST].insert(make_pair(employee.name.lastName, employee.employeeNum));
    (*columnMap)[PHONENUM_MIDDLE].insert(make_pair(employee.phoneNum.middle, employee.employeeNum));
    (*columnMap)[PHONENUM_BACK].insert(make_pair(employee.phoneNum.last, employee.employeeNum));
    (*columnMap)[BIRTHDAY_YEAR].insert(make_pair(employee.bday.year, employee.employeeNum));
    (*columnMap)[BIRTHDAY_MONTH].insert(make_pair(employee.bday.month, employee.employeeNum));
    (*columnMap)[BIRTHDAY_DATE].insert(make_pair(employee.bday.day, employee.employeeNum));
}

void Operator::delColumnMap(Employee& employee)
{
    delColumnMap(NAME, employee, employee.name.firstName + " " + employee.name.lastName);
    delColumnMap(CL, employee, employee.cl);
    delColumnMap(PHONENUM, employee, "010-" + employee.phoneNum.middle + "-" + employee.phoneNum.last);
    delColumnMap(BIRTHDAY, employee, employee.bday.year + employee.bday.month + employee.bday.day);
    delColumnMap(CERTI, employee, employee.certi);
    delColumnMap(NAME_FIRST, employee, employee.name.firstName);
    delColumnMap(NAME_LAST, employee, employee.name.lastName);
    delColumnMap(PHONENUM_MIDDLE, employee, employee.phoneNum.middle);
    delColumnMap(PHONENUM_BACK, employee, employee.phoneNum.last);
    delColumnMap(BIRTHDAY_YEAR, employee, employee.bday.year);
    delColumnMap(BIRTHDAY_MONTH, employee, employee.bday.month);
    delColumnMap(BIRTHDAY_DATE, employee, employee.bday.day);

    auto iter = dataBase->find(employee.employeeNum);
    dataBase->erase(iter);
}

void Operator::delColumnMap(EColumn eColumn, Employee& employee, string key)
{
    for (auto it = (*columnMap)[eColumn].lower_bound(key); it != (*columnMap)[eColumn].upper_bound(key); it++) {
        if (it->second == employee.employeeNum) {
            (*columnMap)[eColumn].erase(it);
            break;
        }
    }
}

void ModOperator::operate(vector<string>& searchQ, CmdString& cmdString)
{
    for (auto employeeNum : searchQ) {
        if (cmdString.col3 == "employeeNum") {
            throw invalid_argument("�����ȣ�� �ٲ� �� �����ϴ�");
        }

        Employee employee = (*dataBase)[employeeNum];
        delColumnMap(employee);

        if (cmdString.col3 == "name") {
            parseName(cmdString.col4, employee.name.firstName, employee.name.lastName);
        }
        else if (cmdString.col3 == "cl") {
            employee.cl = cmdString.col4;
        }
        else if (cmdString.col3 == "phoneNum") {
            parsePhoneNum(cmdString.col4, employee.phoneNum.middle, employee.phoneNum.last);
        }
        else if (cmdString.col3 == "birthday") {
            parseBirthday(cmdString.col4, employee.bday.year, employee.bday.month, employee.bday.day);
        }
        else if (cmdString.col3 == "certi") {
            employee.certi = cmdString.col4;
        }
        else {
            throw invalid_argument("Column �̸� Ȯ�����ּ���");
        }

        addColumnMap(employee);
    }
}

void DelOperator::operate(vector<string>& searchQ, CmdString& cmdString)
{
    for (auto employeeNum : searchQ) {
        Employee employee = (*dataBase)[employeeNum];

        delColumnMap(employee);
    }
}