#include "pch.h"
#include "../ProjectCtream/add.cpp"

TEST(ParseTest, parseTest) {
    vector<string> parseStr = split(string("ADD, , , ,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,PRO"), ',');
    Parser parser = getParser(parseStr);
    EXPECT_EQ(parser.col1, "18050301");
    EXPECT_EQ(parser.col2, "KYUMOK KIM");
    EXPECT_EQ(parser.col3, "CL2");
    EXPECT_EQ(parser.col4, "010-9777-6055");
    EXPECT_EQ(parser.col5, "19980906");
    EXPECT_EQ(parser.col6, "PRO");
}

TEST(AddTest, addTest) {
    vector<string> parseStr = split(string("ADD, , , ,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,PRO"), ',');
    Parser parser = getParser(parseStr);
    add(parser);
    Employee test = dataBase.back();
    EXPECT_EQ("CL2", test.cl);
    EXPECT_EQ("PRO", test.certi);
    EXPECT_EQ("18050301", test.employeeNum);
    EXPECT_EQ("KYUMOK", test.firstName);
    EXPECT_EQ("KIM", test.lastName);
    EXPECT_EQ("9777", test.middleOfPhoneNum);
    EXPECT_EQ("6055", test.backOfPhoneNum);
    EXPECT_EQ("1998", test.yearOfBday);
    EXPECT_EQ("09", test.monthOfBday);
    EXPECT_EQ("06", test.dateOfBday);
}