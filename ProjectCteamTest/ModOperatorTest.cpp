#include "pch.h"
#include "../ProjectCtream/ModOperator.cpp"

TEST(TestCaseName, ModFunc) {
	dataBase.push_back({ "15123099","VXIHXOTH","JHOP","CL3","3112","2609","1977","12","11","ADV" });
	dataBase.push_back({ "17112609","FB","NTAWR","CL4","5645","6122","1986","12","03","PRO" });

	Employee conditionInfo, changeInfo;
	/* -p 옵션 확인 : 1줄
	* cmd : MOD, -p, , , name, FB NTAWR, birthday, 20050520 */
	string answer = "MOD,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO";
	conditionInfo.firstName = "FB";
	conditionInfo.lastName = "NTAWR";
	changeInfo.yearOfBday = "2005";
	changeInfo.monthOfBday = "05";
	changeInfo.dateOfBday = "20";
	EXPECT_TRUE(answer == Mod("-p", " ", " ", "name", conditionInfo, "birthday", changeInfo));

	/* -p 옵션 확인 : 2줄(오름차순)
	* cmd : MOD, , , , name, FB NTAWR, birthday, 20050520 */
	answer = "MOD,16119968,FB NTAWR,CL2,010-5644-6121,19920428,PRO\nMOD,17112609,FB NTAWR,CL4,010-5645-6122,20050520,PRO";
	dataBase.push_back({ "16119968","FB","NTAWR","CL2","5644","6121","1992","04","28","PRO" });
	changeInfo.certi = CertiLevel::EXP;
	string result = Mod("-p", " ", " ", "name", conditionInfo, "certi", changeInfo);
	EXPECT_TRUE(answer == result);

	/* 옵션 없을 때
	* cmd : MOD, , , ,phoneNum,010-3112-2609,cl,CL4 */
	answer = "MOD,1";
	conditionInfo.middleOfPhoneNum = "3112";
	conditionInfo.backOfPhoneNum = "2609";
	changeInfo.cl = CareerLevel::CL4;
	EXPECT_TRUE(answer == Mod(" ", " ", " ", "phoneNum", conditionInfo, "cl", changeInfo));

	/* 조건에 해당하는 record가 없을 때
	* cmd : MOD, , , ,phoneNum,010-3111-2609,cl,CL4 */
	answer = "MOD,NONE";
	conditionInfo.middleOfPhoneNum = "3111";
	conditionInfo.backOfPhoneNum = "2609";
	changeInfo.cl = CareerLevel::CL4;
	EXPECT_TRUE(answer == Mod(" ", " ", " ", "phoneNum", conditionInfo, "cl", changeInfo));
	EXPECT_TRUE(answer == Mod("-p", " ", " ", "phoneNum", conditionInfo, "cl", changeInfo));

	//예외 확인
	EXPECT_THROW({
		Mod(" ", " ", " ", "phoneNuem", conditionInfo, "cl", changeInfo);
		Mod(" ", " ", " ", "phoneNum", conditionInfo, "cl333", changeInfo);
		}, invalid_argument);
}