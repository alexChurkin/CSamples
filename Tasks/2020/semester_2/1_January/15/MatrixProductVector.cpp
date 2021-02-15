#include <iostream>
#include <locale.h>
using namespace std;

double dot_product(double a[], double b[], int size)
{
    int result = 0;
    for (int i = 0; i < size; i++)
        result += a[i] * b[i];
    return result;
}

//Произведение матрицы на вектор
double matrixOnVector(double a[], double b[], int size)
{

}

int main()
{
    setlocale(LC_ALL, "russian");
    double arr1[] = {1, 2, 3};
    double arr2[] = {4, 5, 6};

    cout << dot_product(arr1, arr2, 3);
    return 0;
}