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
};

class BirthdaySearcher : public Searcher {
public:
    BirthdaySearcher(vector<Employee>* pDataBase) : Searcher(pDataBase) {}
    ~BirthdaySearcher() {}
private:
    virtual prioirtyQ search(const CmdString& cmdString) const override;
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
