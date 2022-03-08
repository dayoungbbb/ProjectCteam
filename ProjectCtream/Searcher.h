#pragma once
#include "Define.h"
#include <queue>

class Searcher {
public:
    Searcher(map<string, Employee>* pDataBase, vector<map<string, unordered_set<string>>>* columeMap) : pDataBase_(pDataBase), columeMap_(columeMap) {}
    virtual ~Searcher() {}
    virtual void search(unordered_set<string>& searchQ, const void* cmdString) const = 0;

protected:
    map<string, Employee>* pDataBase_;
    vector<map<string, unordered_set<string>>>* columeMap_;
};

class EmployeeNumSearcher : public Searcher {
public:
    EmployeeNumSearcher(map<string, Employee>* pDataBase, vector<map<string, unordered_set<string>>>* columeMap) : Searcher(pDataBase, columeMap) {}
    ~EmployeeNumSearcher() {}
private:
    virtual void search(unordered_set<string>& searchQ, const void* cmdString) const override;
};

class ColumnSearcher : public Searcher {
public:
    ColumnSearcher(map<string, Employee>* pDataBase, vector<map<string, unordered_set<string>>>* columeMap) : Searcher(pDataBase, columeMap) {}
    ~ColumnSearcher() {}
private:
    virtual void search(unordered_set<string>& searchQ, const void* cmdString) const override;
};

class SearcherManager {
public:
    SearcherManager(map<string, Employee>* pDataBase, vector<map<string, unordered_set<string>>>* columeMap) {
        searcher_[EMPLOYEENUM] = new EmployeeNumSearcher(pDataBase, columeMap);
        searcher_[OTHERCOLUMN] = new ColumnSearcher(pDataBase, columeMap);
    }
    ~SearcherManager() {
        delete searcher_[EMPLOYEENUM];
        delete searcher_[OTHERCOLUMN];
    }

    Searcher* getSearcher(const void* cmdString) const ;

private:
    Searcher* searcher_[2];
};
