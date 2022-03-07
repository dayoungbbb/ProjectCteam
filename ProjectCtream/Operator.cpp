#include "Operator.h"

void AddOperator::operate(prioirtyQ& searchQ, void* cmdString)
{
    Employee* employee = reinterpret_cast<Employee*>(cmdString);
    dataBase->push_back(*employee);
}

void ModOperator::operate(prioirtyQ& searchQ, void* cmdString)
{
    while (!searchQ.empty()) {
        list<Employee>::iterator iter = searchQ.top();
        ModCmd* modCmd = reinterpret_cast<ModCmd*>(cmdString);
        if (modCmd->condType == EMPLOYEENUM) {
            throw invalid_argument("사원번호는 바꿀 수 없습니다");
        }
        else if (modCmd->condType == NAME) {
            parseName(modCmd->cond, iter->name.firstName, iter->name.lastName);
        }
        else if (modCmd->condType == CL) {
            iter->cl = modCmd->cond;
        }
        else if (modCmd->condType == PHONENUM) {
            parsePhoneNum(modCmd->cond, iter->phoneNum.middle, iter->phoneNum.last);
        }
        else if (modCmd->condType == BIRTHDAY) {
            parseBirthday(modCmd->cond, iter->bday.year, iter->bday.month, iter->bday.day);
        }
        else if (modCmd->condType == CERTI) {
            iter->certi = modCmd->cond;
        }
        else {
            throw invalid_argument("Column 이름 확인해주세요");
        }

        searchQ.pop();
    }
}

void DelOperator::operate(prioirtyQ& searchQ, void* cmdString)
{
    while (!searchQ.empty()) {
        list<Employee>::iterator iter = searchQ.top();

        dataBase->erase(iter);

        searchQ.pop();
    }
}