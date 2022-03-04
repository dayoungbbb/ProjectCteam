#include "cmdParameter.h"
#include "define.h"

int CmdParameter::parseCmdParameter(string cmd) {
    cmdList = splitString(cmd, ',');
    cmdType = NONE;
    if (cmdList[0] == "ADD") cmdType = ADD;
    else if (cmdList[0] == "DEL") cmdType = DEL;
    else if (cmdList[0] == "SCH") cmdType = SCH;
    else if (cmdList[0] == "MOD") cmdType = MOD;

    if (cmdType == NONE) return false;
    if (cmdList.size() != cmdParameterSize[cmdType]) return false;
    switch (cmdType) {
    case ADD:
        return parseAddCmdParameter();
    case DEL:
        return parseDelCmdParameter();
    case SCH:
        return parseSchCmdParameter();
    case MOD:
        return parseModCmdParameter();
    default:
        return false;
    }
}
string CmdParameter::getOp1() {
    return op1;
}
string CmdParameter::getOp2() {
    return op2;
}
string CmdParameter::getCol1() {
    return col1;
}
string CmdParameter::getCol2() {
    return col2;
}
string CmdParameter::getCol3() {
    return col3;
}
string CmdParameter::getCol4() {
    return col4;
}
string CmdParameter::getCol5() {
    return col5;
}
string CmdParameter::getCol6() {
    return col6;
}
int CmdParameter::parseAddCmdParameter() {
    if (!isValidAddCmdParameter()) return false;
    col1 = cmdList[4];
    col2 = cmdList[5];
    col3 = cmdList[6];
    col4 = cmdList[7];
    col5 = cmdList[8];
    col6 = cmdList[9];
    return true;
}

int CmdParameter::parseDelCmdParameter() {
    if (!isValidAddCmdParameter()) return false;
    op1 = cmdList[1];
    op2 = cmdList[2];
    col1 = cmdList[4];
    col2 = cmdList[5];
    return true;
}

int CmdParameter::parseSchCmdParameter() {
    if (!isValidAddCmdParameter()) return false;
    op1 = cmdList[1];
    op2 = cmdList[2];
    col1 = cmdList[4];
    col2 = cmdList[5];
    return true;
}
int CmdParameter::parseModCmdParameter() {
    if (!isValidAddCmdParameter()) return false;
    op1 = cmdList[1];
    op2 = cmdList[2];
    col1 = cmdList[4];
    col2 = cmdList[5];
    col3 = cmdList[6];
    col4 = cmdList[7];
    return true;
}
int CmdParameter::isValidAddCmdParameter() {
    return true;
}
int CmdParameter::isValidDelCmdParameter() {
    return true;
}
int CmdParameter::isValidSchCmdParameter() {
    return true;
}
int CmdParameter::isValidModCmdParameter() {
    return true;
}

vector<string> CmdParameter::splitString(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

