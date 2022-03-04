#pragma once
#include <string>
#include <vector>
#include "define.h"
using namespace std;
class ParseCmdParameter {
public:
    virtual int parseCmdParameter(CmdString& cmdString, const vector<string>& cmdList) {
        return false;
    }
private:
    virtual int isValidCmdList(const vector<string>& cmdList) {
        return false;
    }
};

class ParseAddCmdParameter : public ParseCmdParameter {
public:
    int parseCmdParameter(CmdString& cmdString, const vector<string>& cmdList) override {
        if (!isValidCmdList(cmdList)) return false;
        cmdString.col1 = cmdList[4];
        cmdString.col2 = cmdList[5];
        cmdString.col3 = cmdList[6];
        cmdString.col4 = cmdList[7];
        cmdString.col5 = cmdList[8];
        cmdString.col6 = cmdList[9];
        return true;
    }
private:
    int isValidCmdList(const vector<string>& cmdList) override {
        return true;
    }
};

class ParseDelCmdParameter : public ParseCmdParameter {
public:
    int parseCmdParameter(CmdString& cmdString, const vector<string>& cmdList) override {
        if (!isValidCmdList(cmdList)) return false;
        cmdString.op1 = cmdList[1];
        cmdString.op2 = cmdList[2];
        cmdString.col1 = cmdList[4];
        cmdString.col2 = cmdList[5];
        return true;
    }
private:
    int isValidCmdList(const vector<string>& cmdList) override {
        return true;
    }
};
class ParseSchCmdParameter : public ParseCmdParameter {
public:
    int parseCmdParameter(CmdString& cmdString, const vector<string>& cmdList) override {
        if (!isValidCmdList(cmdList)) return false;
        cmdString.op1 = cmdList[1];
        cmdString.op2 = cmdList[2];
        cmdString.col1 = cmdList[4];
        cmdString.col2 = cmdList[5];
        return true;
    }
private:
    int isValidCmdList(const vector<string>& cmdList) override {
        return true;
    }
};
class ParseModCmdParameter : public ParseCmdParameter {
public:
    int parseCmdParameter(CmdString& cmdString, const vector<string>& cmdList) override {
        if (!isValidCmdList(cmdList)) return false;
        cmdString.op1 = cmdList[1];
        cmdString.op2 = cmdList[2];
        cmdString.col1 = cmdList[4];
        cmdString.col2 = cmdList[5];
        cmdString.col3 = cmdList[6];
        cmdString.col4 = cmdList[7];
        return true;
    }
private:
    int isValidCmdList(const vector<string>& cmdList) override {
        return true;
    }
};