#include "pch.h"
#include "CppUnitTest.h"

extern "C" int loadUser(char* username);
extern "C" void saveUser(char* username, int gamescore);
extern "C" int deleteData(char* username);
extern "C"  char* loadList(int choice);
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FILETEST001
{
	TEST_CLASS(FILETEST001)
	{
	public:
		
		TEST_METHOD(REQFM_001)
		{
//Cancelled test

		}
		TEST_METHOD(REQFM_002)
		{
//load user data test
			
			int score = 0;
			score = loadUser("max.txt");
			Assert::AreEqual(5, score);

		}
		TEST_METHOD(REQFM_003)
		{
//save user data test
			int score = 0;
			saveUser("max.txt", 5);
			score = loadUser("max.txt");
			Assert::AreEqual(5, score);
		}
		TEST_METHOD(REQFM_004)
		{
//load random word test
			char* word = loadList(1);
			Assert::IsNotNull(word);
		}
		TEST_METHOD(REQFM_005)
		{
//delete file test
			int value = 2;
			value = deleteData("max.txt");
			Assert::AreEqual(0, value);
		}
	};
}
