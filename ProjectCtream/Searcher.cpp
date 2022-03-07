#include "Searcher.h"
prioirtyQ EmployeeNumSearcher::search(const CmdString& cmdString) const
{
    prioirtyQ searchResult;

    for (employeeIter iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
        if ((*iter).employeeNum == cmdString.col2) {
            searchResult.emplace(iter);
        }
    }

    return searchResult;
}

prioirtyQ NameNumSearcher::search(const CmdString& cmdString) const
{
    prioirtyQ searchResult;

    for (employeeIter iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
        if (cmdString.col2 == getInfo((*iter).name, cmdString.op2)) {
            searchResult.emplace(iter);
        }
    }

    return searchResult;
}

string NameNumSearcher::getInfo(const Name name, const string option) const
{
    if (option == "-f") {
        return name.firstName;
    }
    else if (option == "-l")
    {
        return name.lastName;
    }
    return name.firstName + " " + name.lastName;
}

prioirtyQ ClSearcher::search(const CmdString& cmdString) const
{
    prioirtyQ searchResult;

    for (employeeIter iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
        if ((*iter).cl == cmdString.col2) {
            searchResult.emplace(iter);
        }
    }

    return searchResult;
}

prioirtyQ PhoneNumSearcher::search(const CmdString& cmdString) const
{
    prioirtyQ searchResult;

    for (employeeIter iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
        if (cmdString.col2 == getInfo((*iter).phoneNum, cmdString.op2)) {
            searchResult.emplace(iter);
        }
    }

    return searchResult;
}

string PhoneNumSearcher::getInfo(const PhoneNum phoneNum, const string option) const
{
    if (option == "-m") {
        return phoneNum.middle;
    }
    else if (option == "-l")
    {
        return phoneNum.last;
    }
    return "010-" + phoneNum.middle + "-" + phoneNum.last;
}

prioirtyQ BirthdaySearcher::search(const CmdString& cmdString) const
{
    prioirtyQ searchResult;

    for (employeeIter iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
        if (cmdString.col2 == getInfo((*iter).bday, cmdString.op2)) {
            searchResult.emplace(iter);
        }
    }

    return searchResult;
}

string BirthdaySearcher::getInfo(const Bday bday, const string option) const
{
    if (option == "-y") {
        return bday.year;
    }
    else if (option == "-m")
    {
        return bday.month;
    }
    else if (option == "-d") {
        return bday.day;
    }
    return bday.year + bday.month + bday.day;
}

prioirtyQ CertiSearcher::search(const CmdString& cmdString) const
{
    prioirtyQ searchResult;

    for (employeeIter iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
        if ((*iter).certi == cmdString.col2) {
            searchResult.emplace(iter);
        }
    }

    return searchResult;
}
Searcher* SearcherManager::getSearcher(const CmdString& cmdString) const
{

    if (cmdString.col1 == "employeeNum") {
        return searcher_[EMPLOYEENUM];
    }
    else if (cmdString.col1 == "name") {
        return searcher_[NAME];
    }
    else if (cmdString.col1 == "cl") {
        return searcher_[CL];
    }
    else if (cmdString.col1 == "phoneNum") {
        return searcher_[PHONENUM];
    }
    else if (cmdString.col1 == "birthday") {
        return searcher_[BIRTHDAY];
    }
    else if (cmdString.col1 == "certi") {
        return searcher_[CERTI];
    }
    return nullptr;
}
