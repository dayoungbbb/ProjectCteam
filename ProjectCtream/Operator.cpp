#include "Operator.h"

void AddOperator::operate(unordered_set<string>& searchQ, void* cmdString)
{
    Employee* employee = (Employee*)cmdString;

    addColumnMap(*employee);
}

void Operator::addColumnMap(Employee& employee)
{
    dataBase->insert(make_pair(employee.employeeNum, employee));

    (*columnMap)[EMPLOYEENUM][employee.employeeNum].insert(employee.employeeNum);
    (*columnMap)[NAME][employee.name.firstName + " " + employee.name.lastName].insert(employee.employeeNum);
    (*columnMap)[CL][employee.cl].insert(employee.employeeNum);
    (*columnMap)[PHONENUM]["010-" + employee.phoneNum.middle + "-" + employee.phoneNum.last].insert(employee.employeeNum);
    (*columnMap)[BIRTHDAY][employee.bday.year + employee.bday.month + employee.bday.day].insert(employee.employeeNum);
    (*columnMap)[CERTI][employee.certi].insert(employee.employeeNum);
    (*columnMap)[NAME_FIRST][employee.name.firstName].insert(employee.employeeNum);
    (*columnMap)[NAME_LAST][employee.name.lastName].insert(employee.employeeNum);
    (*columnMap)[PHONENUM_MIDDLE][employee.phoneNum.middle].insert(employee.employeeNum);
    (*columnMap)[PHONENUM_BACK][employee.phoneNum.last].insert(employee.employeeNum);
    (*columnMap)[BIRTHDAY_YEAR][employee.bday.year].insert(employee.employeeNum);
    (*columnMap)[BIRTHDAY_MONTH][employee.bday.month].insert(employee.employeeNum);
    (*columnMap)[BIRTHDAY_DATE][employee.bday.day].insert(employee.employeeNum);
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
    auto iter = (*columnMap)[eColumn].find(key);
    auto findIter = iter->second.find(employee.employeeNum);

    if (findIter == iter->second.end())
    {
        throw invalid_argument("발생하면 안되는 케이스입니다");
    }

    iter->second.erase(findIter);
}

void ModOperator::operate(unordered_set<string>& searchQ, void* cmdString)
{
    ModCmd* modCmd = (ModCmd*)cmdString;
    for (auto employeeNum : searchQ) {
        if (modCmd->condType == EMPLOYEENUM) {
            throw invalid_argument("사원번호는 바꿀 수 없습니다");
        }

        Employee employee = (*dataBase)[employeeNum];
        delColumnMap(employee);

        if (modCmd->condType == NAME) {
            vector<string> parseStr = split(modCmd->cond, ' ');
            employee.name.firstName = parseStr[0];
            employee.name.lastName = parseStr[1];
        }
        else if (modCmd->condType == CL) {
            employee.cl = modCmd->cond;
        }
        else if (modCmd->condType == PHONENUM) {
            vector<string> parseStr = split(modCmd->cond, '-');
            employee.phoneNum.middle = parseStr[1];
            employee.phoneNum.last = parseStr[2];
        }
        else if (modCmd->condType == BIRTHDAY) {
            employee.bday.year = modCmd->cond.substr(0, 4);
            employee.bday.month = modCmd->cond.substr(4, 2);
            employee.bday.day = modCmd->cond.substr(6, 2);
        }
        else if (modCmd->condType == CERTI) {
            employee.certi = modCmd->cond;
        }
        else {
            throw invalid_argument("Column 이름 확인해주세요");
        }

        addColumnMap(employee);
    }
}

vector<string> ModOperator::split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

void DelOperator::operate(unordered_set<string>& searchQ, void* cmdString)
{
    for (auto employeeNum : searchQ) {
        Employee employee = (*dataBase)[employeeNum];

        delColumnMap(employee);
    }
}