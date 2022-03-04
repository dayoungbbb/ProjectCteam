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
		operatorManager = new OperatorManager{ &dataBase };
		dataBase.push_back({ "15123099","VXIHXOTH","JHOP","CL3","3112","2609","1977","12","11","ADV" });
		dataBase.push_back({ "17112609","FB","NTAWR","CL4","5645","6122","1986","12","03","PRO" });
		dataBase.push_back({ "16119968","FB","NTAWR","CL2","5644","6121","1992","04","28","PRO" });
    }

    virtual void TearDown() override
    {
        dataBase.clear();
    }

protected:
	priority_queue<vector<Employee>::iterator> searchQ;
	OperatorManager* operatorManager;
};

TEST_F(OperatorTest, ModTest) {
	Operator* modOperator = operatorManager->getOperator(MOD);

	/* cmd : MOD, -p, , , name, FB NTAWR, birthday, 20050520 */
    searchQ.push(dataBase.begin() + 1);
    searchQ.push(dataBase.begin() + 2);

	string answer = "17112609,FB NTAWR,CL4,010-5645-6122,19861203,EXP\n16119968,FB NTAWR,CL2,010-5644-6121,19920428,EXP";
	CmdString changeInfo;
	changeInfo.col3 = "certi";
	changeInfo.col4 = "EXP";

	modOperator->operate(searchQ, changeInfo);

	string result = "";
	auto i = 0;
	for (auto record : dataBase) {

		if(record.firstName == "FB" && record.lastName == "NTAWR"){
			if (i > 0) {
				result += "\n";
			}
			result += (record.employeeNum + "," + record.firstName + " " + record.lastName + "," + record.cl + ",010-" 
				+ record.middleOfPhoneNum + "-" + record.backOfPhoneNum + "," + record.yearOfBday + record.monthOfBday
				+ record.dateOfBday + "," + record.certi);
			i++;
		}
	}

	EXPECT_TRUE(answer == result);

	//예외 확인
	searchQ.push(dataBase.begin());
	changeInfo.col3 = "cll";
	changeInfo.col4 = "CL3";
	EXPECT_THROW(modOperator->operate(searchQ, changeInfo), invalid_argument);
}

TEST_F(OperatorTest, AddTest) {

	Operator* addOperator = operatorManager->getOperator(ADD);

	/* ADD, , , ,19129568,SRERLALH HMEF,CL2,010-3091-9521,19640910,PRO */
	string answer = "19129568,SRERLALH HMEF,CL2,010-3091-9521,19640910,PRO";
	CmdString changeInfo;
	changeInfo.col1 = "19129568";
	changeInfo.col2 = "SRERLALH HMEF";
	changeInfo.col3 = "CL2";
	changeInfo.col4 = "010-3091-9521";
	changeInfo.col5 = "19640910";
	changeInfo.col6 = "PRO";

	addOperator->operate(searchQ, changeInfo);

	string result;
	auto i = 0;

	for (auto record : dataBase) {

		if (record.firstName == "SRERLALH" && record.lastName == "HMEF") {
			if (i > 0) {
				result += "\n";
			}
			result += (record.employeeNum + "," + record.firstName + " " + record.lastName + "," + record.cl + ",010-"
				+ record.middleOfPhoneNum + "-" + record.backOfPhoneNum + "," + record.yearOfBday + record.monthOfBday
				+ record.dateOfBday + "," + record.certi);
			i++;
		}
	}

	EXPECT_TRUE(answer == result);
}

TEST_F(OperatorTest, DelFunc) {

	Operator* delOperator = operatorManager->getOperator(DEL);
	/* cmd : del, , , , name, FB NTAWR */
	searchQ.push(dataBase.begin() + 1);
	searchQ.push(dataBase.begin() + 2);

	CmdString changeInfo;
	delOperator->operate(searchQ, changeInfo);

	EXPECT_TRUE(searchQ.empty());
}