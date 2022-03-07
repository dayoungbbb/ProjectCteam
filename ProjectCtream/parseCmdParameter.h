#pragma once
#include <string>
#include <vector>
#include "define.h"
#include "Employee.h"
using namespace std;
class ParseCmdParameter {
public:
    virtual int parseCmdParameter(const vector<string>& cmdList) = 0;
    virtual void* getCmdString() = 0;

protected:
    bool isNumber(const string& str)
    {
        for (char const& c : str) {
            if (std::isdigit(c) == 0) return false;
        }
        return true;
    }

    bool isName(vector<string>& strList, const string& str) {
        strList = splitString(str, ' ');
        if (!(strList.size() == 2 || strList.size() == 1)) return false;
        return true;
    }

    bool isCl(const string& str) {
        if (str == "CL1" || str == "CL2" || str == "CL3" || str == "CL4") return true;
        return false;
    }

    bool isPhoneNum(vector<string>& strList, const string& str) {
        strList = splitString(str, '-');
        if (!(strList.size() == 3 || strList.size() == 1)) return false;
        return true;
    }

    bool isBirthday(vector<string>& strList, const string& str) {
        if (!isNumber(str)) return false;
        size_t strLength = str.length();
        if (strLength == 2 || strLength == 4) return true;
        if (strLength == 8) {
            strList.push_back(str.substr(0, 4));
            strList.push_back(str.substr(4, 2));
            strList.push_back(str.substr(6, 2));
            return true;
        }
        return true;
    }

    bool isCerti(const string& str) {
        if (str == "ADV" || str == "PRO" || str == "EXP") return true;
        return false;
    }

    vector<string> splitString(string input, char delimiter) {
        vector<string> answer;
        stringstream ss(input);
        string temp;

        while (getline(ss, temp, delimiter)) {
            answer.push_back(temp);
        }

        return answer;
    }
private:
    virtual int isValidCmdList(const vector<string>& cmdList) = 0;
};
class ParseOperatorParameter : public ParseCmdParameter {
protected:
    int getFirstOpt(const string& str) {
        if (str == " ") return BLANK;
        if (str == "-p") return PRINT;
        return INVALID;
    }

    int getSecondOpt(const string& condType, const string& str) {
        if (str == " ") return BLANK;
        if (str == "-f" && condType == "name") return FIRST_NAME;
        if (str == "-l" && condType == "name") return LAST_NAME;
        if (str == "-m" && condType == "phoneNum") return MIDDLE_NUM;
        if (str == "-l" && condType == "phoneNum") return LAST_NUM;
        if (str == "-y" && condType == "birthday") return YEAR;
        if (str == "-m" && condType == "birthday") return MONTH;
        if (str == "-d" && condType == "birthday") return DAY;
        return INVALID;
    }

    int getCond(const string& str) {
        if (str == "employeeNum") return EMPLOYEENUM;
        if (str == "name") return NAME;
        if (str == "cl") return CL;
        if (str == "phoneNum") return PHONENUM;
        if (str == "birthday") return BIRTHDAY;
        if (str == "certi") return CERTI;
        return INVALID;
    }

    bool isCondVal(int condition, vector<string>& strList, const string& str) {

        if (condition == EMPLOYEENUM && isNumber(str) && str.length() == 8) return true;
        if (condition == NAME && isName(strList, str)) return true;
        if (condition == CL && isCl(str)) return true;
        if (condition == PHONENUM && isPhoneNum(strList, str)) return true;
        if (condition == BIRTHDAY && isBirthday(strList, str)) return true;
        if (condition == CERTI && isCerti(str)) return true;
        return false;
    }
};

class ParseAddCmdParameter : public ParseCmdParameter {
public:
    int parseCmdParameter(const vector<string>& cmdList) override {
        if (!isValidCmdList(cmdList)) return false;
        return true;
    }
    void* getCmdString() {
        return &employee;
    }

private:
    int isValidCmdList(const vector<string>& cmdList) override {
        vector<string> nameList;
        vector<string> phoneNumList;
        vector<string> birthdayList;
        if (!isNumber(cmdList[4]) || cmdList[4].length() != 8) return false;
        if (!isName(nameList, cmdList[5])) return false;
        if (!isCl(cmdList[6])) return false;
        if (!isPhoneNum(phoneNumList, cmdList[7])) return false;
        if (!isBirthday(birthdayList, cmdList[8])) return false;
        if (!isCerti(cmdList[9])) return false;
        employee.employeeNum = cmdList[4];
        employee.name.firstName = nameList[0];
        employee.name.lastName = nameList[1];
        employee.cl = cmdList[6];
        employee.phoneNum.middle = phoneNumList[1];
        employee.phoneNum.last = phoneNumList[2];
        employee.bday.year = birthdayList[0];
        employee.bday.month = birthdayList[1];
        employee.bday.day = birthdayList[2];
        employee.certi = cmdList[9];
        return true;
    }

private:
    Employee employee;
};

class ParseDelCmdParameter : public ParseOperatorParameter {
public:
    int parseCmdParameter(const vector<string>& cmdList) override {
        if (!isValidCmdList(cmdList)) return false;
        return true;
    }
    void* getCmdString() {
        return &schCmd;
    }

private:
    int isValidCmdList(const vector<string>& cmdList) override {
        vector<string> strList;
        int isConditionVal = false;
        schCmd.firstOptionType = getFirstOpt(cmdList[1]);
        schCmd.secondOptionType = getSecondOpt(cmdList[4], cmdList[2]);
        schCmd.condType = getCond(cmdList[4]);
        isConditionVal = isCondVal(schCmd.condType, strList, cmdList[5]);
        if (schCmd.firstOptionType == INVALID) return false;
        if (schCmd.secondOptionType == INVALID) return false;
        if (schCmd.condType == INVALID) return false;
        if (isConditionVal == false) return false;
        schCmd.cond = cmdList[5];
        return true;
    }

private:
    SchCmd schCmd;
};
class ParseSchCmdParameter : public ParseOperatorParameter {
public:
    int parseCmdParameter(const vector<string>& cmdList) override {
        if (!isValidCmdList(cmdList)) return false;
        return true;
    }
    void* getCmdString() {
        return &schCmd;
    }
private:
    int isValidCmdList(const vector<string>& cmdList) override {
        vector<string> strList;
        int isConditionVal = false;
        schCmd.firstOptionType = getFirstOpt(cmdList[1]);
        schCmd.secondOptionType = getSecondOpt(cmdList[4], cmdList[2]);
        schCmd.condType = getCond(cmdList[4]);
        isConditionVal = isCondVal(schCmd.condType, strList, cmdList[5]);
        if (schCmd.firstOptionType == INVALID) return false;
        if (schCmd.secondOptionType == INVALID) return false;
        if (schCmd.condType == INVALID) return false;
        if (isConditionVal == false) return false;
        schCmd.cond = cmdList[5];
        return true;
    }
private:
    SchCmd schCmd;
};
class ParseModCmdParameter : public ParseOperatorParameter {
public:
    int parseCmdParameter(const vector<string>& cmdList) override {
        if (!isValidCmdList(cmdList)) return false;
        return true;
    }
    void* getCmdString() {
        return &modCmd;
    }

private:
    int isValidCmdList(const vector<string>& cmdList) override {
        vector<string> strList;
        int isSchConditionVal = false;
        int isModConditionVal = false;
        modCmd.schCmd.firstOptionType = getFirstOpt(cmdList[1]);
        modCmd.schCmd.secondOptionType = getSecondOpt(cmdList[4], cmdList[2]);
        modCmd.schCmd.condType = getCond(cmdList[4]);
        isSchConditionVal = isCondVal(modCmd.schCmd.condType, strList, cmdList[5]);
        modCmd.condType = getCond(cmdList[6]);
        isModConditionVal = isCondVal(modCmd.condType, strList, cmdList[7]);
        if (modCmd.schCmd.firstOptionType == INVALID) return false;
        if (modCmd.schCmd.secondOptionType == INVALID) return false;
        if (modCmd.schCmd.condType == INVALID) return false;
        if (isSchConditionVal == false) return false;
        if (modCmd.condType == INVALID) return false;
        if (isModConditionVal == false) return false;
        modCmd.schCmd.cond = cmdList[5];
        modCmd.cond = cmdList[7];
        return true;
    }

private:
    ModCmd modCmd;
};