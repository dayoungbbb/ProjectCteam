#pragma once
#include "Employee.h"
#include "cmdParameter.h"
#include <queue>

class Operator {
public:
    Operator(vector<Employee>* dataBase_) { dataBase = dataBase_; }
    virtual void operate(priority_queue<vector<Employee>::iterator>& searchQ, CmdString& cmdString) = 0;

protected:
    vector<Employee>* dataBase;
};

class AddOperator : public Operator {
public:
    AddOperator(vector<Employee>* dataBase) : Operator(dataBase) {}

private:
    virtual void operate(priority_queue<vector<Employee>::iterator>& searchQ, CmdString& cmdString) override;
};

class ModOperator : public Operator {
public:
    ModOperator(vector<Employee>* dataBase) : Operator(dataBase) {}

private:
    virtual void operate(priority_queue<vector<Employee>::iterator>& searchQ, CmdString& cmdString) override;
};

class DelOperator : public Operator {
public:
    DelOperator(vector<Employee>* dataBase) : Operator(dataBase) {}

private:
    virtual void operate(priority_queue<vector<Employee>::iterator>& searchQ, CmdString& cmdString) override;
};

class OperatorManager {
public:
    OperatorManager(vector<Employee>* dataBase) {
        myOperator[ADD] = new AddOperator(dataBase);
        myOperator[MOD] = new ModOperator(dataBase);
        myOperator[DEL] = new DelOperator(dataBase);
    }

    ~OperatorManager() {
        for (auto op : myOperator) {
            if (op) delete op;
        }
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