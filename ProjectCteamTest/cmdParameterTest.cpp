#include "pch.h"
#include "../ProjectCtream/cmdParameter.cpp"

TEST(CmdParameterTest, addTest) {
    CmdParameter* cmdParameter = new CmdParameter();
    int isValid = cmdParameter->parse(string("ADD, , , ,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,PRO"));
    Employee* employee = (Employee*)cmdParameter->getCmdString();
    EXPECT_EQ(true, isValid);
    EXPECT_EQ(employee->employeeNum, "18050301");
    EXPECT_EQ(employee->name.firstName + " " + employee->name.lastName, "KYUMOK KIM");
    EXPECT_EQ(employee->cl, "CL2");
    EXPECT_EQ("010-" + employee->phoneNum.middle + "-" + employee->phoneNum.last, "010-9777-6055");
    EXPECT_EQ(employee->bday.year + employee->bday.month + employee->bday.day, "19980906");
    EXPECT_EQ(employee->certi, "PRO");
    delete cmdParameter;
}
TEST(CmdParameterTest, delTest) {
    CmdParameter* cmdParameter = new CmdParameter();
    int isValid = cmdParameter->parse(string("DEL, , , ,name,KYUMOK KIM"));
    SchCmd* schCmd = (SchCmd*)cmdParameter->getCmdString();
    EXPECT_EQ(true, isValid);
    EXPECT_EQ(schCmd->firstOptionType, BLANK);
    EXPECT_EQ(schCmd->secondOptionType, BLANK);
    EXPECT_EQ(schCmd->condType, NAME);
    EXPECT_EQ(schCmd->cond, "KYUMOK KIM");
    delete cmdParameter;
}

TEST(CmdParameterTest, modTest) {
    CmdParameter* cmdParameter = new CmdParameter();
    int isValid = cmdParameter->parse(string("MOD,-p, , ,name,KYUMOK KIM,cl,CL3"));
    ModCmd* modCmd = (ModCmd*)cmdParameter->getCmdString();
    EXPECT_EQ(true, isValid);
    EXPECT_EQ(modCmd->schCmd.firstOptionType, PRINT);
    EXPECT_EQ(modCmd->schCmd.secondOptionType, BLANK);
    EXPECT_EQ(modCmd->schCmd.condType, NAME);
    EXPECT_EQ(modCmd->schCmd.cond, "KYUMOK KIM");
    EXPECT_EQ(modCmd->condType, CL);
    EXPECT_EQ(modCmd->cond, "CL3");
    delete cmdParameter;
}

TEST(CmdParameterTest, schTest) {
    CmdParameter* cmdParameter = new CmdParameter();
    int isValid = cmdParameter->parse(string("SCH, , , ,name,KYUMOK KIM"));
    SchCmd* schCmd = (SchCmd*)cmdParameter->getCmdString();
    EXPECT_EQ(true, isValid);
    EXPECT_EQ(schCmd->firstOptionType, BLANK);
    EXPECT_EQ(schCmd->secondOptionType, BLANK);
    EXPECT_EQ(schCmd->condType, NAME);
    EXPECT_EQ(schCmd->cond, "KYUMOK KIM");
    delete cmdParameter;
}

TEST(CmdParameterTest, invalidTest) {
    CmdParameter* cmdParameter = new CmdParameter();
    int isValid = cmdParameter->parse(string("TDD, , , ,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,PRO"));
    EXPECT_EQ(false, isValid);
    delete cmdParameter;
}