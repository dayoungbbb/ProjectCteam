#pragma once
#include "Employee.h"


struct resultStruct {
    int cnt;
    vector<Employee> info;
};
using ResultStruct = struct resultStruct;

vector<string> split(string input, char delimiter);
ResultStruct search(vector<string> str);