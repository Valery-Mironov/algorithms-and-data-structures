//
//  main.c
//  Homework
//
//  Created by Валерий on 28.11.2019.
//  Copyright © 2019 Valery Mironov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

void menu(void);                                    // Меню домашнего задания
void task1(void);                                   // Задание 1
void task2(void);                                   // Задание 2
void task3(void);                                   // Задание 3
void task4(void);                                   // Задание 4
void fileRead(int * numbers);                       // Чтение данных из файла и конверсия из формата строки в формат чисел
void depthFirstSearch(int matrix[6][6], int position, int * used, int * way, int counter);
int breadthFirstSearch(int matrix[SIZE][SIZE], int * peaks, int peak, int count);

int main(int argc, const char * argv[]) {
    printf("Домашнее задание Валерия Миронова.\n");
    printf("\n");
    int select;
    do {
        menu();                                     // Вызов функции меню
        scanf("%i", &select);                       // Ввод числа
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

void menu() {
    printf("Список задач:\n");
    printf("1 задание – решено;\n");
    printf("2 задание – решено частично;\n");
    printf("3 задание – решено частично;\n");
    printf("4 задание – не решено.\n");
    printf("Введите номер задания для просмотра, или ноль для выхода: ");
}

/* Задача 1 ######################################################################################################################################### */

void task1() {
    printf("Написать функции, которые считывают матрицу смежности из файла и выводят её на экран.\n\n");
    int numbers[256];                              // Инициализация массива для хранения чисел, прочитаных из файла
    fileRead(numbers);                              // Вызов функции чтения и конверсии чисел из файла 1
    int length = numbers[0];                        // Считываение размера будущей матрицы
    int matrix[length][length];                     // Инициализация двумерного массива
    int counter = 1;                                // Инициализация переменной считчика
    printf("Вывод матрицы смежности на экран: \n");
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            matrix[i][j] = numbers[counter];        // Запись данных в матрицу смежности
            printf("%i ", matrix[i][j]);            // Вывод матрицы смежности из двумерного массива на экран
            counter++;
        }
        printf("\n");
    }
    printf("\n\n");
}

void fileRead(int * numbers) {
    char text[256];                                // Инициализация массива для записи строки из файла
    FILE * file = NULL;                             // Инициализация переменной для хранения данных из файла
    file = fopen("data.txt", "r");                  // Присвоение переменной «file» указателя на реальный файл, где «r» – режим чтения
    if (file == NULL) {                             // Если файл пустой
        puts("Невозможно открыть файл.\n");           // Вевести информацию об ошибке
        exit(1);                                    // Завершить программу с кодом 1
    }
    int i = 0;                                      // Инициализация переменной счётчика
    while (!feof(file)) {                           // Функция !feof возвращает ноль если конец файла не достигнут
        fscanf(file, "%s", text);                   // Считываем строки из файла и записываем в массив
        numbers[i] = atoi(text);                    // Каждое число переводим из формата строки в формат числа
        i++;                                        // Увеличиваем переменную счётчика на еденицу
    }
    fclose(file);                                   // Закрываем файл
}

/* Задача 2 ######################################################################################################################################### */

void task2() {
    printf("Написать рекурсивную функцию обхода графа в глубину.\n\n");
    int matrix[SIZE][SIZE] = {{0, 1, 0, 0, 1, 0}, {1, 0, 1, 0, 0, 1}, {0, 1, 0, 1, 0, 1}, {0, 0, 1, 0, 1, 0}, {1, 0, 0, 1, 0, 1}, {0, 1, 1, 0, 1, 0}};
    printf("Дан граф:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%i ", matrix[i][j]);            // Вывод матрицы смежности из двумерного массива на экран
        }
        printf("\n");
    }
    printf("\n");
    int position;                                   // Инициализация переменной, которая будет хранить текущую вершину
    do {
        printf("Введите номер вершины – 0, 1, 2, 3, 4 или 5: ");
        scanf("%i", &position);
    } while (position < 0 || position > 5);
    int used[SIZE] = {1, 1, 1, 1, 1, 1};            // Инициализация массива для проверки использованых вершин
    int way[SIZE];                                  // Инициализация массива для записи пути обхода
    int counter = 0;                                // Счётчик ходов
    printf("Результат рекурсивного обхода графа в глубину: ");
    depthFirstSearch(matrix, position, used, way, counter);
    printf("\n\n\n");
}

void depthFirstSearch(int matrix[SIZE][SIZE], int position, int * used, int * way, int counter) {
    way[counter] = position;
    printf("%i ", way[counter]);
    used[position] = 0;
    if (counter < SIZE) {
        for (int i = 0; i < SIZE; i++) {
            if (used[i] == 1 && matrix[position][i] == 1) {
                counter++;
                depthFirstSearch(matrix, i, used, way, counter);
                break;
            }
        }
    }
}

/* Задача 3 ######################################################################################################################################### */

void task3() {
    printf("Написать функцию обхода графа в ширину.\n\n");
    int matrix[SIZE][SIZE] = {{0, 1, 0, 0, 1, 0}, {1, 0, 1, 0, 0, 1}, {0, 1, 0, 1, 0, 1}, {0, 0, 1, 0, 1, 0}, {1, 0, 0, 1, 0, 1}, {0, 1, 1, 0, 1, 0}};
    printf("Дан граф:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%i ", matrix[i][j]);            // Вывод матрицы смежности из двумерного массива на экран
        }
        printf("\n");
    }
    int peaks[SIZE] = {2, 1, 1, 1, 1, 1};
    int count = SIZE;
    printf("Результат обхода графа в ширину:\n");
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf(" %i  ", peaks[i]);
    }
    while (count > 0) {
        int peak = 0;
        while (peaks[peak] != 2) {
            peak++;
        }
        count = breadthFirstSearch(matrix, peaks, peak, count);
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf(" %i  ", peaks[i]);
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("[%i] ", i);
    }
    printf("\n\n");
}

int breadthFirstSearch(int matrix[SIZE][SIZE], int * peaks, int peak, int count) {
    for (int i = 0; i < SIZE; i++) {
        if (matrix[peak][i] == 1 && peaks[i] == 1) {
            peaks[i] = 2;
        }
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf(" %i  ", peaks[i]);
    }
    peaks[peak] = 3;
    count--;
    return count;
}

/* Задача 4 ######################################################################################################################################### */

void task4() {
    printf("Создать библиотеку функций для работы с графами.\n\n");
    printf("\n\n");
}
