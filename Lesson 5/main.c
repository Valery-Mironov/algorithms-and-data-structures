//
//  main.c
//  Homework
//
//  Created by Валерий on 20.11.2019.
//  Copyright © 2019 Valery Mironov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxN 1024
#define T char

struct TStack {
    int N;
    T Data[MaxN];
};
struct TStack Stack1;
struct TStack Stack2;
struct TStack Stack3;

void push(struct TStack *Stack, T data) {
    Stack->N++;
    Stack->Data[Stack->N] = data;
}

T pop(struct TStack *Stack) {
    if (Stack->N != -1) return Stack->Data[Stack->N--];
    else return 0;
}

void init(struct TStack *Stack) {
    Stack->N = -1;
}

void conversion(int decimal) {
    if (decimal % 2 == 0) push(&Stack1, '0');
    else push(&Stack1, '1');
    if (decimal > 0) {
        conversion((decimal - (decimal % 2)) / 2);
    }
}

void leftParentheses(char array[32]) {
    for (int i = 0; array[i] != '\0'; i++) {
        if (array[i] == '[') {
            push(&Stack2, '[');
        } else if (array[i] == '(') {
            push(&Stack2, '(');
        } else if (array[i] == '{') {
            push(&Stack2, '{');
        } else {
            continue;
        }
    }
}

void parenthesisComparison(struct TStack *Stack, char array[32]) {
    int test = 0;
    for (int i = 0; array[i] != '\0'; i++) {
        if (array[i] == ']') {
            if (pop(&Stack2) == '[') {
                continue;
            } else {
                test++;
                break;
            }
        } else if (array[i] == ')') {
            if (pop(&Stack2) == '(') {
                continue;
            } else {
                test++;
                break;
            }
        } else if (array[i] == '}') {
            if (pop(&Stack2) == '{') {
                continue;
            } else {
                test++;
                break;
            }
        } else {
            continue;
        }
    }
    if (Stack->N != -1) {
        test++;
    }
    if (test == 0) {
        printf("Введённая скобочная последовательность правильная.");
    } else {
        printf("Введённая скобочная последовательность неправильная.");
    }
}

void menu(void);                                    // Меню домашнего задания
void task1(void);                                   // Задание 1
void task2(void);                                   // Задание 2
void task3(void);                                   // Задание 3
void task4(void);                                   // Задание 4
void task5(void);                                   // Задание 5
void task6(void);                                   // Задание 6
void task7(void);                                   // Задание 7

int main(int argc, const char * argv[]) {
    printf("Домашнее задание Валерия Миронова.\n");
    printf("\n");
    int select;
    do {
        init(&Stack1);
        init(&Stack2);
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
            case 5:
                task5();
                break;
            case 6:
                task6();
                break;
            case 7:
                task7();
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
    printf("2 задание – не решено;\n");
    printf("3 задание – решено;\n");
    printf("4 задание – решено;\n");
    printf("5 задание – не решено;\n");
    printf("6 задание – решено частично;\n");
    printf("7 задание – не решено.\n");
    printf("Введите номер задания для просмотра, или ноль для выхода: ");
}

void task1() {
    printf("Задание 1.\n");
    printf("Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.\n");
    printf("\n");
    int number;                                     // Переменная десятичного числа
    printf("Введите десятичное число: ");
    scanf("%i", &number);
    conversion(number);                             // Конвертирование числа в бинарный формат
    while (Stack1.N != -1) {
        printf("%c", pop(&Stack1));
    }
    printf("\n\n\n");
}

void task2() {
    printf("Задание 2.\n");
    printf("Добавить в программу «Реализация стека на основе односвязного списка» проверку на выделение памяти.\n");
    printf("Если память не выделяется, то должно выводиться соответствующее сообщение.\n");
    printf("Постарайтесь создать ситуацию, когда память не будет выделяться (добавлением большого количества данных).\n");
    printf("\n");
    printf("Не решено.\n");
    printf("\n\n");
}

void task3() {
    printf("Задание 3.\n");
    printf("Написать программу, которая определяет, является ли введённая скобочная последовательность правильной.\n");
    printf("Примеры правильных скобочных выражений – (), ([])(), {}(), ([{}]), неправильных – )(, ())({), (, ])}), ([(]), для скобок – [, (, {.\n");
    printf("Например: (2+(2*2)) или [2/{5*(4+7)}].\n");
    printf("\n");
    char array1[32] = "[2/{5*(4+7)}]";
    printf("Введенная скобочная последовательность: %s\n", array1);
    leftParentheses(array1);
    parenthesisComparison(&Stack2, array1);
    printf("\n\n");
    char array2[32] = "[2/{5*(4+7(}]";
    printf("Введенная скобочная последовательность: %s\n", array2);
    leftParentheses(array2);
    parenthesisComparison(&Stack2, array2);
    printf("\n\n");
    char array3[32] = "[2/5*(4+7)}]";
    printf("Введенная скобочная последовательность: %s\n", array3);
    leftParentheses(array3);
    parenthesisComparison(&Stack2, array3);
    printf("\n\n\n");
}

void task4() {
    printf("Задание 4.\n");
    printf("Создать функцию, копирующую односвязный список (то есть создающую в памяти копию односвязного списка без удаления первого списка).\n");
    printf("\n");
    int number;                                     // Переменная десятичного числа
    printf("Введите десятичное число: ");
    scanf("%i", &number);
    conversion(number);
    for (int i = 0; i <= Stack1.N; i++) {
        push(&Stack3, Stack1.Data[i]);
    }
    printf("Распечатка копии стека: ");
    while (Stack3.N != -1) {
        printf("%c", pop(&Stack3));
    }
    printf("\n");
    printf("Распечатка оригиала стека: ");
    while (Stack1.N != -1) {
        printf("%c", pop(&Stack1));
    }
    printf("\n\n\n");
}

void task5() {
    printf("Задание 5.\n");
    printf("Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную.\n");
    printf("\n");
    printf("Не решено.\n");
    printf("\n\n");
}

void task6() {
    printf("Задание 6.\n");
    printf("Реализовать очередь.\n");
    printf("\n");
    printf("1 – с использованием массива:\n");
    int array[MaxN];
    int rear = 0;       // Указывает на элемент, которые заполняется
    int front = 0;      // Указывает на голову очереди
    int choice;
    do {
        printf("Чтобы добавить элемент в очередь введите 0, чтобы извлечь 1, другое, чтобы выйти: ");
        scanf("%i", &choice);
        if (choice == 0) {
            if (rear + 1 <= MaxN) {
                if (rear + 1 != front) {
                    printf("Введите число для записи в очередь: ");
                    scanf("%i", &array[rear]);
                    rear++;
                } else {
                    printf("Элемент занят. Сперва извлеките элемент.\n");
                }
            } else {
                if (front == 0) {
                    printf("Элемент занят. Сперва извлеките элемент.\n");
                } else {
                    printf("Введите число для записи в очередь: ");
                    scanf("%i", &array[rear]);
                    rear = 0;
                }
            }
        } else if (choice == 1) {
            if (front == rear) {
                printf("Нет элементов в очереди для извлечения.\n");
            } else {
                if (front + 1 < MaxN) {
                    printf("Извлечённый элемент: %i.\n", array[front]);
                    front++;
                } else {
                    if (rear == MaxN) {
                        printf("Извлечённый элемент: %i.\n", array[front]);
                        front = 0;
                        rear = 0;
                    } else {
                        printf("Извлечённый элемент: %i.\n", array[front]);
                        front = 0;
                    }
                }
            }
        } else {
            break;
        }
    } while (choice == 0 || choice == 1);
    printf("\n");
    printf("2 – c использованием односвязного списка:\n");
    printf("Не решено.\n");
    printf("\n\n");
}

void task7() {
    printf("Задание 7.\n");
    printf("Реализовать двустороннюю очередь.\n");
    printf("\n");
    printf("Не решено.\n");
    printf("\n\n");
}
