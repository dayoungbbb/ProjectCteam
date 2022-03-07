#include "pch.h"
#include "../ProjectCtream/Printer.cpp"
#include <vector>

class PrinterTest : public ::testing::Test
{
public:
    PrinterTest() {
    }
    ~PrinterTest() {
    }
protected:
    virtual void SetUp() override
    {
        dataBase.push_back({ "13013973", "Wooyeon", "Kim", "CL3", "4600", "0297", "1988", "01", "27", "PRO" });
        dataBase.push_back({ "99765451", "Test1", "Kim", "CL4", "3333", "4444", "1980", "03", "01", "EXP" });
        dataBase.push_back({ "18001234", "JY", "Kim", "CL2",  "7777", "8888", "1999", "06", "02", "PRO" });
        dataBase.push_back({ "98123456", "BJ", "Park", "CL1", "1234", "5678", "2000", "07", "01", "PRO" });
        dataBase.push_back({ "11765432", "JY", "Kim", "CL3",  "8769", "1234", "1983", "05", "02", "ADV" });
        dataBase.push_back({ "07123456", "TY", "Park", "CL4", "7777", "5544", "1977", "08", "09", "EXP" });
        dataBase.push_back({ "21330234", "JY", "Park", "CL1", "2233", "4456", "2003", "05", "10", "EXP" });
    }

    virtual void TearDown() override
    {
        dataBase.clear();
    }

    unsigned long long getOutputFileCheckSum(std::string fileName) {
        ifstream outputFile;
        outputFile.open(fileName);
        if (outputFile.fail()) {
            throw invalid_argument("file open failed");
        }

        unsigned long long checkSum = 0;
        char c;
        while (outputFile.get(c)) {
            if (c == '\n') continue;
            checkSum += static_cast<unsigned long long>(c);
        }
        outputFile.close();

        return checkSum;
    }

protected:
    // variables
    prioirtyQ priorityQ;
    Printer printer;
    std::list<Employee> dataBase;
};


TEST_F(PrinterTest, printTest) {
    std::list<Employee>::iterator iter = dataBase.begin();
    priorityQ.push(iter);
    priorityQ.push(++iter);
    priorityQ.push(++iter);

    bool isFirst = true;
    printer.setOutputFileName("output_PrinterTest.txt");
    printer.print(MOD, " ", priorityQ, isFirst);

    EXPECT_EQ(getOutputFileCheckSum("output_PrinterTest.txt"), getOutputFileCheckSum("golden_PrinterTest_1.txt"));

    priorityQ.push(++iter);
    priorityQ.push(++iter);
    priorityQ.push(++iter);
    priorityQ.push(++iter);
    SchCmd schCmd = { PRINT, BLANK, NAME, "DSF FDF" };
    printer.print(DEL, &schCmd, priorityQ, isFirst);

    EXPECT_EQ(getOutputFileCheckSum("output_PrinterTest.txt"), getOutputFileCheckSum("golden_PrinterTest_2.txt"));
}
