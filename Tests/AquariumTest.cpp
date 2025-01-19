/**
 * @file AquariumTest.cpp
 * @author Palina Skakun
 */
#include <pch.h>
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include "gtest/gtest.h"
#include <Aquarium.h>
#include <FishBeta.h>
#include <Nemo.h>
#include <DecorCastle.h>
#include <Dory.h>
#include <wx/filename.h>

using namespace std;

class AquariumTest : public ::testing::Test {
protected:
	/**
	* Create a path to a place to put temporary files
	*/
	wxString TempPath()
	{
		// Create a temporary filename we can use
		auto path = wxFileName::GetTempDir() + L"/aquarium";
		if(!wxFileName::DirExists(path))
		{
			wxFileName::Mkdir(path);
		}

		return path;
	}

	/**
	* Read a file into a wstring and return it.
	* @param filename Name of the file to read
	* @return File contents
	*/
	wstring ReadFile(const wxString &filename)
	{
		ifstream t(filename.ToStdString());
		wstring str((istreambuf_iterator<char>(t)),
					istreambuf_iterator<char>());

		return str;
	}

	/**
     * Test to ensure an aquarium .aqua file is empty
     */
	void TestEmpty(wxString filename)
	{
		cout << "Temp file: " << filename << endl;

		auto xml = ReadFile(filename);
		cout << xml << endl;
		ASSERT_TRUE(regex_search(xml, wregex(L"<\\?xml.*\\?>")));
		ASSERT_TRUE(regex_search(xml, wregex(L"<aqua/>")));

	}

	/**
     *  Populate an aquarium with three Beta fish
     */
	void PopulateThreeBetas(Aquarium *aquarium)
	{
		auto fish1 = make_shared<FishBeta>(aquarium);
		aquarium->Add(fish1);
		fish1->SetLocation(100, 200);

		auto fish2 = make_shared<FishBeta>(aquarium);
		aquarium->Add(fish2);
		fish2->SetLocation(400, 400);

		auto fish3 = make_shared<FishBeta>(aquarium);
		aquarium->Add(fish3);
		fish3->SetLocation(600, 100);
	}

	void PopulateAllTypes( Aquarium *aquarium)
	{
		auto fishOne = make_shared<FishBeta>(aquarium);
		aquarium->Add(fishOne);
		fishOne->SetLocation(100, 200);

		auto fishTwo = make_shared<Nemo>(aquarium);
		aquarium->Add(fishTwo);
		fishTwo->SetLocation(400, 400);

		auto fishThree = make_shared<Dory>(aquarium);
		aquarium->Add(fishThree);
		fishThree->SetLocation(600, 100);

		auto item = make_shared<DecorCastle>(aquarium);
		aquarium->Add(item);
		item->SetLocation(600, 600);

	}

	void TestThreeBetas(wxString filename)
	{
		cout << "Temp file: " << filename << endl;

		auto xml = ReadFile(filename);
		cout << xml << endl;

		// Ensure three items
		ASSERT_TRUE(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*</aqua>")));

		// Ensure the positions are correct
		ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\"")));
		ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\"")));
		ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\"")));

		// Ensure the types are correct
		ASSERT_TRUE(regex_search(xml,
								 wregex(L"<aqua><item.* type=\"beta\"/><item.* type=\"beta\"/><item.* type=\"beta\"/></aqua>")));
	}

	void TestAllTypes(wxString filename)
	{
		cout << "Temp file: " << filename << endl;

		auto xml = ReadFile(filename);
		cout << xml << endl;

		// Ensure three items
		ASSERT_TRUE(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*<item.*</aqua>")));

		// Ensure the positions are correct
		ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\"")));
		ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\"")));
		ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\"")));
		ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"600\" y=\"600\"")));

		// Ensure the types are correct
		ASSERT_TRUE(regex_search(xml,
								 wregex(L"<aqua><item.* type=\"beta\"/><item.* type=\"nemo\"/><item.* type=\"dory\"/><item.* type=\\\"castle\\\"/></aqua>")));

	}
};

TEST_F(AquariumTest, Construct){
	Aquarium aquarium;
}

TEST_F(AquariumTest, HitTest) {
	Aquarium aquarium;

	ASSERT_EQ(aquarium.HitTest(100, 200), nullptr) <<
												   L"Testing empty aquarium";

	shared_ptr<FishBeta> fish1 = make_shared<FishBeta>(&aquarium);
	aquarium.Add(fish1);
	fish1->SetLocation(100, 200);

	ASSERT_TRUE(aquarium.HitTest(100, 200) == fish1) <<
													 L"Testing fish at 100, 200";

	shared_ptr<FishBeta> fish2 = make_shared<FishBeta>(&aquarium);
	aquarium.Add(fish2);
	fish2->SetLocation(100, 200);

	// Since fish2 is added on top of fish1, hitting the same location should return fish2
	ASSERT_TRUE(aquarium.HitTest(100, 200) == fish2) <<
													 L"Testing fish on top at 100, 200";

	ASSERT_EQ(aquarium.HitTest(300, 400), nullptr) <<
												   L"Testing no fish at 300, 400";
}

TEST_F(AquariumTest, Save) {
	// Create a path to temporary files
	auto path = TempPath();

	// Create an aquarium
	Aquarium aquarium;

	//
	// First test, saving an empty aquarium
	//
	auto file1 = path + L"/test1.aqua";
	aquarium.Save(file1);

	TestEmpty(file1);

	//
	// Now populate the aquarium
	//

	PopulateThreeBetas(&aquarium);

	auto file2 = path + L"/test2.aqua";
	aquarium.Save(file2);

	TestThreeBetas(file2);

	//
	// Test all types
	//
	Aquarium aquarium3;
	PopulateAllTypes(&aquarium3);

	auto file3 = path + L"/test3.aqua";
	aquarium3.Save(file3);

	TestAllTypes(file3);

}

TEST_F(AquariumTest, Clear)
{
	Aquarium aquarium;

	// Populate aquarium
	PopulateAllTypes(&aquarium);

	aquarium.Clear();

	auto file_path = TempPath();
	auto file4 = file_path + L"/test4.aqua";
	aquarium.Save(file4);

	TestEmpty(file4);

}

TEST_F(AquariumTest, Load) {
	// Create a path to temporary files
	auto path = TempPath();

	// Create an aquarium
	Aquarium aquarium;
	Aquarium aquarium2;

	//
	// First test, saving an empty aquarium
	//
	auto file1 = path + L"/test1.aqua";
	aquarium.Save(file1);

	TestEmpty(file1);

	aquarium2.Load(file1);
	aquarium2.Save(file1);
	TestEmpty(file1);

	//
	// Now populate the aquarium
	//

	PopulateThreeBetas(&aquarium);

	auto file2 = path + L"/test2.aqua";
	aquarium.Save(file2);

	TestThreeBetas(file2);

	aquarium2.Load(file2);
	aquarium2.Save(file2);
	TestThreeBetas(file2);

	//
	// Test all types
	//
	Aquarium aquarium3;
	PopulateAllTypes(&aquarium3);

	auto file3 = path + L"/test3.aqua";
	aquarium3.Save(file3);

	TestAllTypes(file3);

	aquarium2.Load(file3);
	aquarium2.Save(file3);
	TestAllTypes(file3);
}


