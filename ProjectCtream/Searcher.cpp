#include "Searcher.h"
prioirtyQ EmployeeNumSearcher::search(const void* cmdString) const
{
    prioirtyQ searchResult;
    SchCmd* schCmd = (SchCmd*)cmdString;
    for (employeeIter iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
        if ((*iter).employeeNum == schCmd->cond) {
            searchResult.emplace(iter);
        }
    }

    return searchResult;
}

prioirtyQ NameNumSearcher::search(const void* cmdString) const
{
    prioirtyQ searchResult;
    SchCmd* schCmd = (SchCmd*)cmdString;
    for (employeeIter iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
        if (schCmd->cond == getInfo((*iter).name, schCmd->secondOptionType)) {
            searchResult.emplace(iter);
        }
    }

    return searchResult;
}

string NameNumSearcher::getInfo(const Name name, const int option) const
{
    if (option == FIRST_NAME) {
        return name.firstName;
    }
    else if (option == LAST_NAME)
    {
        return name.lastName;
    }
    return name.firstName + " " + name.lastName;
}

prioirtyQ ClSearcher::search(const void* cmdString) const
{
    prioirtyQ searchResult;
    SchCmd* schCmd = (SchCmd*)cmdString;
    for (employeeIter iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
        if ((*iter).cl == schCmd->cond) {
            searchResult.emplace(iter);
        }
    }

    return searchResult;
}

prioirtyQ PhoneNumSearcher::search(const void* cmdString) const
{
    prioirtyQ searchResult;
    SchCmd* schCmd = (SchCmd*)cmdString;
    for (employeeIter iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
        if (schCmd->cond == getInfo((*iter).phoneNum, schCmd->secondOptionType)) {
            searchResult.emplace(iter);
        }
    }

    return searchResult;
}

string PhoneNumSearcher::getInfo(const PhoneNum phoneNum, const int option) const
{
    if (option == MIDDLE_NUM) {
        return phoneNum.middle;
    }
    else if (option == LAST_NUM)
    {
        return phoneNum.last;
    }
    return "010-" + phoneNum.middle + "-" + phoneNum.last;
}

prioirtyQ BirthdaySearcher::search(const void* cmdString) const
{
    prioirtyQ searchResult;
    SchCmd* schCmd = (SchCmd*)cmdString;
    for (employeeIter iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
        if (schCmd->cond == getInfo((*iter).bday, schCmd->secondOptionType)) {
            searchResult.emplace(iter);
        }
    }

    return searchResult;
}

string BirthdaySearcher::getInfo(const Bday bday, const int option) const
{
    if (option == YEAR) {
        return bday.year;
    }
    else if (option == MONTH)
    {
        return bday.month;
    }
    else if (option == DAY) {
        return bday.day;
    }
    return bday.year + bday.month + bday.day;
}

prioirtyQ CertiSearcher::search(const void* cmdString) const
{
    prioirtyQ searchResult;
    SchCmd* schCmd = (SchCmd*)cmdString;
    for (employeeIter iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
        if ((*iter).certi == schCmd->cond) {
            searchResult.emplace(iter);
        }
    }

    return searchResult;
}
Searcher* SearcherManager::getSearcher(const void* cmdString) const
{
    SchCmd* schCmd = (SchCmd*)cmdString;
    if (schCmd->condType == EMPLOYEENUM) {
        return searcher_[EMPLOYEENUM];
    }
    else if (schCmd->condType == NAME) {
        return searcher_[NAME];
    }
    else if (schCmd->condType == CL) {
        return searcher_[CL];
    }
    else if (schCmd->condType == PHONENUM) {
        return searcher_[PHONENUM];
    }
    else if (schCmd->condType == BIRTHDAY) {
        return searcher_[BIRTHDAY];
    }
    else if (schCmd->condType == CERTI) {
        return searcher_[CERTI];
    }
    return nullptr;
}
