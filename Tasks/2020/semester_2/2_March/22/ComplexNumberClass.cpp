#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <cmath>
#include <string>
using namespace std;

/*
2. Класс комплексное число
*/
class complex
{
private:
    double re, im;

public:
    //Конструктор по умолчанию
    complex()
    {
        this->re = 0.0;
        this->im = 0.0;
    }

    //Конструктор с параметрами
    complex(double re, double im)
    {
        this->re = re;
        this->im = im;
    }

    //Сеттер действительной части
    void set_re(double re)
    {
        this->re = re;
    }

    //Геттер действительной части
    double get_re()
    {
        //по факту return this->re;
        return re;
    }

    //Сеттер мнимой части
    void set_im(double im)
    {
        this->im = im;
    }

    //Геттер мнимой части
    double get_im()
    {
        return im;
    }

    /* Функции для арифметических операций над числом */
    complex operator+(const complex b)
    {
        complex c;
        //равносильно this->re
        c.re = re + b.re;
        c.im = im + b.im;
        return c;
    }

    complex operator-(const complex b)
    {
        complex c;
        c.re = re - b.re;
        c.im = im - b.im;
        return c;
    }

    complex operator*(const complex b)
    {
        complex c;
        c.re = re * b.re - im * b.im;
        c.im = re * b.im + im * b.re;
        return c;
    }

    /*
    Возвращает комплексно-сопряжённое к данному число
    const в данном случае сообщает о том, что данная функция
    не затрагивает внутренности нашего текущего объекта
    -> может быть вызвана у константного объекта
    (как в случае с делением)
    */
    complex conjugate() const
    {
        return complex(re, -im);
    }

    complex operator/(const complex b)
    {
        complex c = (*this) * b.conjugate();
        double t = b.re * b.re + b.im * b.im;
        c.re /= t;
        c.im /= t;
        return c;
    }

    double abs()
    {
        return sqrt(re * re + im * im);
    }

    string get_str()
    {
        if (im == 0)
            return to_string(re);
        else if (im > 0)
        {
            return to_string(re) + " + " + to_string(im) + "i";
        }
        else
        {
            return to_string(re) + " - " + to_string(-im) + "i";
        }
    }
};

int main()
{
    setlocale(LC_ALL, "russian");
    complex a(1, 2);
    complex b(3, 4);
    complex c = a / b;

    cout << "> Сложение:  a + b = " << (a + b).get_str() << '\n';
    cout << "> Вычитание: a - b = " << (a - b).get_str() << '\n';
    cout << "> Умножение: a * b = " << (a * b).get_str() << '\n';
    cout << "> Деление:   a / b = " << (a / b).get_str() << '\n';
    cout << "> Модуль:   |a| = " << a.abs();
    return 0;
}