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