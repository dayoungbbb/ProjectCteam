#pragma once
#include <string>
using namespace std;
#define PhoneNumSize 3
#define NameSize 2
#define BirthdaySize 8
#define INVALID -1

struct CmdString {
    string op1;
    string op2;
    string col1;
    string col2;
    string col3;
    string col4;
    string col5;
    string col6;
};

enum CmdType {
    ADD = 0,
    DEL,
    SCH,
    MOD,
    MAX_CMDTYPE
};

static const string CmdTypeStr[] = {
    "ADD",
    "DEL",
    "SCH",
    "MOD",
    "INVALID",
};