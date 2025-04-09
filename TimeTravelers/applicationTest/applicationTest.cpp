#include "pch.h"
#include "CppUnitTest.h"
#include "../BLL/include/register.h"
#include "../BLL/include/login.h"
#include "../DAL/include/files.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace applicationTest
{
	TEST_CLASS(applicationTest)
	{
	public:

		// Test to verify that registration succeeds on first attempt and fails on duplicate
		TEST_METHOD(registerTest)
		{
			json empty;
			FileManager::saveJSON("users.json", empty);

			std::string username = "testUser";
			std::string password = "password123#";


			bool firstAttempt = RegisterManager::registerUser(username, password);
			bool secondAttempt = RegisterManager::registerUser(username, "testPass12#");

			Assert::IsTrue(firstAttempt);
			Assert::IsFalse(secondAttempt);

		}

		// Test to verify that login succeeds with the correct password and fails with an incorrect one
		TEST_METHOD(loginTest)
		{
			json empty;
			FileManager::saveJSON("users.json", empty);

			std::string username = "loginUser";
			std::string password = "loginPass!123";

			RegisterManager::registerUser(username, password);

			bool loginSuccess = LoginManager::login(username, password);
			Assert::IsTrue(loginSuccess);

			bool loginFail = LoginManager::login(username, "wrongPass12!");
			Assert::IsFalse(loginFail);
		}
	};
}
