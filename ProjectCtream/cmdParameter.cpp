#include "cmdParameter.h"
#include "define.h"

int CmdParameter::parse(string cmd) {
    cmdList_ = splitString(cmd, ',');
    cmdType_ = INVALID;
    if (cmdList_[0] == "ADD") cmdType_ = ADD;
    else if (cmdList_[0] == "DEL") cmdType_ = DEL;
    else if (cmdList_[0] == "SCH") cmdType_ = SCH;
    else if (cmdList_[0] == "MOD") cmdType_ = MOD;

    if (cmdType_ == INVALID) return false;
    if (cmdList_.size() != cmdParameterSize_[cmdType_]) return false;
    if (!(parseCmdParameter_[cmdType_]->parseCmdParameter(cmdString_, cmdList_))) return false;
    return true;
}

CmdString CmdParameter::getCmdString() const {
    return cmdString_;
}

int CmdParameter::getCmdType() const {
    return cmdType_;
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

