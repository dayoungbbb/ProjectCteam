#include "Searcher.h"
#include "define.h"
priority_queue<employeeIter, vector<employeeIter>, cmp> EmployeeNumSearcher::search(const CmdString& cmdString) const
{
    priority_queue<employeeIter, vector<employeeIter>, cmp> searchResult;

    for (vector<Employee>::iterator iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
        if ((*iter).employeeNum == cmdString.col2) {
            searchResult.push(iter);
        }
    }

    return searchResult;
}

priority_queue<employeeIter, vector<employeeIter>, cmp> NameNumSearcher::search(const CmdString& cmdString) const
{
    priority_queue<employeeIter, vector<employeeIter>, cmp> searchResult;

    if (cmdString.op2 == "f") {
        for (vector<Employee>::iterator iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
            if ((*iter).firstName == cmdString.col2) {
                searchResult.push(iter);
            }
        }
    }
    else if (cmdString.op2 == "l")
    {
        for (vector<Employee>::iterator iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
            if ((*iter).lastName == cmdString.col2) {
                searchResult.push(iter);
            }
        }
    }
    else {
        for (vector<Employee>::iterator iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
            if (((*iter).firstName + " " + (*iter).lastName )== cmdString.col2) {
                searchResult.push(iter);
            }
        }
    }
    return searchResult;

}

priority_queue<employeeIter, vector<employeeIter>, cmp> ClSearcher::search(const CmdString& cmdString) const
{
    priority_queue<employeeIter, vector<employeeIter>, cmp> searchResult;

    for (vector<Employee>::iterator iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
        if ((*iter).cl == cmdString.col2) {
            searchResult.push(iter);
        }
    }

    return searchResult;
}

priority_queue<employeeIter, vector<employeeIter>, cmp> PhoneNumSearcher::search(const CmdString& cmdString) const
{
    priority_queue<employeeIter, vector<employeeIter>, cmp> searchResult;

    if (cmdString.op2 == "m") {
        for (vector<Employee>::iterator iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
            if ((*iter).middleOfPhoneNum == cmdString.col2) {
                searchResult.push(iter);
            }
        }
    }
    else if (cmdString.op2 == "l")
    {
        for (vector<Employee>::iterator iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
            if ((*iter).backOfPhoneNum == cmdString.col2) {
                searchResult.push(iter);
            }
        }
    }
    else {
        for (vector<Employee>::iterator iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
            if ( ("010-"+ (*iter).middleOfPhoneNum + "-" + (*iter).backOfPhoneNum) == cmdString.col2) {
                searchResult.push(iter);
            }
        }
    }
    return searchResult;
}

priority_queue<employeeIter, vector<employeeIter>, cmp> BirthdaySearcher::search(const CmdString& cmdString) const
{
    priority_queue<employeeIter, vector<employeeIter>, cmp> searchResult;

    if (cmdString.op2 == "y") {
        for (vector<Employee>::iterator iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
            if ((*iter).yearOfBday == cmdString.col2) {
                searchResult.push(iter);
            }
        }
    }
    else if (cmdString.op2 == "m")
    {
        for (vector<Employee>::iterator iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
            if ((*iter).monthOfBday == cmdString.col2) {
                searchResult.push(iter);
            }
        }
    }
    else if (cmdString.op2 == "d")
    {
        for (vector<Employee>::iterator iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
            if ((*iter).dateOfBday == cmdString.col2) {
                searchResult.push(iter);
            }
        }
    }
    else {
        for (vector<Employee>::iterator iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
            if ( ((*iter).yearOfBday + (*iter).monthOfBday + (*iter).dateOfBday) == cmdString.col2) {
                searchResult.push(iter);
            }
        }
    }
    return searchResult;
}

priority_queue<employeeIter, vector<employeeIter>, cmp> CertiSearcher::search(const CmdString& cmdString) const
{
    priority_queue<employeeIter, vector<employeeIter>, cmp> searchResult;

    for (vector<Employee>::iterator iter = pDataBase_->begin(); iter != pDataBase_->end(); iter++) {
        if ((*iter).certi == cmdString.col2) {
            searchResult.push(iter);
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
