#include "add.h"

struct Parser {
    string op1;
    string op2;
    string col1;
    string col2;
    string col3;
    string col4;
    string col5;
    string col6;
};

Parser getParser(vector<string> parseStr) {
    Parser parser;
    if (parseStr[0] == "ADD") {
        parser.col1 = parseStr[4];
        parser.col2 = parseStr[5];
        parser.col3 = parseStr[6];
        parser.col4 = parseStr[7];
        parser.col5 = parseStr[8];
        parser.col6 = parseStr[9];
    }
    else if (parseStr[0] == "DEL") {
        parser.op1 = parseStr[1];
        parser.op2 = parseStr[2];
        parser.col1 = parseStr[4];
        parser.col2 = parseStr[5];
    }
    else if (parseStr[0] == "SCH") {
        parser.op1 = parseStr[1];
        parser.op2 = parseStr[2];
        parser.col1 = parseStr[4];
        parser.col2 = parseStr[5];
    }
    else if (parseStr[0] == "MOD") {
        parser.op1 = parseStr[1];
        parser.op2 = parseStr[2];
        parser.col1 = parseStr[4];
        parser.col2 = parseStr[5];
        parser.col3 = parseStr[6];
        parser.col4 = parseStr[7];
    }
    else {
        throw invalid_argument("invalid command");
    }
    return parser;
}

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

void add(Parser& parser) {
    Employee employee;
    employee.employeeNum = parser.col1;
    parseName(parser.col2, employee.firstName, employee.lastName);
    employee.cl = parser.col3;
    parsePhoneNum(parser.col4, employee.middleOfPhoneNum, employee.backOfPhoneNum);
    parseBirthday(parser.col5, employee.yearOfBday, employee.monthOfBday, employee.dateOfBday);
    employee.certi = parser.col6;
    dataBase.push_back(employee);
}

