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

    if (cmdString.op2 == "-f") {
        for (employeeIter iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
            if ((*iter).name.firstName == cmdString.col2) {
                searchResult.emplace(iter);
            }
        }
    }
    else if (cmdString.op2 == "-l")
    {
        for (employeeIter iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
            if ((*iter).name.lastName == cmdString.col2) {
                searchResult.emplace(iter);
            }
        }
    }
    else {
        for (employeeIter iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
            if (((*iter).name.firstName + " " + (*iter).name.lastName )== cmdString.col2) {
                searchResult.emplace(iter);
            }
        }
    }
    return searchResult;

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

    if (cmdString.op2 == "-m") {
        for (employeeIter iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
            if ((*iter).phoneNum.middle == cmdString.col2) {
                searchResult.emplace(iter);
            }
        }
    }
    else if (cmdString.op2 == "-l")
    {
        for (employeeIter iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
            if ((*iter).phoneNum.last == cmdString.col2) {
                searchResult.emplace(iter);
            }
        }
    }
    else {
        for (employeeIter iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
            if ( ("010-"+ (*iter).phoneNum.middle + "-" + (*iter).phoneNum.last) == cmdString.col2) {
                searchResult.emplace(iter);
            }
        }
    }
    return searchResult;
}

prioirtyQ BirthdaySearcher::search(const CmdString& cmdString) const
{
    prioirtyQ searchResult;

    if (cmdString.op2 == "-y") {
        for (employeeIter iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
            if ((*iter).bday.year == cmdString.col2) {
                searchResult.emplace(iter);
            }
        }
    }
    else if (cmdString.op2 == "-m")
    {
        for (employeeIter iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
            if ((*iter).bday.month == cmdString.col2) {
                searchResult.emplace(iter);
            }
        }
    }
    else if (cmdString.op2 == "-d")
    {
        for (employeeIter iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
            if ((*iter).bday.day == cmdString.col2) {
                searchResult.emplace(iter);
            }
        }
    }
    else {
        for (employeeIter iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
            if ( ((*iter).bday.year + (*iter).bday.month + (*iter).bday.day) == cmdString.col2) {
                searchResult.emplace(iter);
            }
        }
    }
    return searchResult;
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
        return pEmployeeNumSearcher_;
    }
    else if (cmdString.col1 == "name") {
        return pNameNumSearcher_;
    }
    else if (cmdString.col1 == "cl") {
        return pClSearcher_;
    }
    else if (cmdString.col1 == "phoneNum") {
        return pPhoneNumSearcher_;
    }
    else if (cmdString.col1 == "birthday") {
        return pBirthdaySearcher_;
    }
    else if (cmdString.col1 == "certi") {
        return pCertiSearcher_;;
    }
    return nullptr;
}
