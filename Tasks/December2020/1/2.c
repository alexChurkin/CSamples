#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

/*
2. Приближённый синус по формуле Тейлора (выводит дичь при больших x)
*/
double my_sin(double x, int n)
{
    int i, j;
    int sign = 1;

    double result = 0;
    double a = x;
    for (i = 1, j = 1; i <= n; i++, j += 2)
    {
        result += sign * a;
        sign = - sign;
        //a *= (x * x) / ((j + 1) * (j + 2));
        //printf("x/(j + 1) = %lf, x/(j + 2) = %lf\n", (x / (j + 1)), (x / (j + 2)));
        //printf("a = %lf\n", a);
        a *= (x / (j + 1)) * (x / (j + 2));
    }
    return result;
}

void main()
{
    setlocale(LC_CTYPE, "rus");
    double x;
    int n;
    printf("В какой точке?\n");
    scanf("%lf", &x);
    printf("Сколько слагаемых?\n");
    scanf("%i", &n);
    printf(">Настоящий sin(%lf) = %lf\n", x, sin(x));
    printf(">Приближённый sin(%lf) = %lf\n", x, my_sin(x, n));
}