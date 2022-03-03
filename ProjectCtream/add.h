#pragma once
#include "Employee.h"
#include <sstream>
#include <stdexcept>

Parser getParser(vector<string> parseStr);

vector<string> split(string input, char delimiter);

void parseName(string& str, string& firstName, string& lastName);
void parsePhoneNum(string& str, string& middleOfPhoneNum, string& backOfPhoneNum);
void parseBirthday(string& str, string& year, string& month, string& day);

void add(Parser& parser);