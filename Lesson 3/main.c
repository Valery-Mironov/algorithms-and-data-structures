//
//  main.c
//  Homework
//
//  Created by Валерий on 14.11.2019.
//  Copyright © 2019 Valery Mironov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// Меню домашнего задания

void menu() {
    printf("Домашнее задание Валерия Миронова. Решены 4 из 4 заданий.\n");
    printf("Введите номер задания для просмотра или ноль для завершения программы: ");
}

// Генерация рандомизированного массива

void randomizer(int length, int *array) {
    int i;                              // Объявление итератора
    for (i = 0; i < length; i++) {      // Объявление цикла для заполнения массива
        array[i] = i + 1;               // На каждой итерации добавлять в массив значение элемента + 1
    }
    for (i = 0; i < length; i++) {      // Объявление цикла для перетасовки массива
        int memory = array[i];          // Объявление переменной запоминающей значение текущего элемента массива
        int temp = rand() % length;     // Объявление временой переменной равной произвольному числу
        array[i] = array[temp];         // Значение итого элемента равно значению произвольного
        array[temp] = memory;           // Значение произвольного равно значению итого
    }
}

// Клонирвание рандомизированного массива

void cloning(int length, int *array, int *unsorted) {
    for (int i = 0; i < length; i++) {
        unsorted[i] = array[i];
    }
}

// Распечатка массива

void print(int length, int *array) {
    for (int i = 0; i < length; i++) {
        printf(" %i", array[i]);
    }
    printf("\n");
}

// Пузырькова сортировка

void bubblesort(int length, int *array) {
    int temp;
    int count = 0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            count++;
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                count++;
            } else {
            }
        }
    }
    printf("Итераций для пузырьковой сортировки потребовалось %i.\n", count);
}

// Оптимизированная пузырьковая сортировка

void extrabubblesort(int length, int *array) {
    int temp;
    int skipped = 0;
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (skipped == length) {
            break;
        }
        skipped = 1;
        for (int j = 0; j < length - 1; j++) {
            count++;
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                count++;
            } else {
                skipped++;
            }
        }
    }
    printf("Итераций для оптимизированной пузырьковой сортировки потребовалось %i.\n", count);
}

// Меню задания 1

void task1() {
    printf("\n");
    printf("Задание 1.\n");
    printf("Попробовать оптимизировать пузырьковую сортировку.\n");
    printf("Сравнить количество операций сравнения оптимизированной и неоптимизированной программы.\n");
    printf("Написать функции сортировки, которые возвращают количество операций.\n");
    printf("\n");
    int length = 10;                                            // Объявление длины массива
    int array[length];                                          // Объявление рабочего массива
    int unsorted[length];                                       // Объявление рандомизированного массива
    randomizer(length, array);                                  // Вызов функции заполнения массива в произвольном порядке
    cloning(length, array, unsorted);                           // Клонирование рандомизированного массива
    printf("Массив с произвольным расположением чисел:");
    print(length, unsorted);                                    // Вызов функции распечатки массива
    bubblesort(length, unsorted);                               // Пузырьковая сортировка
    printf("Отсортированный массив:");
    print(length, unsorted);                                    // Вызов функции распечатки массива
    cloning(length, array, unsorted);                           // Клонирование рандомизированного массива
    printf("\n");
    printf("Массив с произвольным расположением чисел:");
    print(length, unsorted);                                    // Вызов функции распечатки массива
    extrabubblesort(length, unsorted);                          // Оптимизированная пузырьковая сортировка
    printf("Отсортированный массив:");
    print(length, unsorted);                                    // Вызов функции распечатки массива
    printf("\n");
}

// Шейкерная сортировка

void cocktailsort(int length, int *array) {
    int i, j;
    int skipped = 0;
    int temp;
    int first = 0;
    int last = length - 1;
    int count = 0;                                              // Инициализация счётчика действий
    while (first != length / 2) {
        skipped = first;
        for (i = first; i < last; i++) {
            count++;
            if (array[i] > array[i + 1]) {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                count++;
            } else {
                skipped++;
            }
        }
        if (skipped == i) break;                                // Массив отсортирован
        last--;
        skipped = last;
        for (j = last; j > first; j--) {
            count++;
            if (array[j] < array[j - 1]) {
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
                count++;
            } else {
                skipped--;
            }
        }
        if (skipped == j) break;                                // Массив отсортирован
        first++;
    }
    printf("Итераций для шейкерной сортировки потребовалось %i.\n", count);
}

// Меню задания 2

void task2() {
    printf("\n");
    printf("Задание 2.\n");
    printf("Реализовать шейкерную сортировку.\n");
    printf("\n");
    int length = 10;                                            // Объявление длины массива
    int array[length];                                          // Объявление рабочего массива
    int unsorted[length];                                       // Объявление рандомизированного массива
    randomizer(length, array);                                  // Вызов функции заполнения массива в произвольном порядке
    cloning(length, array, unsorted);                           // Клонирование рандомизированного массива
    printf("Массив с произвольным расположением чисел:");
    print(length, unsorted);                                    // Вызов функции распечатки массива
    cocktailsort(length, unsorted);
    printf("Отсортированный массив:");
    print(length, unsorted);
    printf("\n");
}

// Бинарный поиск

int binarysearch(int *array, int length, int number) {
    int left = 0;
    int right = length - 1;
    int i = left + (right - left) / 2;
    while (array[i] != number && left != right) {
        if (array[i] < number) {
            left = i + 1;
            i = left + (right - left) / 2;
        } else {
            right = i - 1;
            i = left + (right - left) / 2;
        }
    }
    if (array[i] == number) {                                   // Проверка на соответствие искомому числу
        printf("Число найдено, номер хранящего его элемента массива: ");
        return i;
    } else {
        printf("Число не найдено, функция вернула: ");
        return -1;
    }
}

// Меню задания 3

void task3() {
    printf("\n");
    printf("Задание 3.\n");
    printf("Реализовать бинарный алгоритм поиска в виде функции, которой передаётся отсортированный массив.\n");
    printf("Функция возвращает индекс найденного элемента или –1, если элемент не найден.\n");
    printf("\n");
    int length = 10;                                            // Объявление длины массива
    int array[length];                                          // Объявление массива
    for (int i = 0; i < length; i++) {                          // Инициализация цикла для наполнения массива
        array[i] = i + 1;                                       // Наполнение массива
    }
    int number;                                                 // Инициализация переменной для хранения искомого числа
    printf("Введите число от 1 до %i для поиска в массиве: ", length);
    scanf("%i", &number);
    printf("%i\n", binarysearch(array, length, number));
    printf("\n");
}

// Меню задания 4

void task4() {
    printf("\n");
    printf("Задание 4.\n");
    printf("Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической сложностью алгоритма.\n");
    printf("\n");
    int length;
    length = 100;
    int array1[length];                                         // Объявление рабочего массива
    int unsorted1[length];                                      // Объявление рандомизированного массива
    randomizer(length, array1);                                 // Вызов функции заполнения массива в произвольном порядке
    cloning(length, array1, unsorted1);                         // Клонирование рандомизированного массива
    bubblesort(length, unsorted1);                              // Пузырьковая сортировка
    cloning(length, array1, unsorted1);                         // Клонирование рандомизированного массив
    extrabubblesort(length, unsorted1);                         // Оптимизированная пузырьковая сортировка
    cloning(length, array1, unsorted1);                         // Клонирование рандомизированного массива
    cocktailsort(length, unsorted1);                            // Шейкерная сортировка
    length = 1000;
    int array2[length];                                         // Объявление рабочего массива
    int unsorted2[length];                                      // Объявление рандомизированного массива
    randomizer(length, array2);                                 // Вызов функции заполнения массива в произвольном порядке
    cloning(length, array2, unsorted2);                         // Клонирование рандомизированного массива
    bubblesort(length, unsorted2);                              // Пузырьковая сортировка
    cloning(length, array2, unsorted2);                         // Клонирование рандомизированного массив
    extrabubblesort(length, unsorted2);                         // Оптимизированная пузырьковая сортировка
    cloning(length, array2, unsorted2);                         // Клонирование рандомизированного массива
    cocktailsort(length, unsorted2);                            // Шейкерная сортировка
    length = 10000;
    int array3[length];                                         // Объявление рабочего массива
    int unsorted3[length];                                      // Объявление рандомизированного массива
    randomizer(length, array3);                                 // Вызов функции заполнения массива в произвольном порядке
    cloning(length, array3, unsorted3);                         // Клонирование рандомизированного массива
    bubblesort(length, unsorted3);                              // Пузырьковая сортировка
    cloning(length, array3, unsorted3);                         // Клонирование рандомизированного массив
    extrabubblesort(length, unsorted3);                         // Оптимизированная пузырьковая сортировка
    cloning(length, array3, unsorted3);                         // Клонирование рандомизированного массива
    cocktailsort(length, unsorted3);                            // Шейкерная сортировка
    printf("\n");
}

// Основная программа

int main(int argc, const char * argv[]) {
    int select;
    do {
        menu();                                                 // Вызов функции меню
        scanf("%i", &select);
        switch (select) {
            case 0:
                printf("Спасибо за внимание.\n");
                break;
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            default:
                printf("Некорректный ввод.\n");
                break;
        }
    } while (select != 0);
    return 0;
}
