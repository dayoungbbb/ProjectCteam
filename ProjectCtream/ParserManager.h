#pragma once
#include <sstream>
#include <string>
#include <vector>
#include "Define.h"
#include "Parser.h"
using namespace std;

class CmdParameter {
public:
    CmdParameter() {
        pParser[ADD] = new AddParser();
        pParser[DEL] = new DelParser();
        pParser[SCH] = new SchParser();
        pParser[MOD] = new ModParser();
    }
    ~CmdParameter() {
        if (pParser[ADD]) delete pParser[ADD];
        if (pParser[DEL]) delete pParser[DEL];
        if (pParser[SCH]) delete pParser[SCH];
        if (pParser[MOD]) delete pParser[MOD];
    }
    int parse(string cmd);
    void* getCmdString() const;
    int getCmdType() const;

private:
    vector<string> splitString(string input, char delimiter);

private:
    int cmdType;
    int cmdParameterSize[MAX_CMDTYPE] = { 10, 6, 6, 8 };
    Parser* pParser[MAX_CMDTYPE];
    vector<string> cmdList;
};
