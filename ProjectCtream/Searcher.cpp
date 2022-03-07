#include "Searcher.h"
vector<string> EmployeeNumSearcher::search(const void* cmdString) const
{
    vector<string> searchResult;
    SchCmd* schCmd = (SchCmd*)cmdString;
    string key = schCmd->cond;
    if ((*pDataBase_).count(key)) {
        searchResult.emplace_back(key);
    }

    return searchResult;
}

vector<string> ColumnSearcher::search(const void* cmdString) const
{
    vector<string> searchResult;
    SchCmd* schCmd = (SchCmd*)cmdString;
    string key = schCmd->cond;

    if ((*columeMap_)[schCmd->condType].count(key)) {
        for (auto it = (*columeMap_)[schCmd->condType].lower_bound(key); it != (*columeMap_)[schCmd->condType].upper_bound(key); it++) {
            searchResult.emplace_back(it->second);
        }
    }

    return searchResult;
}

Searcher* SearcherManager::getSearcher(const void* cmdString) const
{
    SchCmd* schCmd = (SchCmd*)cmdString;
    if (schCmd->condType == EMPLOYEENUM) {
        return searcher_[EMPLOYEENUM];
    }
    return searcher_[OTHERCOLUMN];
}
