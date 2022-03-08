#pragma once
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <queue>
#include <map>
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
    NAME_FIRST,
    NAME_LAST,
    PHONENUM_MIDDLE,
    PHONENUM_BACK,
    BIRTHDAY_YEAR,
    BIRTHDAY_MONTH,
    BIRTHDAY_DATE,
    MAX_COLUMNTYPE = 13
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

struct Employee {
    string employeeNum;
    Name name;
    string cl;
    PhoneNum phoneNum;
    Bday bday;
    string certi;
};