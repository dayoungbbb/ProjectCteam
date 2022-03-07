#pragma once
#include "Employee.h"
#include "define.h"
#include <queue>


class Searcher {
public:
    Searcher(vector<Employee>* pDataBase) : pDataBase_(pDataBase) {}
    virtual ~Searcher() {}
    virtual prioirtyQ search(const CmdString& cmdString) const = 0;

protected:
    vector<Employee>* pDataBase_;
};

class EmployeeNumSearcher : public Searcher {
public:
    EmployeeNumSearcher(vector<Employee>* pDataBase) : Searcher(pDataBase) {}
    ~EmployeeNumSearcher() {}

private:
    virtual prioirtyQ search(const CmdString& cmdString) const override;
};

class NameNumSearcher : public Searcher {
public:
    NameNumSearcher(vector<Employee>* pDataBase) : Searcher(pDataBase) {}
    ~NameNumSearcher() {}

private:
    virtual prioirtyQ search(const CmdString& cmdString) const override;
    string getInfo(const struct Name name, const string option) const;
};

class ClSearcher : public Searcher {
public:
    ClSearcher(vector<Employee>* pDataBase) : Searcher(pDataBase) {}
    ~ClSearcher() {}

private:
    virtual prioirtyQ search(const CmdString& cmdString) const override;
};

class PhoneNumSearcher : public Searcher {
public:
    PhoneNumSearcher(vector<Employee>* pDataBase) : Searcher(pDataBase) {}
    ~PhoneNumSearcher() {}

private:
    virtual prioirtyQ search(const CmdString& cmdString) const override;
    string getInfo(const struct PhoneNum phoneNum, const string option) const;
};

class BirthdaySearcher : public Searcher {
public:
    BirthdaySearcher(vector<Employee>* pDataBase) : Searcher(pDataBase) {}
    ~BirthdaySearcher() {}

private:
    virtual prioirtyQ search(const CmdString& cmdString) const override;
    string getInfo(const struct Bday bday, const string option) const;
};

class CertiSearcher : public Searcher {
public:
    CertiSearcher(vector<Employee>* pDataBase) : Searcher(pDataBase) {}
    ~CertiSearcher() {}

private:
    virtual prioirtyQ search(const CmdString& cmdString) const override;
};

class SearcherManager {
public:
    SearcherManager(vector<Employee>* pDataBase) {
        searcher_[EMPLOYEENUM] = new EmployeeNumSearcher(pDataBase);
        searcher_[NAME] = new NameNumSearcher(pDataBase);
        searcher_[CL] = new ClSearcher(pDataBase);
        searcher_[PHONENUM] = new PhoneNumSearcher(pDataBase);
        searcher_[BIRTHDAY] = new BirthdaySearcher(pDataBase);
        searcher_[CERTI] = new CertiSearcher(pDataBase);
    }
    ~SearcherManager() {
        for (auto& op : searcher_) {
            delete op;
            op = nullptr;
        }
    }

    Searcher* getSearcher(const CmdString& cmdString) const ;

private:
    Searcher* searcher_[MAX_COLUMNTYPE];
};
