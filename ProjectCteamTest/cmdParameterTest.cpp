#include "pch.h"
#include "../ProjectCtream/cmdParameter.cpp"

TEST(CmdParameterTest, addTest) {
    CmdParameter *cmdParameter = new CmdParameter();
    int isValid = cmdParameter->parse(string("ADD, , , ,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,PRO"));
    EXPECT_EQ(true, isValid);
    EXPECT_EQ(cmdParameter->getCmdString().col1, "18050301");
    EXPECT_EQ(cmdParameter->getCmdString().col2, "KYUMOK KIM");
    EXPECT_EQ(cmdParameter->getCmdString().col3, "CL2");
    EXPECT_EQ(cmdParameter->getCmdString().col4, "010-9777-6055");
    EXPECT_EQ(cmdParameter->getCmdString().col5, "19980906");
    EXPECT_EQ(cmdParameter->getCmdString().col6, "PRO");
    delete cmdParameter;
}
TEST(CmdParameterTest, delTest) {
    CmdParameter* cmdParameter = new CmdParameter();
    int isValid = cmdParameter->parse(string("DEL, , , ,name,KYUMOK KIM"));
    EXPECT_EQ(true, isValid);
    EXPECT_EQ(cmdParameter->getCmdString().op1, " ");
    EXPECT_EQ(cmdParameter->getCmdString().op2, " ");
    EXPECT_EQ(cmdParameter->getCmdString().col1, "name");
    EXPECT_EQ(cmdParameter->getCmdString().col2, "KYUMOK KIM");
    delete cmdParameter;
}

TEST(CmdParameterTest, modTest) {
    CmdParameter* cmdParameter = new CmdParameter();
    int isValid = cmdParameter->parse(string("MOD,-p, , ,name,KYUMOK KIM,cl,CL3"));
    EXPECT_EQ(true, isValid);
    EXPECT_EQ(cmdParameter->getCmdString().op1, "-p");
    EXPECT_EQ(cmdParameter->getCmdString().op2, " ");
    EXPECT_EQ(cmdParameter->getCmdString().col1, "name");
    EXPECT_EQ(cmdParameter->getCmdString().col2, "KYUMOK KIM");
    EXPECT_EQ(cmdParameter->getCmdString().col3, "cl");
    EXPECT_EQ(cmdParameter->getCmdString().col4, "CL3");
    delete cmdParameter;
}

TEST(CmdParameterTest, schTest) {
    CmdParameter* cmdParameter = new CmdParameter();
    int isValid = cmdParameter->parse(string("SCH, , , ,name,KYUMOK KIM"));
    EXPECT_EQ(true, isValid);
    EXPECT_EQ(cmdParameter->getCmdString().op1, " ");
    EXPECT_EQ(cmdParameter->getCmdString().op2, " ");
    EXPECT_EQ(cmdParameter->getCmdString().col1, "name");
    EXPECT_EQ(cmdParameter->getCmdString().col2, "KYUMOK KIM");
    delete cmdParameter;
}

TEST(CmdParameterTest, invalidTest) {
    CmdParameter* cmdParameter = new CmdParameter();
    int isValid = cmdParameter->parse(string("TDD, , , ,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,PRO"));
    EXPECT_EQ(false, isValid);
    delete cmdParameter;
}