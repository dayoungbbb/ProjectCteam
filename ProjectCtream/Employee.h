#pragma once
#include <vector>
#include <string>

using namespace std;

enum CareerLevel {
    CL1 = 0,
    CL2 = 1,
    CL3 = 2,
    CL4 = 3
};

enum CertiLevel {
    ADV = 0,
    PRO = 1,
    EXP = 2
};

static string clString[4] = { "CL1", "CL2", "CL3", "CL4" };
static string certiString[3] = { "ADV", "PRO", "EXP" };

struct Employee {
    string employeeNum;
    string firstName;
    string lastName;
    string cl;
    string middleOfPhoneNum;
    string backOfPhoneNum;
    string yearOfBday;
    string monthOfBday;
    string dateOfBday;
    string certi;
};

static vector<Employee> dataBase;
