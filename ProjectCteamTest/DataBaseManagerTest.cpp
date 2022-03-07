#include "pch.h"
#include "../ProjectCtream/DataBaseManager.cpp"
#include <vector>

#if 0
class DataBaseManagerTest : public ::testing::Test
{
public:
    DataBaseManagerTest() {
        dataBaseManager = new DataBaseManager;
    }
    ~DataBaseManagerTest() {
        delete dataBaseManager;
        dataBaseManager = nullptr;
    }
protected:
    virtual void SetUp() override
    {
    }

    virtual void TearDown() override
    {
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
    DataBaseManager* dataBaseManager;
};

TEST_F(DataBaseManagerTest, operateTest) {
    dataBaseManager->operate("test_input.txt", "output_DataBaseManagerTest.txt");

    EXPECT_EQ(getOutputFileCheckSum("output_DataBaseManagerTest.txt"), getOutputFileCheckSum("golden_DataBaseManagerTest.txt"));
}
#endif