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
		searcherManager = new SearcherManager(&dataBase, &columnMap);
		dataBase.insert(make_pair("15123099", Employee{ "VXIHXOTH","JHOP","CL3","3112","2609","1977","12","11","ADV" }));
		dataBase.insert(make_pair("60112609", Employee{ "FB","NTAWR","CL4","5645","6122","1977","12","11","PRO" }));
		dataBase.insert(make_pair("16119968", Employee{ "FB","NTAWR","CL2","5645","6122","1992","04","28","PRO" }));

		columnMap.resize(MAX_COLUMNTYPE);

		(columnMap)[EMPLOYEENUM]["15123099"].insert("15123099");
		(columnMap)[NAME]["VXIHXOTH JHOP"].insert("15123099");
		(columnMap)[CL]["CL3"].insert("15123099");
		(columnMap)[PHONENUM]["010-3112-2609"].insert("15123099");
		(columnMap)[BIRTHDAY]["19771211"].insert("15123099");
		(columnMap)[CERTI]["ADV"].insert("15123099");
		(columnMap)[NAME_FIRST]["VXIHXOTH"].insert("15123099");
		(columnMap)[NAME_LAST]["JHOP"].insert("15123099");
		(columnMap)[PHONENUM_MIDDLE]["3112"].insert("15123099");
		(columnMap)[PHONENUM_BACK]["2609"].insert("15123099");
		(columnMap)[BIRTHDAY_YEAR]["1977"].insert("15123099");
		(columnMap)[BIRTHDAY_MONTH]["12"].insert("15123099");
		(columnMap)[BIRTHDAY_DATE]["11"].insert("15123099");

		(columnMap)[EMPLOYEENUM]["60112609"].insert("60112609");
		(columnMap)[NAME]["FB NTAWR"].insert("60112609");
		(columnMap)[CL]["CL4"].insert("60112609");
		(columnMap)[PHONENUM]["010-5645-6122"].insert("60112609");
		(columnMap)[BIRTHDAY]["19771211"].insert("60112609");
		(columnMap)[CERTI]["PRO"].insert("60112609");
		(columnMap)[NAME_FIRST]["FB"].insert("60112609");
		(columnMap)[NAME_LAST]["NTAWR"].insert("60112609");
		(columnMap)[PHONENUM_MIDDLE]["5645"].insert("60112609");
		(columnMap)[PHONENUM_BACK]["6122"].insert("60112609");
		(columnMap)[BIRTHDAY_YEAR]["1977"].insert("60112609");
		(columnMap)[BIRTHDAY_MONTH]["12"].insert("60112609");
		(columnMap)[BIRTHDAY_DATE]["11"].insert("60112609");

		(columnMap)[EMPLOYEENUM]["16119968"].insert("16119968");
		(columnMap)[NAME]["FB NTAWR"].insert("16119968");
		(columnMap)[CL]["CL2"].insert("16119968");
		(columnMap)[PHONENUM]["010-5645-6122"].insert("16119968");
		(columnMap)[BIRTHDAY]["19920428"].insert("16119968");
		(columnMap)[CERTI]["PRO"].insert("16119968");
		(columnMap)[NAME_FIRST]["FB"].insert("16119968");
		(columnMap)[NAME_LAST]["NTAWR"].insert("16119968");
		(columnMap)[PHONENUM_MIDDLE]["5645"].insert("16119968");
		(columnMap)[PHONENUM_BACK]["6122"].insert("16119968");
		(columnMap)[BIRTHDAY_YEAR]["1992"].insert("16119968");
		(columnMap)[BIRTHDAY_MONTH]["04"].insert("16119968");
		(columnMap)[BIRTHDAY_DATE]["28"].insert("16119968");
	}

	virtual void TearDown() override
	{
		dataBase.clear();
	}

protected:
	SearcherManager* searcherManager;

	map<string, Employee> dataBase;
	vector<map<string, unordered_set<string>>> columnMap;
};

TEST_F(SearcherTest, nameSearchTest) {
	const SchCmd cmdString = { DISABLE, NAME, "VXIHXOTH JHOP" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	unordered_set<string> employNumSet;
	searcher->search(employNumSet, &cmdString);

	auto iter = employNumSet.find("15123099");
	EXPECT_EQ("15123099", *iter);
}
TEST_F(SearcherTest, nameOptionLSearchTest) {
	const SchCmd cmdString = { DISABLE, NAME_LAST, "NTAWR" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	unordered_set<string> employNumSet;
	searcher->search(employNumSet, &cmdString);

	auto iter = employNumSet.find("60112609");
	EXPECT_EQ("60112609", *iter);
}

TEST_F(SearcherTest, nameOptionFSearchTest) {
	const SchCmd cmdString = { DISABLE, NAME_FIRST, "FB" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	unordered_set<string> employNumSet;
	searcher->search(employNumSet, &cmdString);

	auto iter = employNumSet.find("60112609");
	EXPECT_EQ("60112609", *iter);
}

TEST_F(SearcherTest, phoneNumOptionLSearchTest) {
	const SchCmd cmdString = { DISABLE, PHONENUM_MIDDLE, "5645" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	unordered_set<string> employNumSet;
	searcher->search(employNumSet, &cmdString);

	auto iter = employNumSet.find("60112609");
	EXPECT_EQ("60112609", *iter);
}

TEST_F(SearcherTest, phoneNumOptionFSearchTest) {
	const SchCmd cmdString = { DISABLE, PHONENUM_BACK, "6122" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	unordered_set<string> employNumSet;
	searcher->search(employNumSet, &cmdString);

	auto iter = employNumSet.find("60112609");
	EXPECT_EQ("60112609", *iter);
}

TEST_F(SearcherTest, birthdayOptionYSearchTest) {
	const SchCmd cmdString = { DISABLE, BIRTHDAY_YEAR, "1977" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	unordered_set<string> employNumSet;
	searcher->search(employNumSet, &cmdString);

	EXPECT_EQ(2, employNumSet.size());
}

TEST_F(SearcherTest, birthdayOptionMSearchTest) {
	const SchCmd cmdString = { DISABLE, BIRTHDAY_MONTH, "12" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	unordered_set<string> employNumSet;
	searcher->search(employNumSet, &cmdString);

	EXPECT_EQ(2, employNumSet.size());
}

TEST_F(SearcherTest, birthdayOptionDSearchTest) {
	const SchCmd cmdString = { DISABLE, BIRTHDAY_DATE, "11" };
	Searcher* searcher = searcherManager->getSearcher(&cmdString);
	unordered_set<string> employNumSet;
	searcher->search(employNumSet, &cmdString);

	EXPECT_EQ(2, employNumSet.size());
}