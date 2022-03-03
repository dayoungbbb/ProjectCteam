#include "pch.h"
#include "../ProjectCtream/DelOperator.cpp"
#include <vector>

class DelOperatorTest : public ::testing::Test
{
public:
    DelOperatorTest() {
    }
    ~DelOperatorTest() {
    }
protected:
    virtual void SetUp() override
    {
        dataBase.push_back({ "13013973", "Kim", "Wooyeon", "CL3", "4600", "0297", "1988", "01", "27", "PRO"});
        dataBase.push_back({ "98123456", "Kim", "Test1", "CL4", "3333", "4444", "1980", "03", "01", "EXP"});
        dataBase.push_back({ "18001234", "Kim", "JY", "CL2",  "7777", "8888", "1999", "06", "02", "PRO"});
        dataBase.push_back({ "98123456", "Park","BJ",  "CL1", "1234", "5678", "2000", "07", "01", "PRO"});
        dataBase.push_back({ "11765432", "Kim", "JY", "CL3",  "8769", "1234", "1983", "05", "02", "ADV"});
        dataBase.push_back({ "98123456", "Park","TY",  "CL4", "7777", "5544", "1977", "08", "09", "EXP"});
        dataBase.push_back({ "21330234", "Park","JY",  "CL1", "2233", "4456", "2003", "05", "10", "EXP"});
    }

    virtual void TearDown() override
    {
        dataBase.clear();
    }

protected:
    // variables
};

// TODO: -p option
TEST_F(DelOperatorTest, nameColumnTest) {
    std::string column = "name";
    EXPECT_EQ("DEL,1", del(" ", " ", column, "Wooyeon Kim"));
    EXPECT_EQ("DEL,NONE", del(" ", " ", column, "Not Exist Name"));

    EXPECT_EQ("DEL,3", del(" ", "-f", column, "Park"));
}

TEST_F(DelOperatorTest, clColumnTest) {
    std::string column = "cl";
    EXPECT_EQ("DEL,1", del(" ", " ", column, "CL2"));
    EXPECT_EQ("DEL,NONE", del(" ", " ", column, "CL2"));
    EXPECT_EQ("DEL,2", del(" ", " ", column, "CL4"));
}

TEST_F(DelOperatorTest, phoneNumColumnTest) {
    std::string column = "phoneNum";
    EXPECT_EQ("DEL,1", del(" ", " ", column, "010-4600-0297"));
    EXPECT_EQ("DEL,2", del(" ", "-m", column, "7777"));
    EXPECT_EQ("DEL,NONE", del(" ", "-m", column, "7777"));
    EXPECT_EQ("DEL,NONE", del(" ", "-l", column, "8888"));
    EXPECT_EQ("DEL,1", del(" ", "-l", column, "1234"));
}

TEST_F(DelOperatorTest, birthDayColumnTest) {
    std::string column = "birthDay";
    EXPECT_EQ("DEL,1", del(" ", " ", column, "19880127"));
    EXPECT_EQ("DEL,1", del(" ", "-y", column, "2000"));
    EXPECT_EQ("DEL,2", del(" ", "-m", column, "05"));
    EXPECT_EQ("DEL,1", del(" ", "-d", column, "02"));
    EXPECT_EQ("DEL,NONE", del(" ", "-d", column, "27"));
}

TEST_F(DelOperatorTest, employeeNumColumnTest) {
    std::string column = "employeeNum";
    EXPECT_EQ("DEL,1", del(" ", " ", column, "13013973"));
    EXPECT_EQ("DEL,NONE", del(" ", " ", column, "22330234"));
}

TEST_F(DelOperatorTest, certiColumnTest) {
    std::string column = "certi";
    EXPECT_EQ("DEL,3", del(" ", " ", column, "PRO"));
    EXPECT_EQ("DEL,1", del(" ", " ", column, "ADV"));
    EXPECT_EQ("DEL,NONE", del(" ", " ", column, "PRO"));
    EXPECT_EQ("DEL,3", del(" ", " ", column, "EXP"));
}