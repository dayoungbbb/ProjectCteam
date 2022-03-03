#pragma once
#include "Employee.h"
#include <sstream>
#include <stdexcept>

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

Parser getParser(vector<string> parseStr);

vector<string> splitString(string input, char delimiter);

void parseName(string& str, string& firstName, string& lastName);
void parsePhoneNum(string& str, string& middleOfPhoneNum, string& backOfPhoneNum);
void parseBirthday(string& str, string& year, string& month, string& day);

void add(Parser& parser);
