#pragma once
#include "Employee.h"
#include "cmdParameter.h"
class Operator {
public:
    Operator(list<Employee>* dataBase_) { dataBase = dataBase_; }
    virtual void operate(prioirtyQ& searchQ, CmdString& cmdString) = 0;

protected:
    list<Employee>* dataBase;
};

class AddOperator : public Operator {
public:
    AddOperator(list<Employee>* dataBase) : Operator(dataBase) {}

private:
    virtual void operate(prioirtyQ& searchQ, CmdString& cmdString) override;
};

class ModOperator : public Operator {
public:
    ModOperator(list<Employee>* dataBase) : Operator(dataBase) {}

private:
    virtual void operate(prioirtyQ& searchQ, CmdString& cmdString) override;
};

class DelOperator : public Operator {
public:
    DelOperator(list<Employee>* dataBase) : Operator(dataBase) {}

private:
    virtual void operate(prioirtyQ& searchQ, CmdString& cmdString) override;
};

class OperatorManager {
public:
    OperatorManager(list<Employee>* dataBase) {
        myOperator[ADD] = new AddOperator(dataBase);
        myOperator[MOD] = new ModOperator(dataBase);
        myOperator[DEL] = new DelOperator(dataBase);
        myOperator[SCH] = nullptr;
    }

    ~OperatorManager() {
        for (auto op : myOperator)
            if (op) delete op;
    }

    Operator* getOperator(CmdType type) const {
        if (type >= MAX_CMDTYPE) {
            throw invalid_argument("�ش� ��ɾ�� �������� �ʽ��ϴ�");
        }

        return myOperator[type];
    }

private:
    Operator* myOperator[MAX_CMDTYPE];
};