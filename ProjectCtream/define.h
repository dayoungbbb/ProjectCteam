#pragma once
#include <string>
using namespace std;
#define PhoneNumSize 3
#define NameSize 2
#define BirthdaySize 8
#define INVALID -1
#define PRINT 1
#define BLANK 0
#define OTHERCOLUMN 1

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
    MAX_MAINCOLUMNTYPE = 6,
    SUB_COLUMNTYPESTART = MAX_MAINCOLUMNTYPE,
    NAME_FIRST = SUB_COLUMNTYPESTART,
    NAME_LAST,
    PHONENUM_MIDDLE,
    PHONENUM_BACK,
    BIRTHDAY_YEAR,
    BIRTHDAY_MONTH,
    BIRTHDAY_DATE,
    MAX_COLUMNTYPE,
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
    int printOption;
    int condType;
    string cond;
};

struct ModCmd {
    SchCmd schCmd;
    int condType;
    string cond;
};