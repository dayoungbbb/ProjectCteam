#include "Searcher.h"
vector<string> EmployeeNumSearcher::search(const CmdString& cmdString) const
{
    vector<string> searchResult;

    string key = cmdString.col2;
    if ((*pDataBase_).count(key)) {
        searchResult.emplace_back(key);
    }

    return searchResult;
}

vector<string> NameNumSearcher::search(const CmdString& cmdString) const
{
    vector<string> searchResult;
    string key = cmdString.col2;

    if (cmdString.op2 == "-f") {
        if ((*columeMap_)[NAME_FIRST].count(key)) {
            for (auto it = (*columeMap_)[NAME_FIRST].lower_bound(key); it != (*columeMap_)[NAME_FIRST].upper_bound(key); it++) {
                searchResult.emplace_back(it->second);
            }
        }
    }
    else if (cmdString.op2 == "-l")
    {
        if ((*columeMap_)[NAME_LAST].count(key)) {
            for (auto it = (*columeMap_)[NAME_LAST].lower_bound(key); it != (*columeMap_)[NAME_LAST].upper_bound(key); it++) {
                searchResult.emplace_back(it->second);
            }
        }
    }
    else {
        if ((*columeMap_)[NAME].count(key)) {
            for (auto it = (*columeMap_)[NAME].lower_bound(key); it != (*columeMap_)[NAME].upper_bound(key); it++) {
                searchResult.emplace_back(it->second);
            }
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

vector<string> ClSearcher::search(const CmdString& cmdString) const
{
    vector<string> searchResult;
    string key = cmdString.col2;
    if ((*columeMap_)[CL].count(key)) {
        for (auto it = (*columeMap_)[CL].lower_bound(key); it != (*columeMap_)[CL].upper_bound(key); it++) {
            searchResult.emplace_back(it->second);
        }
    }

    return searchResult;
}

vector<string> PhoneNumSearcher::search(const CmdString& cmdString) const
{
    vector<string> searchResult;

    string key = cmdString.col2;

    if (cmdString.op2 == "-m") {
        if ((*columeMap_)[PHONENUM_MIDDLE].count(key)) {
            for (auto it = (*columeMap_)[PHONENUM_MIDDLE].lower_bound(key); it != (*columeMap_)[PHONENUM_MIDDLE].upper_bound(key); it++) {
                searchResult.emplace_back(it->second);
            }
        }
    }
    else if (cmdString.op2 == "-l")
    {
        if ((*columeMap_)[PHONENUM_BACK].count(key)) {
            for (auto it = (*columeMap_)[PHONENUM_BACK].lower_bound(key); it != (*columeMap_)[PHONENUM_BACK].upper_bound(key); it++) {
                searchResult.emplace_back(it->second);
            }
        }
    }
    else {
        if ((*columeMap_)[PHONENUM].count(key)) {
            for (auto it = (*columeMap_)[PHONENUM].lower_bound(key); it != (*columeMap_)[PHONENUM].upper_bound(key); it++) {
                searchResult.emplace_back(it->second);
            }
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

vector<string> BirthdaySearcher::search(const CmdString& cmdString) const
{
    vector<string> searchResult;

    string key = cmdString.col2;

    if (cmdString.op2 == "-y") {
        if ((*columeMap_)[BIRTHDAY_YEAR].count(key)) {
            for (auto it = (*columeMap_)[BIRTHDAY_YEAR].lower_bound(key); it != (*columeMap_)[BIRTHDAY_YEAR].upper_bound(key); it++) {
                searchResult.emplace_back(it->second);
            }
        }
    }
    else if (cmdString.op2 == "-m")
    {
        if ((*columeMap_)[BIRTHDAY_MONTH].count(key)) {
            for (auto it = (*columeMap_)[BIRTHDAY_MONTH].lower_bound(key); it != (*columeMap_)[BIRTHDAY_MONTH].upper_bound(key); it++) {
                searchResult.emplace_back(it->second);
            }
        }
    }
    else if (cmdString.op2 == "-d")
    {
        if ((*columeMap_)[BIRTHDAY_DATE].count(key)) {
            for (auto it = (*columeMap_)[BIRTHDAY_DATE].lower_bound(key); it != (*columeMap_)[BIRTHDAY_DATE].upper_bound(key); it++) {
                searchResult.emplace_back(it->second);
            }
        }
    }
    else {
        if ((*columeMap_)[BIRTHDAY].count(key)) {
            for (auto it = (*columeMap_)[BIRTHDAY].lower_bound(key); it != (*columeMap_)[BIRTHDAY].upper_bound(key); it++) {
                searchResult.emplace_back(it->second);
            }
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

vector<string> CertiSearcher::search(const CmdString& cmdString) const
{
    vector<string> searchResult;

    string key = cmdString.col2;
    if ((*columeMap_)[CERTI].count(key)) {
        for (auto it = (*columeMap_)[CERTI].lower_bound(key); it != (*columeMap_)[CERTI].upper_bound(key); it++) {
            searchResult.emplace_back(it->second);
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
