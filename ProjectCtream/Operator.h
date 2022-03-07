#pragma once
#include "Employee.h"
#include "cmdParameter.h"

class Operator {
public:
    Operator(map<string, Employee>* dataBase_, vector<multimap<string, string>>* columnMap_) {
        dataBase = dataBase;
        columnMap = columnMap;
    }
    virtual void operate(vector<string>& searchQ, CmdString& cmdString) = 0;

protected:
    map<string, Employee>* dataBase;
    vector<multimap<string, string>>* columnMap;
};

class AddOperator : public Operator {
public:
    AddOperator(map<string, Employee>* dataBase, vector<multimap<string, string>>* columnMap) : Operator(dataBase, columnMap) {}

private:
    virtual void operate(vector<string>& searchQ, CmdString& cmdString) override;
};

class ModOperator : public Operator {
public:
    ModOperator(map<string, Employee>* dataBase, vector<multimap<string, string>>* columnMap) : Operator(dataBase, columnMap) {}

private:
    virtual void operate(vector<string>& searchQ, CmdString& cmdString) override;
};

class DelOperator : public Operator {
public:
    DelOperator(map<string, Employee>* dataBase, vector<multimap<string, string>>* columnMap) : Operator(dataBase, columnMap) {}

private:
    virtual void operate(vector<string>& searchQ, CmdString& cmdString) override;
};

class OperatorManager {
public:
    OperatorManager(map<string, Employee>* dataBase, vector<multimap<string, string>>* columnMap) {
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
            throw invalid_argument("해당 명령어는 지원하지 않습니다");
        }

        return myOperator[type];
    }

private:
    Operator* myOperator[MAX_CMDTYPE];
};