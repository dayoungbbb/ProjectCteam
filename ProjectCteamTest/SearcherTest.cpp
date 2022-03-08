#include "pch.h"
#include "../ProjectCtream/Searcher.cpp"


#if 1
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
		searcherManager = new SearcherManager( &dataBase, &columnMap );
		dataBase.insert(make_pair("15123099", Employee{ "VXIHXOTH","JHOP","CL3","3112","2609","1977","12","11","ADV" }));
		dataBase.insert(make_pair("60112609", Employee{ "FB","NTAWR","CL4","5645","6122","1977","12","11","PRO" }));
		dataBase.insert(make_pair("16119968", Employee{ "FB","NTAWR","CL2","5645","6122","1992","04","28","PRO" }));

		columnMap.resize(MAX_COLUMNTYPE);

		(columnMap)[NAME].insert(make_pair("VXIHXOTH JHOP", "15123099"));
		(columnMap)[CL].insert(make_pair("CL3", "15123099"));
		(columnMap)[PHONENUM].insert(make_pair("010-3112-2609", "15123099"));
		(columnMap)[BIRTHDAY].insert(make_pair("19771211", "15123099"));
		(columnMap)[CERTI].insert(make_pair("ADV", "15123099"));
		(columnMap)[NAME_FIRST].insert(make_pair("VXIHXOTH", "15123099"));
		(columnMap)[NAME_LAST].insert(make_pair("JHOP", "15123099"));
		(columnMap)[PHONENUM_MIDDLE].insert(make_pair("3112", "15123099"));
		(columnMap)[PHONENUM_BACK].insert(make_pair("2609", "15123099"));
		(columnMap)[BIRTHDAY_YEAR].insert(make_pair("1977", "15123099"));
		(columnMap)[BIRTHDAY_MONTH].insert(make_pair("12", "15123099"));
		(columnMap)[BIRTHDAY_DATE].insert(make_pair("11", "15123099"));


		(columnMap)[NAME].insert(make_pair("FB NTAWR", "60112609"));
		(columnMap)[CL].insert(make_pair("CL4", "60112609"));
		(columnMap)[PHONENUM].insert(make_pair("010-5645-6122", "60112609"));
		(columnMap)[BIRTHDAY].insert(make_pair("19771211", "60112609"));
		(columnMap)[CERTI].insert(make_pair("PRO", "60112609"));
		(columnMap)[NAME_FIRST].insert(make_pair("FB", "60112609"));
		(columnMap)[NAME_LAST].insert(make_pair("NTAWR", "60112609"));
		(columnMap)[PHONENUM_MIDDLE].insert(make_pair("5645", "60112609"));
		(columnMap)[PHONENUM_BACK].insert(make_pair("6122", "60112609"));
		(columnMap)[BIRTHDAY_YEAR].insert(make_pair("1977", "60112609"));
		(columnMap)[BIRTHDAY_MONTH].insert(make_pair("12", "60112609"));
		(columnMap)[BIRTHDAY_DATE].insert(make_pair("11", "60112609"));


		(columnMap)[NAME].insert(make_pair("FB NTAWR", "16119968"));
		(columnMap)[CL].insert(make_pair("CL2", "16119968"));
		(columnMap)[PHONENUM].insert(make_pair("010-5645-6122", "16119968"));
		(columnMap)[BIRTHDAY].insert(make_pair("19920428", "16119968"));
		(columnMap)[CERTI].insert(make_pair("PRO", "16119968"));
		(columnMap)[NAME_FIRST].insert(make_pair("FB", "16119968"));
		(columnMap)[NAME_LAST].insert(make_pair("NTAWR", "16119968"));
		(columnMap)[PHONENUM_MIDDLE].insert(make_pair("5645", "16119968"));
		(columnMap)[PHONENUM_BACK].insert(make_pair("6122", "16119968"));
		(columnMap)[BIRTHDAY_YEAR].insert(make_pair("1922", "16119968"));
		(columnMap)[BIRTHDAY_MONTH].insert(make_pair("04", "16119968"));
		(columnMap)[BIRTHDAY_DATE].insert(make_pair("28", "16119968"));

	}

	virtual void TearDown() override
	{
		dataBase.clear();
	}

protected:
	SearcherManager* searcherManager;

	map<string, Employee> dataBase;
	vector<multimap<string, string>> columnMap;
};

TEST_F(SearcherTest, nameSearchTest) {
	const SchCmd cmdString = { DISABLE, NAME, "VXIHXOTH JHOP" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	vector<string> iter = searcher->search(&cmdString);
	EXPECT_EQ("15123099", iter[0]);
}
TEST_F(SearcherTest, nameOptionLSearchTest) {
	const SchCmd cmdString = { DISABLE, NAME_LAST, "NTAWR" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	vector<string> iter = searcher->search(&cmdString);
	EXPECT_EQ("60112609", iter[0]);
}
TEST_F(SearcherTest, nameOptionFSearchTest) {
	const SchCmd cmdString = { DISABLE, NAME_FIRST, "FB" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	vector<string> iter = searcher->search(&cmdString);
	EXPECT_EQ("60112609", iter[0]);
}

TEST_F(SearcherTest, phoneNumOptionLSearchTest) {
	const SchCmd cmdString = { DISABLE, PHONENUM_MIDDLE, "5645" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	vector<string> iter = searcher->search(&cmdString);
	EXPECT_EQ("60112609", iter[0]);
}
TEST_F(SearcherTest, phoneNumOptionFSearchTest) {
	const SchCmd cmdString = { DISABLE, PHONENUM_BACK, "6122" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	vector<string> iter = searcher->search(&cmdString);
	EXPECT_EQ("60112609", iter[0]);
}

TEST_F(SearcherTest, birthdayOptionYSearchTest) {
	const SchCmd cmdString = { DISABLE, BIRTHDAY_YEAR, "1977" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	vector<string> iter = searcher->search(&cmdString);
	EXPECT_EQ(2, iter.size());
}
TEST_F(SearcherTest, birthdayOptionMSearchTest) {
	const SchCmd cmdString = { DISABLE, BIRTHDAY_MONTH, "12" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	vector<string> iter = searcher->search(&cmdString);
	EXPECT_EQ(2, iter.size());
}

TEST_F(SearcherTest, birthdayOptionDSearchTest) {
	const SchCmd cmdString = { DISABLE, BIRTHDAY_DATE, "11" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	vector<string> iter = searcher->search(&cmdString);
	EXPECT_EQ(2, iter.size());
}
#endif