#include "pch.h"
#include "../ProjectCtream/Searcher.cpp"

class SearcherTest : public ::testing::Test
{
public:
	SearcherTest() {
	}
	~SearcherTest() {
	}
protected:
	virtual void SetUp() override
	{
		searcherManager = new SearcherManager{ &dataBase };
		dataBase.push_back({ "15123099","VXIHXOTH","JHOP","CL3","3112","2609","1977","12","11","ADV" });
		dataBase.push_back({ "60112609","FB","NTAWR","CL4","5645","6122","1977","12","11","PRO" });
		dataBase.push_back({ "16119968","FB","NTAWR","CL2","5645","6122","1992","04","28","PRO" });
	}

	virtual void TearDown() override
	{
		dataBase.clear();
	}

protected:
	SearcherManager* searcherManager;
};

TEST_F(SearcherTest, nameSearchTest) {
	SchCmd cmdString = { BLANK, BLANK, NAME, "VXIHXOTH JHOP" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	prioirtyQ iter = searcher->search(&cmdString);
	EXPECT_EQ("15123099", iter.top()->employeeNum);
}
TEST_F(SearcherTest, nameOptionLSearchTest) {
	SchCmd cmdString = { BLANK, LAST_NAME, NAME,"NTAWR" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	prioirtyQ iter = searcher->search(&cmdString);
	string result;
	if (!iter.empty())
		result = iter.top()->employeeNum;
	EXPECT_EQ("60112609", result);
}
TEST_F(SearcherTest, nameOptionFSearchTest) {
	SchCmd cmdString = { BLANK, FIRST_NAME, NAME,"FB" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	prioirtyQ iter = searcher->search(&cmdString);
	string result;
	if (!iter.empty())
		result = iter.top()->employeeNum;
	EXPECT_EQ("60112609", result);
}

TEST_F(SearcherTest, phoneNumOptionLSearchTest) {
	SchCmd cmdString = { BLANK, MIDDLE_NUM, PHONENUM, "5645" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	prioirtyQ iter = searcher->search(&cmdString);	string result;
	if (!iter.empty())
		result = iter.top()->employeeNum;
	EXPECT_EQ("60112609", result);
}
TEST_F(SearcherTest, phoneNumOptionFSearchTest) {
	SchCmd cmdString = { BLANK, LAST_NUM, PHONENUM,"6122" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	prioirtyQ iter = searcher->search(&cmdString);	string result;
	if (!iter.empty())
		result = iter.top()->employeeNum;
	EXPECT_EQ("60112609", result);
}

TEST_F(SearcherTest, birthdayOptionYSearchTest) {
	SchCmd cmdString = { BLANK, YEAR, BIRTHDAY,"1977" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	prioirtyQ iter = searcher->search(&cmdString);	string result;
	if (!iter.empty())
		result = iter.top()->employeeNum;
	EXPECT_EQ("60112609", result);
}
TEST_F(SearcherTest, birthdayOptionMSearchTest) {
	SchCmd cmdString = { BLANK, MONTH, BIRTHDAY, "12" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	prioirtyQ iter = searcher->search(&cmdString);	string result;
	if (!iter.empty())
		result = iter.top()->employeeNum;
	EXPECT_EQ("60112609", result);
}

TEST_F(SearcherTest, birthdayOptionDSearchTest) {
	SchCmd cmdString = { BLANK, DAY, BIRTHDAY,"11" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	prioirtyQ iter = searcher->search(&cmdString);	string result;
	if (!iter.empty())
		result = iter.top()->employeeNum;
	EXPECT_EQ("60112609", result);
}