#include "ParserManager.h"
#include "Define.h"

int CmdParameter::parse(string cmd) {
    cmdList = splitString(cmd, ',');
    cmdType = INVALID;
    if (cmdList[0] == "ADD") cmdType = ADD;
    else if (cmdList[0] == "DEL") cmdType = DEL;
    else if (cmdList[0] == "SCH") cmdType = SCH;
    else if (cmdList[0] == "MOD") cmdType = MOD;

    if (cmdType == INVALID) return false;
    if (cmdList.size() != cmdParameterSize[cmdType]) return false;
    if (!(pParser[cmdType]->operateParser(cmdList))) return false;
    return true;
}

void* CmdParameter::getCmdString() const {
    return pParser[cmdType]->getCmdString();
}

int CmdParameter::getCmdType() const {
    return cmdType;
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

