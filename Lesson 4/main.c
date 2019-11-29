//
//  main.c
//  Homework
//
//  Created by Валерий on 17.11.2019.
//  Copyright © 2019 Valery Mironov. All rights reserved.
//

#include <stdio.h>
#define HEIGHT 6
#define WIDTH 5

// Меню домашнего задания

void menu() {
    printf("Домашнее задание Валерия Миронова. Решены 3 из 3 заданий.\n");
    printf("Введите номер задания для просмотра или ноль для завершения программы: ");
}

// Первая функция распечатки двумерного массива

void print1(int h, int w, int array[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            printf("%3i", array[i][j]);
            
        }
        printf("\n");
    }
}

// Задание 1

void task1() {
    printf("Задание 1.\n");
    printf("Количество маршрутов с препятствиями.\n");
    printf("Реализовать чтение массива с препятствием и нахождение количества маршрутов.\n");
    printf("\n");
    int map[HEIGHT][WIDTH];                                         // Инициализируем двумерный массив для карты
    int array[HEIGHT][WIDTH];                                       // Инициализируем двумерный массив для вычислений
    int i,j;                                                        // Инициализируем две переменные счётчики
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if ((i == 3 && j == 0) || (i == 4 && j == 0) || (i == 4 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 2) || (i == 2 && j == 3)) {
                map[i][j] = 0;
            } else {
                map[i][j] = 1;
            }
        }
    }
    printf("Чтение массива с препятствиями:\n\n");
    print1(HEIGHT, WIDTH, map);                                     // Распечатываем массив для карты
    printf("\n");
    for (j = 0; j < WIDTH; j++) {                                   // Проходимся по ширине массива для вычислений
        if (map[0][j] == 0) array[0][j] = 0;                        // Если позиция на карте заблокирована, ставим ноль
        else if (array[0][j - 1] == 0) array[0][j] = 0;             // Иначе, если позиция левее заблокирована, ставим ноль
        else array[0][j] = 1;                                       // Иначе инициализируем первую строку единицами
    }
    for (i = 1; i < HEIGHT; i++) {                                  // Проходимся по высоте массива для вычислений начиная со второй позиции
        if (map[i][0] == 0) array[i][0] = 0;                        // Если позиция на карте заблокирована, ставим ноль
        else if (array[i - 1][0] == 0) array[i][0] = 0;             // Иначе, если позиция выше заблокирована, ставим ноль
        else array[i][0] = 1;                                       // Иначе, инициализируем первый столбец единицами
        for (j = 1; j < WIDTH; j++) {                               // Проходимся по ширине массива для вычислений начиная со второй позиции
            if (map[i][j] == 0) array[i][j] = 0;                    // Если позиция на карте заблокирована, ставим ноль
            else array[i][j] = array[i][j - 1] + array[i - 1][j];   // Иначе инициализируем массив произведением числа слева и сверху
        }
    }
    printf("Нахождение количества маршрутов:\n\n");
    print1(HEIGHT, WIDTH, array);                                    // Распечатываем массив для вычислений
    printf("\n");
}

// Вторая функция распечатки двумерного массива

void print2(int width, int height, int array[width][height], char *brains, char *minds) {
    int i, j;
    for (i = 0; i < width; i++) {
        printf("%3c", brains[i]);
    }
    printf("\n");
    for (i = 1; i < height; i++) {
        printf("%3c", minds[i]);
        for (j = 1; j < width; j++) {
            printf("%3i", array[i][j]);
            
        }
        printf("\n");
    }
}

// Задание 2

void task2() {
    printf("Задание 2.\n");
    printf("Решить задачу о нахождении длины максимальной подпоследовательности с помощью матрицы.\n");
    printf("\n");
    char brains[] = {' ', 'G', 'E', 'E', 'K', 'B', 'R', 'A', 'I', 'N', 'S', '\0'};
    char minds[] = {'0', 'G', 'E', 'E', 'K', 'M', 'I', 'N', 'D', 'S', '\0'};
    int i = 0, j = 0, length = 0, width = 0, height = 0;
    while (brains[width] != '\0') {                                 // Определяем ширину матрицы исходя из длины первого массива
        width++;
    }
    while (minds[height] != '\0') {                                 // Определяем высоту матрицы исходя из длины второго массива
        height++;
    }
    int array[width][height];                                       // Инициализация двумерного массива матрицы нулями
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            array[i][j] = 0;
        }
    }
    int memorizer = 0;                                              // Инициализация переменной для запоминания позиции в матрице
    int found = 0;                                                  // Инициализация переменной для хранения результатов поиска
    int skipped = 0;                                                // Инициализация переменной для хранения пропущеных шагов
    for (i = 0; i < height; i++) {                                  // Цикл перебора строк
        for (j = memorizer; j < width; j++) {                       // Цикл перебора столбцов
            if (brains[j] == minds[i]) {                            // Если джитый элемент массива «brains» равен итому элементу массива «minds»
                length++;                                           // Длинну подпоследовательности увеличить на еденицу
                array[i][j] = length;                               // Отметить увеличение в матрице
                found = 1;                                          // Изменить переменную результатов поиска на еденицу
                break;                                              // Прервать цикл
            } else {                                                // Иначе
                skipped++;                                          // Считать пропущеные ячейки
            }
        }
        if (found == 0) {                                           // Если совпадение в строке не найдено
            memorizer = j - skipped;                                // Присвоить «memorizer» результат вычитания из джитого элемента пропущенных шагов
            skipped = 0;                                            // Обнулить счётчик пропущеных шагов
        } else {                                                    // Иначе
            memorizer = j + 1;                                      // Присвоить «memorizer» результат увеличения джитого элемента на еденицу
            found = 0;                                              // Обнулить переменную результатов поиска
        }
    }
    print2(width, height, array, brains, minds);                    // Вывести матрицу
    printf("\n");
    printf("Максимальная длина подпоследовательности равна %i.", length);
    printf("\n\n");
}

// Функция подсчёта варантов хода

int searchForOptions(int h, int w, int array[HEIGHT][WIDTH]) {
    int options = 0;
    if (array[h + 1][w + 2] == 0 && h + 1 >= 0 && h + 1 < HEIGHT && w + 2 >= 0 && w + 2 < WIDTH) {      // Ход 0
        options++;
    }
    if (array[h + 2][w + 1] == 0 && h + 2 >= 0 && h + 2 < HEIGHT && w + 1 >= 0 && w + 1 < WIDTH) {      // Ход 1
        options++;
    }
    if (array[h + 2][w - 1] == 0 && h + 2 >= 0 && h + 2 < HEIGHT && w - 1 >= 0 && w - 1 < WIDTH) {      // Ход 2
        options++;
    }
    if (array[h + 1][w - 2] == 0 && h + 1 >= 0 && h + 1 < HEIGHT && w - 2 >= 0 && w - 2 < WIDTH) {      // Ход 3
        options++;
    }
    if (array[h - 1][w - 2] == 0 && h - 1 >= 0 && h - 1 < HEIGHT && w - 2 >= 0 && w - 2 < WIDTH) {      // Ход 4
        options++;
    }
    if (array[h - 2][w - 1] == 0 && h - 2 >= 0 && h - 2 < HEIGHT && w - 1 >= 0 && w - 1 < WIDTH) {      // Ход 5
        options++;
    }
    if (array[h - 2][w + 1] == 0 && h - 2 >= 0 && h - 2 < HEIGHT && w + 1 >= 0 && w + 1 < WIDTH) {      // Ход 6
        options++;
    }
    if (array[h - 1][w + 2] == 0 && h - 1 >= 0 && h - 1 < HEIGHT && w + 2 >= 0 && w + 2 < WIDTH) {      // Ход 7
        options++;
    }
    return options;
}

// Функция проверки следующего хода

int nextMoveCheck(int h, int w, int array[HEIGHT][WIDTH]) {
    int options = 0;
    if (h < 0 || w < 0 || h > HEIGHT - 1 || w > WIDTH - 1) {
        return options;
    } else {
        if (array[h][w] == 0) {
            options = searchForOptions(h, w, array);
        } else {
            return options;
        }
        
        return options;
    }
}

// Задаине 3

void task3() {
    printf("Задание 3.\n");
    printf("Требуется обойти конём шахматную доску размером N × M, пройдя через все поля доски по одному разу.\n");
    printf("Здесь алгоритм решения такой же, как и в задаче о 8 ферзях.\n");
    printf("Разница только в проверке положения коня.\n");
    printf("\n");
    
    int stop = 0;
    int options[8];
    int array[HEIGHT][WIDTH];
    int w, h, progress = 1;
    
    for (h = 0; h < HEIGHT; h++) {
        for (w = 0; w < WIDTH; w++) {
            array[h][w] = 0;
        }
    }
    
    h = 0;
    w = 0;
    array[h][w] = 1;
    
    print1(HEIGHT, WIDTH, array);
    printf("\n");
    
    do {
//        if (progress == HEIGHT * WIDTH) break;
//        printf("h = %i, w = %i\n\n", h, w);
//        printf("Ход %i.\n", progress);
        printf("\n");
        
        options[0] = nextMoveCheck(h + 1, w + 2, array);
        options[1] = nextMoveCheck(h + 2, w + 1, array);
        options[2] = nextMoveCheck(h + 2, w - 1, array);
        options[3] = nextMoveCheck(h + 1, w - 2, array);
        options[4] = nextMoveCheck(h - 1, w - 2, array);
        options[5] = nextMoveCheck(h - 2, w - 1, array);
        options[6] = nextMoveCheck(h - 2, w + 1, array);
        options[7] = nextMoveCheck(h - 1, w + 2, array);
        
        int min = 8;
        int option = 8;
        
        for (int i = 0; i < 8; i++) {
//            printf("В варианте %i ходов %i\n", i, options[i]);
            if (options[i] > 0 && options[i] < min) {
                min = options[i];
                option = i;
            }
        }
//        printf("\nВариант %i подразумевает наименьшее количество возможных ходов.\n\n", option);
        
        if (option == 0) {
            h += 1;
            w += 2;
            array[h][w] = progress + 1;
        } else if (option == 1) {
            h += 2;
            w += 1;
            array[h][w] = progress + 1;
        } else if (option == 2) {
            h += 2;
            w -= 1;
            array[h][w] = progress + 1;
        } else if (option == 3) {
            h += 1;
            w -= 2;
            array[h][w] = progress + 1;
        } else if (option == 4) {
            h -= 1;
            w -= 2;
            array[h][w] = progress + 1;
        } else if (option == 5) {
            h -= 2;
            w -= 1;
            array[h][w] = progress + 1;
        } else if (option == 6) {
            h -= 2;
            w += 1;
            array[h][w] = progress + 1;
        } else if (option == 7) {
            h -= 1;
            w += 2;
            array[h][w] = progress + 1;
        } else if (option == 8) {
            if (array[h + 1][w + 2] == 0 && h + 1 >= 0 && h + 1 < HEIGHT && w + 2 >= 0 && w + 2 < WIDTH) {          // Ход 0
                array[h + 1][w + 2] = progress + 1;
            } else if (array[h + 2][w + 1] == 0 && h + 2 >= 0 && h + 2 < HEIGHT && w + 1 >= 0 && w + 1 < WIDTH) {   // Ход 1
                array[h + 2][w + 1] = progress + 1;
            } else if (array[h + 2][w - 1] == 0 && h + 2 >= 0 && h + 2 < HEIGHT && w - 1 >= 0 && w - 1 < WIDTH) {   // Ход 2
                array[h + 2][w - 1] = progress + 1;
            } else if (array[h + 1][w - 2] == 0 && h + 1 >= 0 && h + 1 < HEIGHT && w - 2 >= 0 && w - 2 < WIDTH) {   // Ход 3
                array[h + 1][w - 2] = progress + 1;
            } else if (array[h - 1][w - 2] == 0 && h - 1 >= 0 && h - 1 < HEIGHT && w - 2 >= 0 && w - 2 < WIDTH) {   // Ход 4
                array[h - 1][w - 2] = progress + 1;
            } else if (array[h - 2][w - 1] == 0 && h - 2 >= 0 && h - 2 < HEIGHT && w - 1 >= 0 && w - 1 < WIDTH) {   // Ход 5
                array[h - 2][w - 1] = progress + 1;
            } else if (array[h - 2][w + 1] == 0 && h - 2 >= 0 && h - 2 < HEIGHT && w + 1 >= 0 && w + 1 < WIDTH) {   // Ход 6
                array[h - 2][w + 1] = progress + 1;
            } else {                                                                                                // Ход 7
                array[h - 1][w + 2] = progress + 1;
            }
        } else {
            stop = 1;
            printf("Ошибка!\n\n");
        }
        print1(HEIGHT, WIDTH, array);
        printf("\n");
        progress++;
    } while (progress < HEIGHT * WIDTH && stop == 0);
    printf("Готово! Конь обошёл шахматную доску размером %i, %i.\n", WIDTH, HEIGHT);
    printf("\n");
}

// Основная программа

int main(int argc, const char * argv[]) {
    int select;
    do {
        menu();                                                 // Вызов функции меню
        scanf("%i", &select);
        printf("\n");
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
            default:
                printf("Некорректный ввод.\n");
                break;
        }
    } while (select != 0);
    return 0;
}

