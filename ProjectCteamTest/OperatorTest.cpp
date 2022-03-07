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
	prioirtyQ searchQ;
	OperatorManager* operatorManager;
};

TEST_F(OperatorTest, ModTest) {
	Operator* modOperator = operatorManager->getOperator(MOD);
	std::list<Employee>::iterator iter = dataBase.begin();
	/* cmd : MOD, -p, , , name, FB NTAWR, birthday, 20050520 */
	searchQ.push(++iter);
	searchQ.push(++iter);

	string answer = "17112609,FB NTAWR,CL4,010-5645-6122,19861203,EXP\n16119968,FB NTAWR,CL2,010-5644-6121,19920428,EXP";
	ModCmd changeInfo;
	changeInfo.condType = CERTI;
	changeInfo.cond = "EXP";

	modOperator->operate(searchQ, &changeInfo);

	string result = "";
	auto i = 0;
	for (auto record : dataBase) {

		if (record.name.firstName == "FB" && record.name.lastName == "NTAWR") {
			if (i > 0) {
				result += "\n";
			}
			result += (record.employeeNum + "," + record.name.firstName + " " + record.name.lastName + "," + record.cl + ",010-"
				+ record.phoneNum.middle + "-" + record.phoneNum.last + "," + record.bday.year + record.bday.month
				+ record.bday.day + "," + record.certi);
			i++;
		}
	}

	EXPECT_TRUE(answer == result);
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

		if (record.name.firstName == "SRERLALH" && record.name.lastName == "HMEF") {
			if (i > 0) {
				result += "\n";
			}
			result += (record.employeeNum + "," + record.name.firstName + " " + record.name.lastName + "," + record.cl + ",010-"
				+ record.phoneNum.middle + "-" + record.phoneNum.last + "," + record.bday.year + record.bday.month
				+ record.bday.day + "," + record.certi);
			i++;
		}
	}

	EXPECT_TRUE(answer == result);
}

TEST_F(OperatorTest, DelFunc) {
	std::list<Employee>::iterator iter = dataBase.begin();
	Operator* delOperator = operatorManager->getOperator(DEL);
	/* cmd : del, , , , name, FB NTAWR */
	searchQ.push(++iter);
	searchQ.push(++iter);

	SchCmd changeInfo;
	delOperator->operate(searchQ, &changeInfo);

	EXPECT_TRUE(searchQ.empty());
}
