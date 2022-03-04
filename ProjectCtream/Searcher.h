#pragma once
#include "Employee.h"
#include "define.h"
#include <queue>
string addStr(string str) {
    string ret = "";
    if (stoi(str.substr(0, 1)) <= 2)
        return ret = "20" + str;
    else if (stoi(str.substr(0, 1)) >= 6)
        return ret = "19" + str;
    else
        return ret;
}
struct cmp {
    bool operator()(employeeIter a, employeeIter b) {
        string aStr = addStr(a->employeeNum);
        string bStr = addStr(b->employeeNum);
        return stoi(aStr) > stoi(bStr);
    }
};

class Searcher {
public:
    Searcher(vector<Employee>* pDataBase) : pDataBase_(pDataBase) {}
    virtual ~Searcher() {}
    virtual priority_queue<employeeIter, vector<employeeIter>, cmp> search(const CmdString& cmdString) const = 0;

protected:
    vector<Employee>* pDataBase_;
};

class EmployeeNumSearcher : public Searcher {
public:
    EmployeeNumSearcher(vector<Employee>* pDataBase) : Searcher(pDataBase) {}
    ~EmployeeNumSearcher() {}
private:
    virtual priority_queue<employeeIter, vector<employeeIter>, cmp> search(const CmdString& cmdString) const override;
};

class NameNumSearcher : public Searcher {
public:
    NameNumSearcher(vector<Employee>* pDataBase) : Searcher(pDataBase) {}
    ~NameNumSearcher() {}
private:
    virtual priority_queue<employeeIter, vector<employeeIter>, cmp> search(const CmdString& cmdString) const override;
};

class ClSearcher : public Searcher {
public:
    ClSearcher(vector<Employee>* pDataBase) : Searcher(pDataBase) {}
    ~ClSearcher() {}
private:
    virtual priority_queue<employeeIter, vector<employeeIter>, cmp> search(const CmdString& cmdString) const override;
};

class PhoneNumSearcher : public Searcher {
public:
    PhoneNumSearcher(vector<Employee>* pDataBase) : Searcher(pDataBase) {}
    ~PhoneNumSearcher() {}
private:
    virtual priority_queue<employeeIter, vector<employeeIter>, cmp> search(const CmdString& cmdString) const override;
};

class BirthdaySearcher : public Searcher {
public:
    BirthdaySearcher(vector<Employee>* pDataBase) : Searcher(pDataBase) {}
    ~BirthdaySearcher() {}
private:
    virtual priority_queue<employeeIter, vector<employeeIter>, cmp> search(const CmdString& cmdString) const override;
};

class CertiSearcher : public Searcher {
public:
    CertiSearcher(vector<Employee>* pDataBase) : Searcher(pDataBase) {}
    ~CertiSearcher() {}
private:

    virtual priority_queue<employeeIter, vector<employeeIter>, cmp> search(const CmdString& cmdString) const override;
};


class SearcherManager {
public:
    SearcherManager(vector<Employee>* pDataBase) {
        
        pEmployeeNumSearcher_ = new EmployeeNumSearcher(pDataBase);
        pNameNumSearcher_ = new NameNumSearcher(pDataBase);
        pClSearcher_ = new ClSearcher(pDataBase);
        pPhoneNumSearcher_ = new PhoneNumSearcher(pDataBase);
        pBirthdaySearcher_ = new BirthdaySearcher(pDataBase);
        pCertiSearcher_ = new CertiSearcher(pDataBase);

    }
    ~SearcherManager() {
		
		if (pEmployeeNumSearcher_) delete pEmployeeNumSearcher_;
		if (pNameNumSearcher_) delete pNameNumSearcher_;
        if (pClSearcher_) delete pClSearcher_;
        if (pPhoneNumSearcher_) delete pPhoneNumSearcher_;
        if (pBirthdaySearcher_) delete pBirthdaySearcher_;
        if (pCertiSearcher_) delete pCertiSearcher_;
    }

    Searcher* getSearcher(const CmdString& cmdString) const ;

private:
    Searcher* pEmployeeNumSearcher_;
    Searcher* pNameNumSearcher_;
    Searcher* pClSearcher_;
    Searcher* pPhoneNumSearcher_;
    Searcher* pBirthdaySearcher_;
    Searcher* pCertiSearcher_;
};
