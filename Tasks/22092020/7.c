#include <stdio.h>

/*
7. Вывод на экран цифр заданного числа
*/
void main() {
    int n, res = -1;
    scanf("%i", &n);

    res = n % 10;
    while(res != 0) {
        printf("%i\n", res);
        n /= 10;
        res = n % 10;
    }
}