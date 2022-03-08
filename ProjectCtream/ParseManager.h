#pragma once
#include <sstream>
#include <string>
#include <vector>
#include "Define.h"
#include "ParseCmdParameter.h"
using namespace std;

class CmdParameter {
public:
    CmdParameter() {
        pParseCmdParameter[ADD] = new ParseAddCmdParameter();
        pParseCmdParameter[DEL] = new ParseDelCmdParameter();
        pParseCmdParameter[SCH] = new ParseSchCmdParameter();
        pParseCmdParameter[MOD] = new ParseModCmdParameter();
    }
    ~CmdParameter() {
        if (pParseCmdParameter) delete pParseCmdParameter;
    }
    int parse(string cmd);
    void* getCmdString() const;
    int getCmdType() const;

private:
    vector<string> splitString(string input, char delimiter);

private:
    int cmdType;
    int cmdParameterSize[MAX_CMDTYPE] = { 10, 6, 6, 8 };
    ParseCmdParameter* pParseCmdParameter[MAX_CMDTYPE];
    vector<string> cmdList;
};
