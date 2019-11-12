//
//  main.c
//  Homework
//
//  Created by Валерий on 11.11.2019.
//  Copyright © 2019 Valery Mironov. All rights reserved.
//

#include <stdio.h>

void menu() {
    printf("Домашнее задание Валерия Миронова. Решены 2 из 3 заданий.\n");
    printf("Введите номер задания для просмотра или ноль для завершения программы: ");
}

// Задание 1

int binary[256];

void conversion(int decimal, int i) {
    binary[i] = decimal % 2;
    if (decimal > 0) {
        conversion((decimal - (decimal % 2)) / 2, i + 1);
    }
    else {
        while (i >= 0) {
            printf("%i", binary[i]);
            i--;
        }
    }
}

void task1() {
    printf("\nЗадание 1 – реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.\n");
    int number;
    printf("Введите десятичное число: ");
    scanf("%d", &number);
    printf("Введённое число в бинарном формате: ");
    conversion(number, 0);
    printf(".\n\n");
}

// Задание 2, подпункт «a»

void task1a() {
    printf("\na – без рекурсии.\n");
    int i = 1;
    int number;
    int exponent;
    printf("Введите число: ");
    scanf("%i", &number);
    printf("Введите степень: ");
    scanf("%i", &exponent);
    int result = number;
    if (exponent == 0) {
        result = 1;
    } else if (exponent == 1) {
        result = number;
    } else {
        while (i < exponent) {
            result *= number;
            i++;
        }
    }
    printf("Результат возведения числа %i в степень %i равен %i.\n", number, exponent, result);
}

// Задание 2, подпункт «b»

int exponentiation1(int number, int exponent, int result, int i) {
    if (i == exponent) {
        return result;
    } else if (i > exponent) {
        return 1;
    } else {
        return exponentiation1(number, exponent, result * number, i + 1);
    }
}

void task1b() {
    printf("\nb – рекурсивно.\n");
    int number;
    int exponent;
    printf("Введите число: ");
    scanf("%i", &number);
    printf("Введите степень: ");
    scanf("%i", &exponent);
    printf("Результат возведения числа %i в степень %i равен %i.\n", number, exponent, exponentiation1(number, exponent, number, 1));
}

// Задание 2, подпункт «c»

int exponentiation2(int number, int exponent, int result) {
    if (exponent == 0)  {
        printf("1\n");
        return 1;
    } else if (exponent == 1) {
        printf("2\n");
        return result;
    } else {
        if (exponent % 2 != 0) {
            printf("3-1\n");
            return result * exponentiation2(number, (exponent - 1) / 2, result * result);
        } else if (exponent == 2) {
            printf("3-2\n");
            return result * result;
        } else {
            printf("3-3\n");
            return exponentiation2(number, exponent / 2, result * result);
        }
    }
}

void task1c() {
    printf("\nc – рекурсивно, используя свойство чётности степени.\n");
    int number;
    int exponent;
    printf("Введите число: ");
    scanf("%i", &number);
    printf("Введите степень: ");
    scanf("%i", &exponent);
    printf("Результат возведения числа %i в степень %i равен %i.\n", number, exponent, exponentiation2(number, exponent, number));
    
}

// Задание 2, вызов подпунктов

void task2() {
    printf("\nЗадание 2 – Реализовать функцию возведения числа a в степень b:\n");
    task1a();
    task1b();
    task1c();
    printf("\n");
}

// Задание 3

void task3() {
    int program = 0;
    int min = 3;
    int max = 20;
    int calculator;
    int array[max - min];
    int i = 0, a, b;
    
    /*
     calculator *= 2
     calculator += 1
     */
    
    // Находим максимально возможное число умножений на 2
    int factors = 0;
    for (calculator = min; (calculator * 2) <= max; calculator *= 2) {
        factors++;
    }
    calculator = min;
    printf("Максимальное число множителей: %i\n", factors);
    
    // Пока позиция первого множетеля не достигла позиции, после которого произведение будет больше или равно максимальному числу, перебираем варианты
    a = -1;
    while ((calculator * 2) < max) {
        calculator = min;
        array[a] = 2;
        
        // Цикл for
        for (i = 0; i < (max - min); i++) {
            
//            for (b = 0; b < (max - min - i); b++) {
//                if (array[i + b] != 2) {
//                    array[i + b] = 2;
//                } else {
//                    array[i + b] = 1;
//                }
//            }
            
            // Если позиция массива предназначена для множителя – умножить на 2, если нет – добавить 1
            if (array[i] == 2) {
                calculator *= 2;
                printf("X2, ");
            } else {
                calculator +=1;
                printf("+1, ");
            }
            
            // Если резульат сложений и умножений равен max, засчитать метод, обновить calculator и прервать цикл
            if (calculator == max) {
                program++;
                calculator = min;
                break;
            } else {
                continue;
            }
        }
        printf("\na = %i, calcualtor = %i\n", a, calculator);
        // Цикл for
        
        array[a] = 1;
        a++;
    }
    printf("\n");
    printf("Определены %i программ, которые преобразуют число %i в число %i.\n", program, min, max);
}

// Вызов решений домашних заданий

int main(int argc, const char * argv[]) {
    int select;
    do {
        menu();
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
            default:
                printf("Некорректный ввод.\n");
                break;
        }
    } while (select != 0);
    return 0;
}
