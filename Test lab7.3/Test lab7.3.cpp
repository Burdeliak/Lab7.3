#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.3/lab7.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testlab73
{
	TEST_CLASS(Testlab73)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			
			int rowCount = 3;
			int colCount = 3;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++) {
				a[i] = new int[colCount];
			}

			
			int data[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					a[i][j] = data[i][j];
				}
			}

			
			int product = FindProductOfRows(a, rowCount, colCount);
			Assert::AreEqual(362880, product);  // 1*2*3*4*5*6*7*8*9 = 362880

			
			for (int i = 0; i < rowCount; i++) {
				delete[] a[i];
			}
			delete[] a;
		}
		};
	
};
