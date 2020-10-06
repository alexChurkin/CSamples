#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define M 5
#define N 10

/*
7. Заданы 2 массива размерами M и N, где M < N;
   Определить, содержатся ли все эл-ты массива размером M в другом массиве (размером N)
*/
void main() {
    setlocale(LC_CTYPE, "rus");
    int arrSmall[M];
    int arrBig[N];
    int i, j;
    int found = 0;

    printf("Введите все элементы МЕНЬШЕГО массива (размером M = %i):\n", M);
    for(i = 0; i < M; i++)
        scanf("%i", &arrSmall[i]);
    
    printf("\nВведите элементы БОЛЬШЕГО массива (размером N = %i):\n", N);
    for(i = 0; i < N; i++)
        scanf("%i", &arrBig[i]);

    for(i = 0; i < M; i++) {
        for(j = 0; j < N; j++) {
            if(arrSmall[i] == arrBig[j]) found = 1;
            break;
        }
        if(!found) {
            printf("Не все элементы маленького массива содержатся в большом");
            return;
        }
        found = 0;
    }
    printf("Все элементы меньшего содержатся в большем");
}