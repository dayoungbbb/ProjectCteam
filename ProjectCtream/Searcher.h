#pragma once
#include "Employee.h"
#include "define.h"
#include <queue>


class Searcher {
public:
    Searcher(map<string, Employee>* pDataBase, vector<multimap<string, string>>* columeMap) : pDataBase_(pDataBase), columeMap_(columeMap) {}
    virtual ~Searcher() {}
    virtual vector<string> search(const void* cmdString) const = 0;

protected:
    map<string, Employee>* pDataBase_;
    vector<multimap<string, string>>* columeMap_;
};

class EmployeeNumSearcher : public Searcher {
public:
    EmployeeNumSearcher(map<string, Employee>* pDataBase, vector<multimap<string, string>>* columeMap) : Searcher(pDataBase, columeMap) {}
    ~EmployeeNumSearcher() {}
private:
    virtual vector<string> search(const void* cmdString) const override;
};

class ColumnSearcher : public Searcher {
public:
    ColumnSearcher(map<string, Employee>* pDataBase, vector<multimap<string, string>>* columeMap) : Searcher(pDataBase, columeMap) {}
    ~ColumnSearcher() {}
private:
    virtual vector<string> search(const void* cmdString) const override;
};

class SearcherManager {
public:
    SearcherManager(map<string, Employee>* pDataBase, vector<multimap<string, string>>* columeMap) {
        searcher_[EMPLOYEENUM] = new EmployeeNumSearcher(pDataBase, columeMap);
        searcher_[OTHERCOLUMN] = new ColumnSearcher(pDataBase, columeMap);
    }
    ~SearcherManager() {
        for (auto& op : searcher_) {
            delete op;
            op = nullptr;
        }
    }

    Searcher* getSearcher(const void* cmdString) const ;

private:
    Searcher* searcher_[MAX_MAINCOLUMNTYPE];

};
