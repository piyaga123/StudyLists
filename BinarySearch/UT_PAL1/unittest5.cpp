#include "stdafx.h"
#include "CppUnitTest.h"
#include "BinarySearch.h"
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT_PAL1
{		
	TEST_CLASS(UT_PAL_t1)
	{
	public:
		
		TEST_METHOD(TesingPAL)
		{
			// TODO: Your test code here
			//std::this_thread::sleep_for(std::chrono::seconds(15));

			int Arr[] = { 2,5,7,8,9,11,13,34, 67, 89, 111, 222, 333, 444, 555 };
			int f1 = bsearchPAL(Arr, 15, 13);
			int f2 = bsearchPAL(Arr, 15, 9);
			int f22 = bsearchPAL(Arr, 15, 555);
			int f = bsearchPAL(Arr, 15, 2);

			Assert::AreEqual(6, f1);
			Assert::AreEqual(4, f2);

			int ArrS1[] = { 0 };
			int ArrS2[] = { 4 };

			int f3 = bsearchPAL(ArrS2, 1, 4);
			int f4 = bsearchPAL(ArrS2, 1, 5);

			Assert::AreEqual(1, f3);



			AddInts b(10,3);
			Assert::AreEqual(b.AddThem(), 13);

		}

	};
}