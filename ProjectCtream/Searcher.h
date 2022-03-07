#pragma once
#include "Employee.h"
#include "define.h"
#include <queue>


class Searcher {
public:
    Searcher(list<Employee>* pDataBase) : pDataBase_(pDataBase) {}
    virtual ~Searcher() {}
    virtual prioirtyQ search(void* cmdString) const = 0;

protected:
    list<Employee>* pDataBase_;
};

class EmployeeNumSearcher : public Searcher {
public:
    EmployeeNumSearcher(list<Employee>* pDataBase) : Searcher(pDataBase) {}
    ~EmployeeNumSearcher() {}
private:
    virtual prioirtyQ search(void* cmdString) const override;
};

class NameNumSearcher : public Searcher {
public:
    NameNumSearcher(list<Employee>* pDataBase) : Searcher(pDataBase) {}
    ~NameNumSearcher() {}
private:
    virtual prioirtyQ search(void* cmdString) const override;
    string getInfo(const Name name, const int option) const;
};

class ClSearcher : public Searcher {
public:
    ClSearcher(list<Employee>* pDataBase) : Searcher(pDataBase) {}
    ~ClSearcher() {}
private:
    virtual prioirtyQ search(void* cmdString) const override;
};

class PhoneNumSearcher : public Searcher {
public:
    PhoneNumSearcher(list<Employee>* pDataBase) : Searcher(pDataBase) {}
    ~PhoneNumSearcher() {}
private:
    virtual prioirtyQ search(void* cmdString) const override;
    string getInfo(const PhoneNum phoneNum, const int option) const;

};

class BirthdaySearcher : public Searcher {
public:
    BirthdaySearcher(list<Employee>* pDataBase) : Searcher(pDataBase) {}
    ~BirthdaySearcher() {}
private:
    virtual prioirtyQ search(void* cmdString) const override;
    string getInfo(const Bday bday, const int option) const;

};

class CertiSearcher : public Searcher {
public:
    CertiSearcher(list<Employee>* pDataBase) : Searcher(pDataBase) {}
    ~CertiSearcher() {}
private:

    virtual prioirtyQ search(void* cmdString) const override;
};


class SearcherManager {
public:
    SearcherManager(list<Employee>* pDataBase) {
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

    Searcher* getSearcher(void* cmdString) const;

private:
    Searcher* searcher_[MAX_COLUMNTYPE];

};
