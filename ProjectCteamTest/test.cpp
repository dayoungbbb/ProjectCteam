#include "pch.h"
#include "../ProjectCtream/employee.h"
#include <vector>
vector<string> seperateString(string input) {
	vector<string> v;

	v = split(input, ',');
	for (auto va : v) {
		remove(va.begin(), va.end(), ' ');
	}
	return v;
}
TEST(TestCaseName, SearchTestBirthday) {
	string input = "SCH, , , , birthday, 19810630";
	vector<string> v = seperateString(input);
	ResultStruct ret = search(v);

	EXPECT_EQ(0, ret.cnt);
	EXPECT_TRUE(true);
}

TEST(TestCaseName, SearchTestEmployeeNum) {
	string input = "SCH, , , , employeeNum, 23040123";
	vector<string> v = seperateString(input);
	ResultStruct ret = search(v);
	EXPECT_EQ(0, ret.cnt);

	EXPECT_TRUE(true);
}

TEST(TestCaseName, SearchTestName) {
	string input = "SCH, , , ,name,KYUMOK KIM";
	vector<string> v = seperateString(input);
	ResultStruct ret = search(v);

	EXPECT_EQ(0, ret.cnt);
	EXPECT_TRUE(true);
}
TEST(TestCaseName, SearchTestCL) {
	string input = "CH, , , ,cl,CL2";
	vector<string> v = seperateString(input);
	ResultStruct ret = search(v);

	EXPECT_EQ(0, ret.cnt);
	EXPECT_TRUE(true);
}
TEST(TestCaseName, SearchTestPhoneNum) {
	string input = "CH, , , ,phoneNum,010-3333-1234";
	vector<string> v = seperateString(input);
	ResultStruct ret = search(v);

	EXPECT_EQ(0, ret.cnt);
	EXPECT_TRUE(true);
}
TEST(TestCaseName, SearchTestCerti) {
	string input = "CH, , , ,certi,ADV";
	vector<string> v = seperateString(input);
	ResultStruct ret = search(v);

	EXPECT_EQ(0, ret.cnt);
	EXPECT_TRUE(true);
}
TEST(TestCaseName, SearchTestBirthday) {
	string input = "SCH, -p, , , birthday, 19810630";
	vector<string> v = seperateString(input);
	ResultStruct ret = search(v);
	for(int i = 0; i < ret.cnt; i++){
		for (auto emp : ret.info) {
				cout << emp.backOfPhoneNum << " ";
				cout << emp.certi << " ";
				cout << emp.cl << " ";
				cout << emp.dateOfBday << " ";
				cout << emp.employeeNum << " ";
				cout << emp.firstName << " ";
				cout << emp.frontOfPhoneNum << " ";
				cout << emp.lastName << " ";
				cout << emp.middleOfPhoneNum << " ";
				cout << emp.monthOfBday << " ";
				cout << emp.yearOfBday << " ";
				cout << endl;
		}
	}

	EXPECT_TRUE(true);
}

