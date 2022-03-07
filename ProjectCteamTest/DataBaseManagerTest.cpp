#include "pch.h"
#include "../ProjectCtream/DataBaseManager.cpp"
#include "TestUtil.h"

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

protected:
    // variables
    DataBaseManager* dataBaseManager;
};

TEST_F(DataBaseManagerTest, operateTest) {
    dataBaseManager->operate("test_input.txt", "output_DataBaseManagerTest.txt");

    EXPECT_EQ(getOutputFileCheckSum("output_DataBaseManagerTest.txt"), getOutputFileCheckSum("golden_DataBaseManagerTest.txt"));
}