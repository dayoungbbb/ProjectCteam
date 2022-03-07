#pragma once
#include <sstream>
#include <string>
#include <vector>
#include "define.h"
#include "parseCmdParameter.h"
using namespace std;

class CmdParameter {
public:
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
    ParseCmdParameter* pParseCmdParameter;
    vector<string> cmdList;
};
