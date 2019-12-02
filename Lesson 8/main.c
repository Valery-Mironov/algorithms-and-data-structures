//
//  main.c
//  Homework
//
//  Created by Валерий on 02.12.2019.
//  Copyright © 2019 Valery Mironov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void menu(void);                                    // Меню домашнего задания
void task1(void);                                   // Задание 1
void task2(void);                                   // Задание 2
void task3(void);                                   // Задание 3
void task4(void);                                   // Задание 4
void task5(void);                                   // Задание 5

void arrayPrint(int * array, int length);                   // Распечатка массива
void simpleCountingSort(int *array, int length, int max);   // Сортировка подсчётом
int quickSort(int * array, int start, int end);             // Сортировка Хоара

int main(int argc, const char * argv[]) {
    printf("Домашнее задание Валерия Миронова.\n");
    printf("\n");
    int select;
    do {
        menu();
        scanf("%i", &select);
        printf("\n\n");
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
            default:
                printf("Некорректный ввод.\n");
                break;
        }
    } while (select != 0);
    return 0;
}

void menu() {
    printf("Список задач:\n");
    printf("1 задание – решено;\n");
    printf("2 задание – решено (но почему-то срабатывает не с первого раза);\n");
    printf("3 задание – не успел решить;\n");
    printf("4 задание – не успел решить.\n");
    printf("Введите номер задания для просмотра, или ноль для выхода: ");
}

/* Задача 1 ######################################################################################################################################### */

void task1() {
    printf("Реализовать сортировку подсчетом.\n\n");
    int array[SIZE] = {3, 2, 500, 123, 854, 121, 86, 19, 333, 0};
    int max = 0;
    for (int i = 0; i < SIZE; i++) {
        if (array[i] > max) max = array[i];
    }
    arrayPrint(array, SIZE);
    simpleCountingSort(array, SIZE, max);
}

void arrayPrint(int * array, int length) {
    printf("Распечатка массива:\t\t");
    for (int i = 0; i < length; i++) {
        printf(" %i", array[i]);
    }
    printf("\n");
}

void simpleCountingSort(int * array, int length, int max) {
    int frequency[max + 1];
    for (int i = 0; i < max; i++) {
        frequency[i] = 0;
    }
    for (int i = 0; i < length; i++) {
        frequency[array[i]]++;
    }
    int cell = 0;
    for (int i = 0; i < max + 1; i++) {
        if (frequency[i] > 0) {
            for (int j = 0; j < frequency[i]; j++) {
                array[cell] = i;
                cell++;
            }
        }
    }
    printf("Отсортированный массив:\t");
    for (int i = 0; i < length; i++) {
        printf(" %i", array[i]);
    }
    printf("\n\n\n");
}

/* Задача 2 ######################################################################################################################################### */

void task2() {
    printf("Реализовать быструю сортировку.\n\n");
    int array[SIZE] = {3, 2, 500, 123, 854, 121, 86, 19, 333, 0};
    arrayPrint(array, SIZE);
    quickSort(array, 0, SIZE - 1);
    printf("Отсортированный массив:\t");
    for (int i = 0; i < SIZE; i++) {
        printf(" %i", array[i]);
    }
    printf("\n\n");
}

int quickSort(int * array, int start, int end) {
    if (start < end) {
        int middle = rand() % (end - start + 1) + start;
//        int middle = (end - start) / 2 + start;
        int i = start, j = end;
        while (i < j) {
            if (array[i] >= array[middle]) {
                if (array[j] < array[middle]) {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                    i++;
                    j--;
                } else {
                    j--;
                }
            } else {
                i++;
            }
        }
        quickSort(array, start, middle);
        quickSort(array, middle + 1, end);
    } else {
        return 1;
    }
    return 0;
}
