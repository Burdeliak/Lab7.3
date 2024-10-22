#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

int ProductOfRowWithoutZeroes(int** a, const int colCount, int rowNo) {
    int product = 1;
    for (int j = 0; j < colCount; j++) {
        if (a[rowNo][j] == 0) {
            return 0;  
        }
        product *= a[rowNo][j];
    }
    return product;
}

int FindProductOfRows(int** a, const int rowCount, const int colCount) {
    int totalProduct = 1;
    bool hasValidRow = false;

    for (int i = 0; i < rowCount; i++) {
        int product = ProductOfRowWithoutZeroes(a, colCount, i);
        if (product != 0) {
            totalProduct *= product;
            hasValidRow = true;
        }
    }

    return hasValidRow ? totalProduct : 0;  
}

void SumOfDiagonals(int** a, const int rowCount, const int colCount, int& maxSum) {
    maxSum = INT_MIN;

    
    for (int offset = -(rowCount - 1); offset < colCount; offset++) {
        int sum = 0;
        for (int i = 0; i < rowCount; i++) {
            int j = i + offset;
            if (j >= 0 && j < colCount) {
                sum += a[i][j];
            }
        }
        if (sum > maxSum) {
            maxSum = sum;
        }
    }
}

void PrintMatrix(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    srand((unsigned)time(NULL));
    int Low = -7;
    int High = 7;
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        a[i] = new int[colCount];
    }

    
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    PrintMatrix(a, rowCount, colCount);

    
    int product = FindProductOfRows(a, rowCount, colCount);
    if (product != 0)
        cout << "!0 = " << product << endl;
    else
        cout << "!0" << endl;

    
    int maxSum;
    SumOfDiagonals(a, rowCount, colCount, maxSum);
    cout << "Max sum diagonals = " << maxSum << endl;

    
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}