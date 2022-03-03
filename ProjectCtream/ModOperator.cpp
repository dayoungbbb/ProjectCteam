#include <map>
#include <stdexcept>
#include "Employee.h"

void ModifyColumn(map <string, Employee>& prevRecord, vector<Employee>::iterator& iter, string& changeColumn, Employee& changeInfo) {
    prevRecord.insert({ iter->employeeNum, *iter });

    if (changeColumn == "employeeNum") {
        iter->employeeNum = changeInfo.employeeNum;
    }
    else if (changeColumn == "name") {
        iter->firstName = changeInfo.firstName;
        iter->lastName = changeInfo.lastName;
    }
    else if (changeColumn == "cl") {
        iter->cl = changeInfo.cl;
    }
    else if (changeColumn == "phoneNum") {
        iter->middleOfPhoneNum = changeInfo.middleOfPhoneNum;
        iter->backOfPhoneNum = changeInfo.backOfPhoneNum;
    }
    else if (changeColumn == "birthday") {
        iter->yearOfBday = changeInfo.yearOfBday;
        iter->monthOfBday = changeInfo.monthOfBday;
        iter->dateOfBday = changeInfo.dateOfBday;
    }
    else if (changeColumn == "certi") {
        iter->certi = changeInfo.certi;
    }
    else {
        throw invalid_argument("Column 이름 확인해주세요");
    }
}

string Mod(string op1, string op2, string op3, string ConditioColumn, Employee& conditionInfo, string changeColumn, Employee& changeInfo) {

    map <string, Employee> prevRecord;

    if (ConditioColumn == "employeeNum") {
        for (auto iter = dataBase.begin(); iter != dataBase.end(); iter++) {
            if (iter->employeeNum == conditionInfo.employeeNum) {
                ModifyColumn(prevRecord, iter, changeColumn, changeInfo);
            }
        }
    }
    else if (ConditioColumn == "name") {
        for (auto iter = dataBase.begin(); iter != dataBase.end(); iter++) {
            if (iter->firstName == conditionInfo.firstName && iter->lastName == conditionInfo.lastName) {
                ModifyColumn(prevRecord, iter, changeColumn, changeInfo);
            }
        }
    }
    else if (ConditioColumn == "cl") {
        for (auto iter = dataBase.begin(); iter != dataBase.end(); iter++) {
            if (iter->cl == conditionInfo.cl) {
                ModifyColumn(prevRecord, iter, changeColumn, changeInfo);
            }
        }
    }
    else if (ConditioColumn == "phoneNum") {
        for (auto iter = dataBase.begin(); iter != dataBase.end(); iter++) {
            if (iter->middleOfPhoneNum == conditionInfo.middleOfPhoneNum &&
                iter->backOfPhoneNum == conditionInfo.backOfPhoneNum) {
                ModifyColumn(prevRecord, iter, changeColumn, changeInfo);
            }
        }
    }
    else if (ConditioColumn == "birthday") {
        for (auto iter = dataBase.begin(); iter != dataBase.end(); iter++) {
            if (iter->yearOfBday == conditionInfo.yearOfBday &&
                iter->monthOfBday == conditionInfo.monthOfBday &&
                iter->dateOfBday == conditionInfo.dateOfBday) {
                ModifyColumn(prevRecord, iter, changeColumn, changeInfo);
            }
        }
    }
    else if (ConditioColumn == "certi") {
        for (auto iter = dataBase.begin(); iter != dataBase.end(); iter++) {
            if (iter->certi == conditionInfo.certi) {
                ModifyColumn(prevRecord, iter, changeColumn, changeInfo);
            }
        }
    }
    else {
        throw invalid_argument("Column 이름 확인해주세요");
    }

    if (prevRecord.empty()) {
        return "MOD,NONE";
    }

    if (op1 == "-p") {
        string sResult;
        auto i = 0;
        for (auto iter = prevRecord.begin(); iter != prevRecord.end(); iter++) {
            if (i > 0) {
                sResult += "\n";
            }
            sResult += ("MOD," + iter->second.employeeNum + "," + iter->second.firstName + " " + iter->second.lastName + ","
                + iter->second.cl + "," + "010-" + iter->second.middleOfPhoneNum + "-"
                + iter->second.backOfPhoneNum + "," + iter->second.yearOfBday + iter->second.monthOfBday + iter->second.dateOfBday + ","
                + iter->second.certi);
            i++;
            if (i == 5) {
                break;
            }
        }
        return sResult;
    }
    else if (op1 == " ") {
        return "MOD," + to_string(prevRecord.size());
    }
    else {
        throw invalid_argument("Option 확인해주세요");
    }
}