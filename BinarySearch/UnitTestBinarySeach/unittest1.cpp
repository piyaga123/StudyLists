#include "stdafx.h"
#include "CppUnitTest.h"
#include "BinarySearch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestBinarySeach
{		
	TEST_CLASS(TestAddInts)
	{
	public:
		
		TEST_METHOD(TestAddThem)
		{
			// TODO: Your test code here
			AddInts a(7,8);
			Assert::AreEqual(a.AddThem(), 15);

			Assert::AreEqual(1.1, 2.2/2);
		}

	};
}