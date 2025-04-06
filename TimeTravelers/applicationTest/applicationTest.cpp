#include "pch.h"
#include "CppUnitTest.h"
#include "../BLL/include/register.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace applicationTest
{
	TEST_CLASS(applicationTest)
	{
	public:
		
		TEST_METHOD(registerTest)
		{
			std::string username = "testUser";
			std::string password = "password123#";
			
			
			bool firstAttempt = RegisterManager::registerUser(username, password);
			bool secondAttempt = RegisterManager::registerUser(username, "testPassword12#");

			Assert::IsTrue(firstAttempt);
			Assert::IsFalse(secondAttempt);

		}
	};
}
