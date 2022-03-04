#pragma once
#include <vector>
#include <string>
#include <sstream>

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

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

void parseName(string& str, string& firstName, string& lastName) {
    vector<string> parseStr = split(str, ' ');
    firstName = parseStr[0];
    lastName = parseStr[1];
}

void parsePhoneNum(string& str, string& middleOfPhoneNum, string& backOfPhoneNum) {
    vector<string> parseStr = split(str, '-');
    middleOfPhoneNum = parseStr[1];
    backOfPhoneNum = parseStr[2];
}

void parseBirthday(string& str, string& year, string& month, string& day) {
    year = str.substr(0, 4);
    month = str.substr(4, 2);
    day = str.substr(6, 2);
}
