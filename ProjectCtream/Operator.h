#pragma once
#include "ParserManager.h"

class Operator {
public:
    Operator(map<string, Employee>* dataBase_, vector<map<string, unordered_set<string>>>* columnMap_) {
        dataBase = dataBase_;
        columnMap = columnMap_;
    }
    virtual void operate(unordered_set<string>& searchQ, void* cmdString) = 0;

protected:
    void addColumnMap(Employee& employee);
    void delColumnMap(Employee& employee);

private:
    void delColumnMap(EColumn eColumn, Employee& employee, string key);

protected:
    map<string, Employee>* dataBase;
    vector<map<string, unordered_set<string>>>* columnMap;
};

class AddOperator : public Operator {
public:
    AddOperator(map<string, Employee>* dataBase, vector<map<string, unordered_set<string>>>* columnMap) : Operator(dataBase, columnMap) {}

private:
    virtual void operate(unordered_set<string>& searchQ, void* cmdString) override;
};

class ModOperator : public Operator {
public:
    ModOperator(map<string, Employee>* dataBase, vector<map<string, unordered_set<string>>>* columnMap) : Operator(dataBase, columnMap) {}

private:
    virtual void operate(unordered_set<string>& searchQ, void* cmdString) override;
    vector<string> split(string input, char delimiter);
};

class DelOperator : public Operator {
public:
    DelOperator(map<string, Employee>* dataBase, vector<map<string, unordered_set<string>>>* columnMap) : Operator(dataBase, columnMap) {}

private:
    virtual void operate(unordered_set<string>& searchQ, void* cmdString) override;
};

class OperatorManager {
public:
    OperatorManager(map<string, Employee>* dataBase, vector<map<string, unordered_set<string>>>* columnMap) {
        myOperator[ADD] = new AddOperator(dataBase, columnMap);
        myOperator[MOD] = new ModOperator(dataBase, columnMap);
        myOperator[DEL] = new DelOperator(dataBase, columnMap);
        myOperator[SCH] = nullptr;
    }

    ~OperatorManager() {
        for (auto op : myOperator)
            if (op) delete op;
    }

    Operator* getOperator(CmdType type) const {
        if (type >= MAX_CMDTYPE) {
            throw invalid_argument("???? ???????? ???????? ????????");
        }

        return myOperator[type];
    }

private:
    Operator* myOperator[MAX_CMDTYPE];
};