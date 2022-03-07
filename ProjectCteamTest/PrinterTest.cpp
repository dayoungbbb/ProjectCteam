#include "pch.h"
#include "../ProjectCtream/Printer.cpp"
#include <vector>
#include "TestUtil.h"

class PrinterTest : public ::testing::Test
{
public:
    PrinterTest() {
        printer = new Printer(dataBase);
    }
    ~PrinterTest() {
        delete printer;
        printer = nullptr;
    }
protected:
    virtual void SetUp() override
    {
        Employee employee[7] = {
            { "13013973", "Wooyeon", "Kim", "CL3", "4600", "0297", "1988", "01", "27", "PRO" },
            { "99765451", "Test1", "Kim", "CL4", "3333", "4444", "1980", "03", "01", "EXP" },
            { "18001234", "JY", "Kim", "CL2",  "7777", "8888", "1999", "06", "02", "PRO" },
            { "98123456", "BJ", "Park", "CL1", "1234", "5678", "2000", "07", "01", "PRO" },
            { "11765432", "JY", "Kim", "CL3",  "8769", "1234", "1983", "05", "02", "ADV" },
            { "07123456", "TY", "Park", "CL4", "7777", "5544", "1977", "08", "09", "EXP" },
            { "21330234", "JY", "Park", "CL1", "2233", "4456", "2003", "05", "10", "EXP" },
        };

        for (int i = 0; i < 7; i++) {
            dataBase.insert(make_pair(employee[i].employeeNum, employee[i]));
        }
    }

    virtual void TearDown() override
    {
        dataBase.clear();
    }

protected:
    // variables
    map<string, Employee> dataBase;
    vector<multimap<string, string>> columnMap;
    Printer *printer;
};

TEST_F(PrinterTest, printTest) {

    vector<string> searchList;

    searchList.push_back("13013973");
    searchList.push_back("99765451");
    searchList.push_back("18001234");

    bool isFirst = true;
    printer->setOutputFileName("output_PrinterTest.txt");
    printer->print(MOD, " ", searchList, isFirst);

    EXPECT_EQ(getOutputFileCheckSum("output_PrinterTest.txt"), getOutputFileCheckSum("golden_PrinterTest_1.txt"));

    searchList.push_back("98123456");
    searchList.push_back("11765432");
    searchList.push_back("07123456");
    searchList.push_back("21330234");
    SchCmd schCmd = {PRINT, NAME, "DSRC DSF"};
    printer->print(DEL, &schCmd, searchList, isFirst);

    EXPECT_EQ(getOutputFileCheckSum("output_PrinterTest.txt"), getOutputFileCheckSum("golden_PrinterTest_2.txt"));
}