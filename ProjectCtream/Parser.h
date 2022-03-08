#pragma once
#include <string>
#include <vector>
#include "Define.h"

class Parser {
public:
    virtual int operateParser(const vector<string>& cmdList) = 0;
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

private:
    vector<string> splitString(string input, char delimiter) {
        vector<string> answer;
        stringstream ss(input);
        string temp;

        while (getline(ss, temp, delimiter)) {
            answer.push_back(temp);
        }

        return answer;
    }

    virtual int isValidCmdList(const vector<string>& cmdList) = 0;
};
class OperatorParser : public Parser {
protected:
    int getFirstOpt(const string& str) {
        if (str == " ") return DISABLE;
        if (str == "-p") return ENABLE;
        return INVALID;
    }

    int getColumn(const string& condType) {
        if (condType == "employeeNum") return EMPLOYEENUM;
        if (condType == "name") return NAME;
        if (condType == "cl") return CL;
        if (condType == "phoneNum") return PHONENUM;
        if (condType == "birthday") return BIRTHDAY;
        if (condType == "certi") return CERTI;
        return INVALID;
    }

    int getSecondOpt(const string& condType, const string& str) {
        if (str == " ") return getColumn(condType);
        if (str == "-f" && condType == "name") return NAME_FIRST;
        if (str == "-l" && condType == "name") return NAME_LAST;
        if (str == "-m" && condType == "phoneNum") return PHONENUM_MIDDLE;
        if (str == "-l" && condType == "phoneNum") return PHONENUM_BACK;
        if (str == "-y" && condType == "birthday") return BIRTHDAY_YEAR;
        if (str == "-m" && condType == "birthday") return BIRTHDAY_MONTH;
        if (str == "-d" && condType == "birthday") return BIRTHDAY_DATE;
        return INVALID;
    }

    bool isCondVal(int condition, vector<string>& strList, const string& str) {

        if (condition == EMPLOYEENUM && isNumber(str) && str.length() == 8) return true;
        if ((condition == NAME || condition == NAME_LAST || condition == NAME_FIRST) && isName(strList, str)) return true;
        if (condition == CL && isCl(str)) return true;
        if ((condition == PHONENUM || condition == PHONENUM_BACK || condition == PHONENUM_MIDDLE) && isPhoneNum(strList, str)) return true;
        if ((condition == BIRTHDAY || condition == BIRTHDAY_YEAR || condition == BIRTHDAY_MONTH || condition == BIRTHDAY_DATE) && isBirthday(strList, str)) return true;
        if (condition == CERTI && isCerti(str)) return true;
        return false;
    }
};

class AddParser : public Parser {
public:
    int operateParser(const vector<string>& cmdList) override {
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

class DelParser : public OperatorParser {
public:
    int operateParser(const vector<string>& cmdList) override {
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
        schCmd.printOption = getFirstOpt(cmdList[1]);
        schCmd.condType = getSecondOpt(cmdList[4], cmdList[2]);
        isConditionVal = isCondVal(schCmd.condType, strList, cmdList[5]);
        if (schCmd.printOption == INVALID) return false;
        if (schCmd.condType == INVALID) return false;
        if (isConditionVal == false) return false;
        schCmd.cond = cmdList[5];
        return true;
    }

private:
    SchCmd schCmd;
};

class SchParser : public OperatorParser {
public:
    int operateParser(const vector<string>& cmdList) override {
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
        schCmd.printOption = getFirstOpt(cmdList[1]);
        schCmd.condType = getSecondOpt(cmdList[4], cmdList[2]);
        isConditionVal = isCondVal(schCmd.condType, strList, cmdList[5]);
        if (schCmd.printOption == INVALID) return false;
        if (schCmd.condType == INVALID) return false;
        if (isConditionVal == false) return false;
        schCmd.cond = cmdList[5];
        return true;
    }

private:
    SchCmd schCmd;
};

class ModParser : public OperatorParser {
public:
    int operateParser(const vector<string>& cmdList) override {
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
        modCmd.schCmd.printOption = getFirstOpt(cmdList[1]);
        modCmd.schCmd.condType = getSecondOpt(cmdList[4], cmdList[2]);
        isSchConditionVal = isCondVal(modCmd.schCmd.condType, strList, cmdList[5]);
        modCmd.condType = getSecondOpt(cmdList[6], " ");
        isModConditionVal = isCondVal(modCmd.condType, strList, cmdList[7]);
        if (modCmd.schCmd.printOption == INVALID) return false;
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