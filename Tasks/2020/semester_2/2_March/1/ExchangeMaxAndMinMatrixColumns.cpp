#include <iostream>
#include <locale.h>
#include <time.h>
using namespace std;

void print_matrix(double **matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        int j;
        for (j = 0; j < n - 1; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << matrix[i][j] << '\n';
    }
}

double **make_matrix(int m, int n)
{
    double **matrix = new double *[m];
    for (int i = 0; i < m; i++)
        matrix[i] = new double[n];
    return matrix;
}

void fill_matrix(double **matrix, int m, int n)
{
    int count = m * n;

    if (count <= 9)
    {
        cout << "Введите " << m * n << " элементов матрицы:\n";
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        return;
    }

    cout << "Матрица будет заполена автоматически.\n";
    srand((unsigned int)time(NULL));
    int range_min, range_max;
    cout << "Введите минимальное значение: \n";
    cin >> range_min;
    cout << "Введите максимальное значение: \n";
    cin >> range_max;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] =
                (int)((double)rand() / (RAND_MAX + 1) * (range_max + 1 - range_min) +
                      range_min);
        }
    }
    cout << "Успешно создана матрица: \n";
    print_matrix(matrix, m, n);
}

//Функция нахождения максимального элемента в матрице
void max_element_cords(double **matrix, int n, int &str, int &col)
{
    str = 0, col = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] > matrix[str][col])
            {
                str = i;
                col = j;
            }
        }
}

//Функция нахождения минимального элемента в матрице
void min_element_cords(double **matrix, int n, int &str, int &col)
{
    str = 0, col = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] < matrix[str][col])
            {
                str = i;
                col = j;
            }
        }
}

void exchange_min_max_columns_matrix(double **matrix, int n)
{
    int strmin, colmin;
    min_element_cords(matrix, n, strmin, colmin);
    int strmax, colmax;
    max_element_cords(matrix, n, strmax, colmax);
    //Теперь нужно поменять местами элементы столбцов colmin и colmax
    for (int i = 0; i < n; i++)
        swap(matrix[i][colmin], matrix[i][colmax]);
}

int main()
{
    setlocale(LC_ALL, "russian");
    int m = 3, n = 3;
    double **matr = make_matrix(m, n);
    fill_matrix(matr, m, n);

    /*int strmin, colmin;
    min_element_cords(matr, n, strmin, colmin);
    cout << "Минимум найден:\nСтрока = " << strmin + 1
         << ", Столбец = " << colmin + 1 << '\n';

    int strmax, colmax;
    max_element_cords(matr, n, strmax, colmax);
    cout << "Максимум найден:\nСтрока = " << strmax + 1
         << ", Столбец = " << colmax + 1 << '\n';*/
    exchange_min_max_columns_matrix(matr, n);
    cout << "Новая матрица:\n";
    print_matrix(matr, n, n);
    return 0;
}