#pragma once
#include "Employee.h"
#include "define.h"
#include <queue>


class Searcher {
public:
    Searcher(map<string, Employee>* pDataBase, vector<multimap<string, string>>* columeMap) : pDataBase_(pDataBase), columeMap_(columeMap) {}
    virtual ~Searcher() {}
    virtual vector<string> search(const CmdString& cmdString) const = 0;

protected:
    map<string, Employee>* pDataBase_;
    vector<multimap<string, string>>* columeMap_;
};

class EmployeeNumSearcher : public Searcher {
public:
    EmployeeNumSearcher(map<string, Employee>* pDataBase, vector<multimap<string, string>>* columeMap) : Searcher(pDataBase, columeMap) {}
    ~EmployeeNumSearcher() {}
private:
    virtual vector<string> search(const CmdString& cmdString) const override;
};

class NameNumSearcher : public Searcher {
public:
    NameNumSearcher(map<string, Employee>* pDataBase, vector<multimap<string, string>>* columeMap) : Searcher(pDataBase, columeMap) {}
    ~NameNumSearcher() {}
private:
    virtual vector<string> search(const CmdString& cmdString) const override;
    string getInfo(const Name name, const string option) const;
};

class ClSearcher : public Searcher {
public:
    ClSearcher(map<string, Employee>* pDataBase, vector<multimap<string, string>>* columeMap) : Searcher(pDataBase, columeMap) {}
    ~ClSearcher() {}
private:
    virtual vector<string> search(const CmdString& cmdString) const override;
};

class PhoneNumSearcher : public Searcher {
public:
    PhoneNumSearcher(map<string, Employee>* pDataBase, vector<multimap<string, string>>* columeMap) : Searcher(pDataBase, columeMap) {}
    ~PhoneNumSearcher() {}
private:
    virtual vector<string> search(const CmdString& cmdString) const override;
    string getInfo(const PhoneNum phoneNum, const string option) const;

};

class BirthdaySearcher : public Searcher {
public:
    BirthdaySearcher(map<string, Employee>* pDataBase, vector<multimap<string, string>>* columeMap) : Searcher(pDataBase, columeMap) {}
    ~BirthdaySearcher() {}
private:
    virtual vector<string> search(const CmdString& cmdString) const override;
    string getInfo(const Bday bday, const string option) const;

};

class CertiSearcher : public Searcher {
public:
    CertiSearcher(map<string, Employee>* pDataBase, vector<multimap<string, string>>* columeMap) : Searcher(pDataBase, columeMap) {}
    ~CertiSearcher() {}
private:

    virtual vector<string> search(const CmdString& cmdString) const override;
};


class SearcherManager {
public:
    SearcherManager(map<string, Employee>* pDataBase, vector<multimap<string, string>>* columeMap) {
        searcher_[EMPLOYEENUM] = new EmployeeNumSearcher(pDataBase, columeMap);
        searcher_[NAME] = new NameNumSearcher(pDataBase, columeMap);
        searcher_[CL] = new ClSearcher(pDataBase, columeMap);
        searcher_[PHONENUM] = new PhoneNumSearcher(pDataBase, columeMap);
        searcher_[BIRTHDAY] = new BirthdaySearcher(pDataBase, columeMap);
        searcher_[CERTI] = new CertiSearcher(pDataBase, columeMap);
    }
    ~SearcherManager() {
        for (auto& op : searcher_) {
            delete op;
            op = nullptr;
        }
    }

    Searcher* getSearcher(const CmdString& cmdString) const ;

private:
    Searcher* searcher_[MAX_MAINCOLUMNTYPE];

};
