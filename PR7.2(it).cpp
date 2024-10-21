#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// Прототипи функцій
void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
void FindMaxIndex(int** a, const int k, int col, int& maxIdx);
void FindMinIndex(int** a, const int k, int col, int& minIdx);
void SwapMinMaxOddColumns(int** a, const int k, const int n);

int main()
{
    srand((unsigned)time(NULL));
    int Low, High, k, n; 

    // Введення меж для генерації випадкових чисел
    cout << "Low: "; cin >> Low;
    cout << "High: "; cin >> High;

    // Введення кількості рядків і стовпців
    cout << "k = "; cin >> k; 
    cout << "n = "; cin >> n; 

    int** a = new int* [k]; 
    for (int i = 0; i < k; i++)
        a[i] = new int[n]; 

    Create(a, k, n, Low, High);

    Print(a, k, n);

    SwapMinMaxOddColumns(a, k, n);

    cout << "Zminena matrutsya:\n";
    Print(a, k, n);

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

// Функція для створення матриці
void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// Функція для виведення матриці
void Print(int** a, const int k, const int n)
{
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

// Функція для знаходження індексу максимального елемента в стовпці
void FindMaxIndex(int** a, const int k, int col, int& maxIdx)
{
    maxIdx = 0; 
    for (int i = 1; i < k; i++) 
    {
        if (a[i][col] > a[maxIdx][col])
        {
            maxIdx = i; 
        }
    }
}

// Функція для знаходження індексу мінімального елемента в стовпці
void FindMinIndex(int** a, const int k, int col, int& minIdx)
{
    minIdx = 0; 
    for (int i = 1; i < k; i++) 
    {
        if (a[i][col] < a[minIdx][col])
        {
            minIdx = i; 
        }
    }
}

// Функція для заміни місцями максимальних і мінімальних елементів у непарних стовпцях
void SwapMinMaxOddColumns(int** a, const int k, const int n)
{
    for (int j = 0; j < n; j += 2) // перебір стовпців
    {
        int maxIdx, minIdx; 
        FindMaxIndex(a, k, j, maxIdx); 
        FindMinIndex(a, k, j, minIdx); 

        // Міняємо місцями максимальний і мінімальний елементи, якщо вони знайдені
        if (maxIdx != minIdx) { 
            int temp = a[maxIdx][j]; 
            a[maxIdx][j] = a[minIdx][j]; 
            a[minIdx][j] = temp; 
        }
    }
}
