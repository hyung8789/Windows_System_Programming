#include "pch.h"
#include "CppUnitTest.h"

#include "../CommandPrompt.cpp"
#include "../main.cpp"
#include <iostream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace 명령프롬프트단위테스트
{
	TEST_CLASS(명령프롬프트단위테스트)
	{
	public:

		TEST_METHOD(TokenList_초기화_테스트)
		{
			// https://docs.microsoft.com/en-us/cpp/text/how-to-convert-between-various-string-types?view=msvc-160
			ClearTokenList();

			for (int i = 0; i < MAX_CMD_TOKEN_COUNT; i++)
				for (int j = 0; j < MAX_STR_LEN; j++)
					Assert::AreEqual((TCHAR)NULL, cmdTokenList[i][j]);
		}

		TEST_METHOD(소문자_변환_테스트)
		{
			TCHAR* expected = L"test";
			TCHAR* actual = StrLower(expected);
			TCHAR* actual2 = StrLower(NULL);

			Assert::AreEqual(actual, expected);
			Assert::IsNull(actual2);
		}
	};
}
