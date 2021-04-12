#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <string>
using namespace std;

/*
1. VectorND
*/
class Vector
{
private:
    int n;
    double *arr;

public:
    //Конструктор обычный
    Vector(int _n = 3);
    //Конструктор копирования
    Vector(const Vector &v);
    //Деструктор
    ~Vector();

    //Сложение
    Vector operator+(double b);
    Vector operator+(const Vector &b);
    //Вычитание
    Vector operator-(double b);
    Vector operator-(const Vector &b);
    //Умножение на число
    Vector operator*(double b);
    //Скалярное произведение
    double operator*(const Vector &b);

    //Получение i-й компоненты для чтения/записи (set/get)
    double &operator[](int i);

    friend ostream &operator<<(ostream &os, Vector v)
    {
        os << '(';
        for (int i = 0; i < v.n - 1; i++)
        {
            os << v[i] << ", ";
        }
        os << v[v.n - 1] << ')';
        return os;
    }
};

/* ........................ */

Vector::Vector(int _n)
{
    n = _n;
    arr = new double[_n];
}

//В конструктор копирования передаётся ссылка!
//Иначе будет вызов функции копирования со срабатыванием
//КОНСТРУКТОРА КОПИРОВАНИЯ!!! (БЕСКОНЕЧНЫЙ ЦИКЛ)
Vector::Vector(const Vector &v)
{
    n = v.n;
    arr = new double[v.n];
    for (int i = 0; i < n; i++)
        arr[i] = v.arr[i];
}

Vector::~Vector()
{
    delete[] arr;
}

Vector Vector::operator+(double b)
{
    Vector res(n);
    for (int i = 0; i < n; i++)
        res[i] = (*this)[i] + b;
    //c.arr[i] = arr[i] + b;
    //СОЗДАЁТСЯ КОПИЯ ДАННОЙ ПЕРЕМЕННОЙ С ТЕМ ЖЕ ЗНАЧЕНИЕМ,
    //ЗАТЕМ ПЕРЕДАЁТСЯ В ГЛАВНУЮ ПРОГРАММУ! ДЛЯ ЭТОГО ОБЯЗАТЕЛЬНО
    //НУЖНО ПЕРЕОПРЕДЕЛЯТЬ КОНСТРУКТОР КОПИРОВАНИЯ (ЕСЛИ В КЛАССЕ ЕСТЬ
    //ДИНАМИЕЧЕСКИЕ ПОЛЯ)
    return res;
}

//const-ссылка нужна, чтобы обезопасить себя от изменения полей b внутри
//данной функции!
Vector Vector::operator+(const Vector &b)
{
    Vector res(n);
    for (int i = 0; i < n; i++)
        res[i] = arr[i] + b.arr[i];
    return res;
}

Vector Vector::operator-(double b)
{
    Vector res(n);
    for (int i = 0; i < n; i++)
        res[i] = (*this)[i] - b;
    return res;
}

Vector Vector::operator-(const Vector &b)
{
    Vector res(n);
    for (int i = 0; i < n; i++)
        res[i] = arr[i] - b.arr[i];
    return res;
}

Vector Vector::operator*(double b)
{
    Vector res(n);
    for (int i = 0; i < n; i++)
        res.arr[i] = arr[i] * b;
    return res;
}

double Vector::operator*(const Vector &b)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i] * b.arr[i];
    return sum;
}

double &Vector::operator[](int i)
{
    return arr[i];
}

/* ........................ */
int main()
{
    setlocale(LC_ALL, "russian");
    Vector c(3);
    Vector d(3);
    c[0] = 1;
    c[1] = 2;
    c[2] = 3;
    d[0] = d[1] = d[2] = 5;

    cout << "Дано:\n";
    cout << "c = " << c << "\n";
    cout << "d = " << d << "\n\n";

    Vector k1 = c + 2;
    cout << "c + 2 = " << k1 << '\n';

    Vector k2 = c - 2;
    cout << "c - 2 = " << k2 << '\n';

    Vector k3 = c * 10;
    cout << "c * 10 = " << k3 << '\n';

    int k4 = c * d;
    cout << "c * d = " << k4 << '\n';

    return 0;
}