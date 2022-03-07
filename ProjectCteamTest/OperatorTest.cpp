#include "pch.h"
#include "../ProjectCtream/Operator.cpp"

class OperatorTest : public ::testing::Test
{
public:
	OperatorTest() {
    }
    ~OperatorTest() {
    }
protected:
    virtual void SetUp() override
    {
		operatorManager = new OperatorManager{ &dataBase, &columnMap };

		columnMap.resize(MAX_COLUMNTYPE);
		vector<Employee> eInfo;
		eInfo.push_back({ "15123099",{"VXIHXOTH","JHOP"},"CL3",{"3112","2609"},{"1977","12","11"},"ADV" });
		eInfo.push_back({ "17112609",{"FB","NTAWR"},"CL4",{"5645","6122"},{"1986","12","03"},"PRO" });
		eInfo.push_back({ "16119968",{"FB","NTAWR"},"CL2",{"5644","6121"},{"1992","04","28"},"PRO" });

		for (auto employee : eInfo) {
			dataBase[employee.employeeNum] = employee;
		}

		(columnMap)[NAME].insert(make_pair("VXIHXOTH JHOP", "15123099"));
		(columnMap)[CL].insert(make_pair("CL3", "15123099"));
		(columnMap)[PHONENUM].insert(make_pair("010-3112-2609", "15123099"));
		(columnMap)[BIRTHDAY].insert(make_pair("19771211", "15123099"));
		(columnMap)[CERTI].insert(make_pair("ADV", "15123099"));
		(columnMap)[NAME_FIRST].insert(make_pair("VXIHXOTH", "15123099"));
		(columnMap)[NAME_LAST].insert(make_pair("JHOP", "15123099"));
		(columnMap)[PHONENUM_MIDDLE].insert(make_pair("3112", "15123099"));
		(columnMap)[PHONENUM_BACK].insert(make_pair("2609", "15123099"));
		(columnMap)[BIRTHDAY_YEAR].insert(make_pair("1977", "15123099"));
		(columnMap)[BIRTHDAY_MONTH].insert(make_pair("12", "15123099"));
		(columnMap)[BIRTHDAY_DATE].insert(make_pair("11", "15123099"));

		(columnMap)[NAME].insert(make_pair("FB NTAWR", "17112609"));
		(columnMap)[CL].insert(make_pair("CL4", "16119968"));
		(columnMap)[PHONENUM].insert(make_pair("010-5645-6122", "16119968"));
		(columnMap)[BIRTHDAY].insert(make_pair("19861203", "16119968"));
		(columnMap)[CERTI].insert(make_pair("PRO", "16119968"));
		(columnMap)[NAME_FIRST].insert(make_pair("FB", "16119968"));
		(columnMap)[NAME_LAST].insert(make_pair("NTAWR", "16119968"));
		(columnMap)[PHONENUM_MIDDLE].insert(make_pair("5645", "16119968"));
		(columnMap)[PHONENUM_BACK].insert(make_pair("6122", "16119968"));
		(columnMap)[BIRTHDAY_YEAR].insert(make_pair("1986", "16119968"));
		(columnMap)[BIRTHDAY_MONTH].insert(make_pair("12", "16119968"));
		(columnMap)[BIRTHDAY_DATE].insert(make_pair("03", "16119968"));

		(columnMap)[NAME].insert(make_pair("FB NTAWR", "16119968"));
		(columnMap)[CL].insert(make_pair("CL2", "16119968"));
		(columnMap)[PHONENUM].insert(make_pair("010-5644-6121", "16119968"));
		(columnMap)[BIRTHDAY].insert(make_pair("19920428", "16119968"));
		(columnMap)[CERTI].insert(make_pair("PRO", "16119968"));
		(columnMap)[NAME_FIRST].insert(make_pair("FB", "16119968"));
		(columnMap)[NAME_LAST].insert(make_pair("NTAWR", "16119968"));
		(columnMap)[PHONENUM_MIDDLE].insert(make_pair("5644", "16119968"));
		(columnMap)[PHONENUM_BACK].insert(make_pair("6121", "16119968"));
		(columnMap)[BIRTHDAY_YEAR].insert(make_pair("1986", "16119968"));
		(columnMap)[BIRTHDAY_MONTH].insert(make_pair("04", "16119968"));
		(columnMap)[BIRTHDAY_DATE].insert(make_pair("28", "16119968"));
    }

    virtual void TearDown() override
    {
        dataBase.clear();
    }

protected:
	vector<string> searchQ;

	map<string, Employee> dataBase;
	vector<multimap<string, string>> columnMap;

	OperatorManager* operatorManager;
};

TEST_F(OperatorTest, ModTest) {
	Operator* modOperator = operatorManager->getOperator(MOD);

	/* cmd : MOD, -p, , , name, FB NTAWR, birthday, 20050520 */
	searchQ.clear();
    searchQ.push_back("17112609");
	searchQ.push_back("16119968");

	string answer = "16119968,FB NTAWR,CL2,010-5644-6121,19920428,EXP\n17112609,FB NTAWR,CL4,010-5645-6122,19861203,EXP";
	ModCmd changeInfo;
	changeInfo.condType = CERTI;
	changeInfo.cond = "EXP";

	modOperator->operate(searchQ, &changeInfo);

	string result = "";
	auto i = 0;
	for (auto record : dataBase) {

		if(record.second.name.firstName == "FB" && record.second.name.lastName == "NTAWR"){
			if (i > 0) {
				result += "\n";
			}
			result += (record.second.employeeNum + "," + record.second.name.firstName + " " + record.second.name.lastName + "," + record.second.cl + ",010-"
				+ record.second.phoneNum.middle + "-" + record.second.phoneNum.last + "," + record.second.bday.year + record.second.bday.month
				+ record.second.bday.day + "," + record.second.certi);
			i++;
		}
	}

	EXPECT_TRUE(answer == result);

	///* 예외 확인 */
	//searchQ.clear();
	//searchQ.push_back("15123099");
	//changeInfo.col3 = "cll";
	//changeInfo.col4 = "CL3";
	//EXPECT_THROW(modOperator->operate(searchQ, changeInfo), invalid_argument);

	//searchQ.clear();
	//searchQ.push_back("15123099");
	//changeInfo.col3 = "employeeNum";
	//changeInfo.col4 = "75249568";
	//EXPECT_THROW(modOperator->operate(searchQ, changeInfo), invalid_argument);
}

TEST_F(OperatorTest, AddTest) {

	Operator* addOperator = operatorManager->getOperator(ADD);

	/* ADD, , , ,19129568,SRERLALH HMEF,CL2,010-3091-9521,19640910,PRO */
	string answer = "19129568,SRERLALH HMEF,CL2,010-3091-9521,19640910,PRO";
	Employee changeInfo;
	changeInfo.employeeNum = "19129568";
	changeInfo.name.firstName = "SRERLALH";
	changeInfo.name.lastName = "HMEF";
	changeInfo.cl = "CL2";
	changeInfo.phoneNum.middle = "3091"; 
	changeInfo.phoneNum.last = "9521";
	changeInfo.bday.year = "1964";
	changeInfo.bday.month = "09";
	changeInfo.bday.day = "10";
	changeInfo.certi = "PRO";

	addOperator->operate(searchQ, &changeInfo);

	string result;
	auto i = 0;
	for (auto record : dataBase) {

		if (record.second.name.firstName == "SRERLALH" && record.second.name.lastName == "HMEF") {
			if (i > 0) {
				result += "\n";
			}
			result += (record.second.employeeNum + "," + record.second.name.firstName + " " + record.second.name.lastName + "," + record.second.cl + ",010-"
				+ record.second.phoneNum.middle + "-" + record.second.phoneNum.last + "," + record.second.bday.year + record.second.bday.month
				+ record.second.bday.day + "," + record.second.certi);
			i++;
		}
	}

	EXPECT_TRUE(answer == result);
}

TEST_F(OperatorTest, DelFunc) {

	Operator* delOperator = operatorManager->getOperator(DEL);
	/* cmd : del, , , , name, FB NTAWR */
	searchQ.clear();
	searchQ.push_back("17112609");
	searchQ.push_back("16119968");

	SchCmd changeInfo;
	delOperator->operate(searchQ, &changeInfo);
	bool bResult = true;
	
	for (auto record : dataBase) {
		if (record.second.name.firstName == "FB" && record.second.name.lastName == "NTAWR") {
			bResult = false;
			break;
		}
	}

	EXPECT_TRUE(bResult);
}