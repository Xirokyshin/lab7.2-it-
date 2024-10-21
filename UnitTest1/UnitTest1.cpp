#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7.2(it).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestSwapMinMaxOddColumns)
        {
            const int k = 3;
            const int n = 3;
            int* a[k];
            for (int i = 0; i < k; i++)
                a[i] = new int[n];

            a[0][0] = 8; a[0][1] = 4; a[0][2] = 3;
            a[1][0] = 8; a[1][1] = 5; a[1][2] = 2;
            a[2][0] = 1; a[2][1] = 6; a[2][2] = 7;

            SwapMinMaxOddColumns(a, k, n);

            Assert::AreEqual(8, a[1][0]); 
            Assert::AreEqual(1, a[0][0]);

            for (int i = 0; i < k; i++)
                delete[] a[i];
        }
    };
};