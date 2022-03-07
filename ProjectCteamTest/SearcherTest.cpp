#include "pch.h"
#include "../ProjectCtream/Searcher.cpp"

#if 0
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
	const CmdString cmdString = { "", "", "name","VXIHXOTH JHOP", "","","","" };
	Searcher* searcher = searcherManager->getSearcher(cmdString);
	prioirtyQ iter = searcher->search(cmdString);
	EXPECT_EQ("15123099", iter.top()->employeeNum);
}
TEST_F(SearcherTest, nameOptionLSearchTest) {
	const CmdString cmdString = { "", "-l", "name","NTAWR", "","","","" };
	Searcher* searcher = searcherManager->getSearcher(cmdString);
	prioirtyQ iter = searcher->search(cmdString);
	string result;
	if (!iter.empty())
		result = iter.top()->employeeNum;
	EXPECT_EQ("60112609", result);
}
TEST_F(SearcherTest, nameOptionFSearchTest) {
	const CmdString cmdString = { "", "-f", "name","FB", "","","","" };
	Searcher* searcher = searcherManager->getSearcher(cmdString);
	prioirtyQ iter = searcher->search(cmdString);
	string result;
	if (!iter.empty())
		result = iter.top()->employeeNum;
	EXPECT_EQ("60112609", result);
}

TEST_F(SearcherTest, phoneNumOptionLSearchTest) {
	const CmdString cmdString = { "", "-m", "phoneNum","5645", "","","","" };
	Searcher* searcher = searcherManager->getSearcher(cmdString);
	prioirtyQ iter = searcher->search(cmdString);	string result;
	if (!iter.empty())
		result = iter.top()->employeeNum;
	EXPECT_EQ("60112609", result);
}
TEST_F(SearcherTest, phoneNumOptionFSearchTest) {
	const CmdString cmdString = { "", "-l", "phoneNum","6122", "","","","" };
	Searcher* searcher = searcherManager->getSearcher(cmdString);
	prioirtyQ iter = searcher->search(cmdString);	string result;
	if (!iter.empty())
		result = iter.top()->employeeNum;
	EXPECT_EQ("60112609", result);
}

TEST_F(SearcherTest, birthdayOptionYSearchTest) {
	const CmdString cmdString = { "", "-y", "birthday","1977", "","","","" };
	Searcher* searcher = searcherManager->getSearcher(cmdString);
	prioirtyQ iter = searcher->search(cmdString);	string result;
	if (!iter.empty())
		result = iter.top()->employeeNum;
	EXPECT_EQ("60112609", result);
}
TEST_F(SearcherTest, birthdayOptionMSearchTest) {
	const CmdString cmdString = { "", "-m", "birthday","12", "","","","" };
	Searcher* searcher = searcherManager->getSearcher(cmdString);
	prioirtyQ iter = searcher->search(cmdString);	string result;
	if (!iter.empty())
		result = iter.top()->employeeNum;
	EXPECT_EQ("60112609", result);
}

TEST_F(SearcherTest, birthdayOptionDSearchTest) {
	const CmdString cmdString = { "", "-d", "birthday","11", "","","","" };
	Searcher* searcher = searcherManager->getSearcher(cmdString);
	prioirtyQ iter = searcher->search(cmdString);	string result;
	if (!iter.empty())
		result = iter.top()->employeeNum;
	EXPECT_EQ("60112609", result);
}
#endif