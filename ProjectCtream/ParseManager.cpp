#include "ParseManager.h"
#include "Define.h"

int CmdParameter::parse(string cmd) {
    cmdList = splitString(cmd, ',');
    cmdType = INVALID;
    if (cmdList[0] == "ADD") {
        cmdType = ADD;
        pParseCmdParameter = new ParseAddCmdParameter();
    }
    else if (cmdList[0] == "DEL") {
        cmdType = DEL;
        pParseCmdParameter = new ParseDelCmdParameter();
    }
    else if (cmdList[0] == "SCH") {
        cmdType = SCH;
        pParseCmdParameter = new ParseSchCmdParameter();
    }
    else if (cmdList[0] == "MOD") {
        cmdType = MOD;
        pParseCmdParameter = new ParseModCmdParameter();
    }

    if (cmdType == INVALID) return false;
    if (cmdList.size() != cmdParameterSize[cmdType]) return false;
    if (!(pParseCmdParameter->parseCmdParameter(cmdList))) return false;
    return true;
}

void* CmdParameter::getCmdString() const {
    return pParseCmdParameter->getCmdString();
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

