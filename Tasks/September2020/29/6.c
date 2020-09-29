#define _CRT_SECURE_NO_WARNINGS
#define SIZE 5
#include <stdio.h>
#include <locale.h>

/*
6. Неотсортированный массив с повторяющимися элементами введён с клавиатуры.
   1. Сформировать массив без повторений.
   2. Подсчитать количество каждых элементов
*/

/*
Функция, возвращающая: 
1, если элемент уже содержится внутри нового массива,
0, если нет
Проверка производится до заданного limit (правая граница), не включая сам limit
*/
int contains(int arrRes[], int element, int limit) {
    int k;
    for(k = 0; k < limit; k++) {
        if(arrRes[k] == element) return 1;
    }
    return 0;
}

void main() {
    setlocale(LC_ALL, "");
    int arr[SIZE];
    int arrRes[SIZE];
    //i - счётчик для arr, j - счётчик количества элементов в конечном массиве arrRes
    int i, j = 0;
    //count - счётчик для подсчёта и вывода количества конкретных элементов
    //(используется в конце задачи)
    int count = 0;
    //z - счётчик для вложенного цикла (в конце задачи)
    int z;

    printf("Введите %i элементов массива:\n", SIZE);
    for(i = 0; i < SIZE; i++)
        scanf("%i", &arr[i]);

    for(i = 0; i < SIZE; i++) {
        if(!contains(arrRes, arr[i], j)) {
            arrRes[j] = arr[i];
            j++;
        }
    }

    //Вывод результата (массив без повторяющихся элементов)
    printf("Получившийся массив без повторений:\n[ ", j);
    for(i = 0; i < j; i++)
        printf("%i ", arrRes[i]);
    printf("]\n\n");

    //Подсчёт и вывод количества различных элементов в начальном массиве
    //(проходим по конечному массиву и считаем, 
    //сколько раз каждый из элементов встречался в начальном)
    printf("Элемент -> количество его вхождений в исходном массиве:\n");
    for(i = 0; i < j; i++) {
        for(z = 0; z < SIZE; z++)
            if(arr[z] == arrRes[i]) count++;
        printf("%i -> %i\n", arrRes[i], count);
        count = 0;
    }
}