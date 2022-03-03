#pragma once
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

struct Employee {
    unsigned int employeeNum;
    string firstName;
    string lastName;
    string cl;
    string frontOfPhoneNum;
    string middleOfPhoneNum;
    string backOfPhoneNum;
    unsigned int yearOfBday;
    unsigned int monthOfBday;
    unsigned int dateOfBday;
    string certi;
};
struct resultStruct {
    int cnt;
    vector<Employee> info;
};
using ResultStruct = struct resultStruct;
vector<Employee> dataBase;
vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}
void add(vector<string> str)
{
    
}
ResultStruct search(vector<string> str)
{
    ResultStruct ret = { 0, };
   
    if (str[4] == "employeeNum") {
        for (auto data : dataBase) {
            if (stoul(str[5], nullptr, 0) == data.employeeNum) {
                ret.cnt++;
            }
        }
    }
    else if (str[4] == "name") {
        vector<string> vname = split(str[5], ' ');
        for (auto data : dataBase) {
            if (vname[0] == data.firstName && vname[0] == data.lastName) {
                ret.cnt++;
            }
        }
    }
    else if (str[4] == "cl") {
        int clNum = stoi(str[5].substr(2, 1));
        for (auto data : dataBase) {
            if (str[5].substr(2, 1) == data.cl) {
                ret.cnt++;
            }
        }
    }
    else if (str[4] == "phoneNum") {
        string phoneMiddle = str[5].substr(4, 4);
        string phoneLast = str[5].substr(9, 4);
        for (auto data : dataBase) {
            if ((phoneMiddle == data.middleOfPhoneNum) && (phoneLast == data.backOfPhoneNum)) {
                ret.cnt++;
            }
        }
    }
    else if (str[4] == "birthday") {
        unsigned int bday[3];
        bday[0] = stoul(str[5].substr(0, 4));
        bday[1] = stoul(str[5].substr(4, 2));
        bday[2] = stoul(str[5].substr(6, 2));

        for (auto data : dataBase) {
            if ((bday[0] == data.yearOfBday) && (bday[1] == data.monthOfBday) && (bday[2] == data.dateOfBday)) {
                ret.cnt++;
            }
        }
    }
    else if (str[4] == "certi") {
        for (auto data : dataBase) {
            if (str[5] == data.certi) {
                ret.cnt++;
            }
        }
    }



    //option 1 ( -p), option 2 (-f, -l(name), -m, -l(phoneNum), -y, m, d()
    return ret;
}