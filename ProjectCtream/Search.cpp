#include "Search.h"
#include <sstream>

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

ResultStruct search(vector<string> str)
{
    ResultStruct ret = { 0, };

    if (str[4] == "employeeNum") {
        for (auto data : dataBase) {
            if (str[5] == data.employeeNum) {
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
        string bday[3];
        bday[0] = str[5].substr(0, 4);
        bday[1] = str[5].substr(4, 2);
        bday[2] = str[5].substr(6, 2);

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