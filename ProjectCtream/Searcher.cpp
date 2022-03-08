#include "Searcher.h"
void EmployeeNumSearcher::search(unordered_set<string>& searchQ, const void* cmdString) const
{
    SchCmd* schCmd = (SchCmd*)cmdString;
    string key = schCmd->cond;
    if ((*pDataBase_).count(key)) {
        searchQ.insert(key);
    }
}

void ColumnSearcher::search(unordered_set<string>& searchQ, const void* cmdString) const
{
    SchCmd* schCmd = (SchCmd*)cmdString;
    string key = schCmd->cond;

    if ((*columeMap_)[schCmd->condType].count(key)) {
        auto iter = (*columeMap_)[schCmd->condType].find(key);
        searchQ = iter->second;
    }
}

Searcher* SearcherManager::getSearcher(const void* cmdString) const
{
    SchCmd* schCmd = (SchCmd*)cmdString;
    if (schCmd->condType == EMPLOYEENUM) {
        return searcher_[EMPLOYEENUM];
    }
    return searcher_[OTHERCOLUMN];
}
