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
    virtual void operate(priority_queue<vector<Employee>::iterator>& searchQ, CmdString& cmdString) override;
};

class ModOperator : public Operator {
public:
    ModOperator(vector<Employee>* dataBase) : Operator(dataBase) {}
    virtual void operate(priority_queue<vector<Employee>::iterator>& searchQ, CmdString& cmdString) override;
};

class DelOperator : public Operator {
public:
    DelOperator(vector<Employee>* dataBase) : Operator(dataBase) {}
    virtual void operate(priority_queue<vector<Employee>::iterator>& searchQ, CmdString& cmdString) override;
};

class OperatorManager {
public:
    OperatorManager(vector<Employee>* dataBase) {
        addOperator = new AddOperator(dataBase);
        modOperator = new ModOperator(dataBase);
        delOperator = new DelOperator(dataBase);
    }

    ~OperatorManager() {
        if (addOperator) delete addOperator;
        if (modOperator) delete modOperator;
        if (delOperator) delete delOperator;
    }

    Operator* getOperator(CmdType type) const {
        if (ADD == type) {
            return addOperator;
        }
        else if (MOD == type) {
            return modOperator;
        }
        else if (DEL == type) {
            return delOperator;
        }
        else {
            throw invalid_argument("해당 명령어는 지원하지 않습니다");
        }
    }

private:
    AddOperator* addOperator;
    ModOperator* modOperator;
    DelOperator* delOperator;
};