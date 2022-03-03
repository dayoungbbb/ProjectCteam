#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "employee.h"
using namespace std;



int main()
{
    /*  SCH, -p, , , birthday, 19810630           SCH, 07843022, SEO KFI, CL3, 010 - 4837 - 6716, 19810630, ADV
                                                  SCH, 18050301, KIM EOE, CL4, 010 - 6848 - 4988, 19810630, EX
        SCH, , , , birthday, 19810630             SCH, 2
        SCH, , , , employeeNum, 23040123          SCH, NON*/
    string input = "SCH, , , ,name,KYUMOK KIM";
    vector<string> v;
    //vector<string> v = {"SCH", "","" ,"" ,"name", "KYUMOK KIM"};
    v = split(input, ',' );
    for (auto va : v) {
        remove(va.begin(), va.end(), ' ');
    }
    search(v);
    return 0;
}