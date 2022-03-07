#pragma once
#include <string>
using namespace std;
#define PhoneNumSize 3
#define NameSize 2
#define BirthdaySize 8
#define INVALID -1

enum CmdType {
    ADD = 0,
    DEL,
    SCH,
    MOD,
    MAX_CMDTYPE = 4
};

enum EColumn {
    EMPLOYEENUM = 0,
    NAME,
    CL,
    PHONENUM,
    BIRTHDAY,
    CERTI,
    MAX_COLUMNTYPE = 6
};

enum OptionType {
    BLANK,
    PRINT,
    FIRST_NAME,
    LAST_NAME,
    MIDDLE_NUM,
    LAST_NUM,
    YEAR,
    MONTH,
    DAY,
    MAX_OPTION_TYPE
};

static const string CmdTypeStr[] = {
    "ADD",
    "DEL",
    "SCH",
    "MOD",
    "INVALID",
};

struct Name {
    string firstName;
    string lastName;
};

struct PhoneNum {
    string middle;
    string last;
};

struct Bday {
    string year;
    string month;
    string day;
};

struct SchCmd {
    int firstOptionType;
    int secondOptionType;
    int condType;
    string cond;
};

struct ModCmd {
    SchCmd schCmd;
    int condType;
    string cond;
};
