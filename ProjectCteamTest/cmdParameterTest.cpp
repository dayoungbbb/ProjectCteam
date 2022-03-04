#include "pch.h"
#include "../ProjectCtream/cmdParameter.cpp"

TEST(CmdParameterTest, parseTest1) {
    CmdParameter *cmdParameter = new CmdParameter();
    int isValid = cmdParameter->parseCmdParameter(string("ADD, , , ,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,PRO"));
    EXPECT_EQ(true, isValid);
    EXPECT_EQ(cmdParameter->getCol1(), "18050301");
    EXPECT_EQ(cmdParameter->getCol2(), "KYUMOK KIM");
    EXPECT_EQ(cmdParameter->getCol3(), "CL2");
    EXPECT_EQ(cmdParameter->getCol4(), "010-9777-6055");
    EXPECT_EQ(cmdParameter->getCol5(), "19980906");
    EXPECT_EQ(cmdParameter->getCol6(), "PRO");
    delete cmdParameter;
}
TEST(CmdParameterTest, parseTest2) {
    CmdParameter* cmdParameter = new CmdParameter();
    int isValid = cmdParameter->parseCmdParameter(string("DEL, , , ,name,KYUMOK KIM"));
    EXPECT_EQ(true, isValid);
    EXPECT_EQ(cmdParameter->getOp1(), " ");
    EXPECT_EQ(cmdParameter->getOp2(), " ");
    EXPECT_EQ(cmdParameter->getCol1(), "name");
    EXPECT_EQ(cmdParameter->getCol2(), "KYUMOK KIM");
    delete cmdParameter;
}

TEST(CmdParameterTest, parseTest3) {
    CmdParameter* cmdParameter = new CmdParameter();
    int isValid = cmdParameter->parseCmdParameter(string("MOD,-p, , ,name,KYUMOK KIM,cl,CL3"));
    EXPECT_EQ(true, isValid);
    EXPECT_EQ(cmdParameter->getOp1(), "-p");
    EXPECT_EQ(cmdParameter->getOp2(), " ");
    EXPECT_EQ(cmdParameter->getCol1(), "name");
    EXPECT_EQ(cmdParameter->getCol2(), "KYUMOK KIM");
    EXPECT_EQ(cmdParameter->getCol3(), "cl");
    EXPECT_EQ(cmdParameter->getCol4(), "CL3");
    delete cmdParameter;
}

TEST(CmdParameterTest, parseTest4) {
    CmdParameter* cmdParameter = new CmdParameter();
    int isValid = cmdParameter->parseCmdParameter(string("SCH, , , ,name,KYUMOK KIM"));
    EXPECT_EQ(true, isValid);
    EXPECT_EQ(cmdParameter->getOp1(), " ");
    EXPECT_EQ(cmdParameter->getOp2(), " ");
    EXPECT_EQ(cmdParameter->getCol1(), "name");
    EXPECT_EQ(cmdParameter->getCol2(), "KYUMOK KIM");
    delete cmdParameter;
}

TEST(CmdParameterTest, parseTest5) {
    CmdParameter* cmdParameter = new CmdParameter();
    int isValid = cmdParameter->parseCmdParameter(string("TDD, , , ,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,PRO"));
    EXPECT_EQ(false, isValid);
    delete cmdParameter;
}