#include <iostream>
#include <vector>
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
    CareerLevel cl;
    string frontOfPhoneNum;
    string middleOfPhoneNum;
    string backOfPhoneNum;
    unsigned int yearOfBday;
    unsigned int monthOfBday;
    unsigned int dateOfBday;
    CertiLevel certi;
};

vector<Employee> dataBase;

void search()
{
    cout << "Search" << endl;
}

int main()
{
    search();
    return 0;
}