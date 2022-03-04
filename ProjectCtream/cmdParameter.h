#pragma once
#include <sstream>
#include <string>
#include <vector>
#include "define.h"
#include "parseCmdParameter.h"
using namespace std;

class CmdParameter {
public:
    CmdParameter() {
        parseCmdParameter_[ADD] = new ParseAddCmdParameter();
        parseCmdParameter_[DEL] = new ParseDelCmdParameter();
        parseCmdParameter_[SCH] = new ParseSchCmdParameter();
        parseCmdParameter_[MOD] = new ParseModCmdParameter();
        parseCmdParameter_[NONE] = new ParseCmdParameter();
    }
    int parse(string cmd);
    CmdString getCmdString() const;
    int getCmdType() const;
private:
    vector<string> splitString(string input, char delimiter);

private:
    int cmdType_;
    int cmdParameterSize_[MAX_CMDTYPE] = { 10, 6, 6, 8, 0 };
    ParseCmdParameter *parseCmdParameter_[MAX_CMDTYPE];
    CmdString cmdString_;
    vector<string> cmdList_;
};
