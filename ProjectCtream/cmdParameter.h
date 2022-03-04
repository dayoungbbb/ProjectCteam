#pragma once
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class CmdParameter {
public:
    int parseCmdParameter(string cmd);
    string getOp1();
    string getOp2();
    string getCol1();
    string getCol2();
    string getCol3();
    string getCol4();
    string getCol5();
    string getCol6();
private:
    int parseAddCmdParameter();
    int parseDelCmdParameter();
    int parseSchCmdParameter();
    int parseModCmdParameter();
    int isValidAddCmdParameter();
    int isValidDelCmdParameter();
    int isValidSchCmdParameter();
    int isValidModCmdParameter();
    vector<string> splitString(string input, char delimiter);

private:
    int cmdType;
    string op1;
    string op2;
    string col1;
    string col2;
    string col3;
    string col4;
    string col5;
    string col6;
    vector<string> cmdList;
};
