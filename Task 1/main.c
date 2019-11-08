//
//  main.c
//  Homework
//
//  Created by Валерий on 07.11.2019.
//  Copyright © 2019 Valery Mironov. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void menu() {
    printf("Домашнее задание Валерия Миронова. Решены 14 из 14 заданий.\n");
    printf("Введите номер задания для просмотра или ноль для завершения программы: ");
}

void solution1() {
    printf("\nЗадание 1 – ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I = m / (h * h), где m – масса тела в килограммах, h – рост в метрах.\n---\n");
    float h;
    float m;
    printf("Введите рост человека в метрах: ");
    scanf("%f", &h);
    printf("Введите вес человека в килограммах: ");
    scanf("%f", &m);
    float I = m / (h * h);
    printf("Индекс массы человека: %.2f кг/м².\n\n", I);
}

void solution2() {
    printf("\nЗадание 2 – найти максимальное из четырёх чисел. Массивы не использовать.\n---\n");
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    printf("Введите первое число: ");
    scanf("%i", &a);
    printf("Введите второе число: ");
    scanf("%i", &b);
    printf("Введите третье число: ");
    scanf("%i", &c);
    printf("Введите чертвёртое число: ");
    scanf("%i", &d);
    if (a > b && a > c && a > d) {
        printf("Максимальное из четырёх чисел – число: %i\n\n", a);
    } else if (b > a && b > c && b > d) {
        printf("Максимальное из четырёх чисел – число: %i\n\n", b);
    } else if (c > a && c > b && c > d) {
        printf("Максимальное из четырёх чисел – число: %i\n\n", c);
    } else {
        printf("Максимальное из четырёх чисел – число: %i\n\n", d);
    }
}

void solution3() {
    printf("\nЗадание 3 – написать программу обмена значениями двух целочисленных переменных без использования третьей переменной.\n---\n");
    int a = 0;
    int b = 0;
    printf("Введите значение первой целочисленной переменной: ");
    scanf("%i", &a);
    printf("Введите значение второй целочисленной переменной: ");
    scanf("%i", &b);
    a += b;
    b = a - b;
    a -= b;
    printf("Теперь значение первой переменной %i, а значение второй %i.\n\n", a, b);
}

void solution4() {
    printf("\nЗадание 4 – написать программу нахождения корней заданного квадратного уравнения.\n---\n");
    printf("Дано квадратное уравнение x² − 8x + 12 = 0.\n");
    float a = 1;
    float b = 8;
    float c = 12;
    float x1 = 0;
    float x2 = 0;
    int result;
    double D = b * b - 4 * a * c;
    double root = sqrt(D);
    if (a == 0) {
        x1 = -c / b;
        result = 0;
    } else if (D < 0) {
        result = -1;
    } else if (D == 0) {
        x1 = (-1 * b + root) / 2 * a; // Выводим один корень
        result = 0;
    } else {
        // D > 0
        x1 = (-1 * b + root) / 2 * a; // Выводим первый корень
        x2 = (-1 * b - root) / 2 * a; // Выводим второй корень
        result = 1;
    }
    switch (result) {
        case 0:
            printf("Уравнение содержит один корень – это число %.2f.\n\n", x1);
            break;
        case 1:
            printf("Уравнение содержит два корня – это числа %.2f и %.2f.\n\n", x1, x2);
            break;
        case -1:
            printf("Уравнение не содержит корней.\n\n");
            break;
        default:
            printf("Неожиданный вывод: %d\n\n", result);
            break;
    }

}

void solution5() {
    printf("\nЗадание 5 – с клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится.\n---\n");
    int month;
    printf("Введите номер месяца: ");
    scanf("%i", &month);
    if (month == 12 || month <= 2) {
        printf("%i месяц относится к зимнему времени года.\n\n", month);
    } else if (month > 2 && month <= 5) {
        printf("%i месяц относится к весеннему времени года.\n\n", month);
    } else if (month > 5 && month <= 8) {
        printf("%i месяц относится к летнему времени года.\n\n", month);
    } else if (month > 8 && month <= 11) {
        printf("%i месяц относится к осеннему времени года.\n\n", month);
    } else {
        printf("Введено номер несуществующего месяца.\n\n");
    }
}

void solution6() {
    printf("\nЗадание 6 – ввести возраст человека (от 1 до 150 лет) и вывести его вместе со словом «год», «года» или «лет».\n---\n");
    int age = 0;
    do {
        printf("Введите возраст от человека от 1 до 150 лет: ");
        scanf("%i", &age);
        if (age < 1 || age > 149) {
            printf("Введённый возраст не соотсвествует условиям.\n");
        } else {
            if ((age % 10) == 1) {
                printf("Человеку %i год.\n\n", age);
                break;
            } else if ((age % 10) > 1 && (age % 10) < 5) {
                printf("Человеку %i года.\n\n", age);
                break;
            } else {
                printf("Человеку %i лет.\n\n", age);
                break;
            }
        }
    } while (age < 1 || age > 149);
}

void solution7() {
    printf("\nЗадание 7 – склавиатуры вводятся числовые координаты двух полей шахматной доски (x1, y1, x2, y2). Требуется определить, относятся ли к поля к одному цвету или нет.\n---\n");
    struct field {
        int x;
        int y;
    };
    typedef struct field field;
    field f1, f2;
    printf("Введите значение оси X для первой координаты: ");
    scanf("%i", &f1.x);
    printf("Введите значение оси Y для первой координаты: ");
    scanf("%i", &f1.y);
    printf("Введите значение оси X для второй координаты: ");
    scanf("%i", &f2.x);
    printf("Введите значение оси Y для второй координаты: ");
    scanf("%i", &f2.y);
    if ((f1.x % 2 == f1.y % 2) && (f2.x % 2 == f2.y % 2)) {
        printf("Обе координаты относятся к полям с одним цветом.\n\n");
    } else {
        printf("Координаты относятся к полям с разным цветом.\n\n");
    }
}

void solution8() {
    printf("\nЗадание 8 – ввести a и b и вывести квадраты и кубы чисел от a до b.\n---\n");
    int a;
    int b;
    printf("Введите число a: ");
    scanf("%i", &a);
    printf("Введите число b: ");
    scanf("%i", &b);
    if (a < b) {
        for (a = a; a <= b; a++) {
            printf("%i² = %i\t%i³ = %i.\n", a, (a * a), a, (a * a * a));
        }
    } else {
        for (a = a; a >= b; a--) {
            printf("%i² = %i\t%i³ = %i.\n", a, (a * a), a, (a * a * a));
        }
    }
    printf("\n");
}

void solution9() {
    printf("\nЗадание 9 – даны целые положительные числа N и K. Используя только операции сложения и вычитания, найти частное от деления нацело N на K, а также остаток от этого деления.\n---\n");
    int N = 37;
    int K = 10;
    int remainder = 0;
    printf("N = %i, K = %i\n", N, K);
    do {
        N -= K;
        remainder++;
    } while (N >= K);
    printf("Частное от деления нацело N на K = %i.\n", remainder);
    printf("Остаток от деления нацело N на K = %i.\n\n", N);
}

void solution10() {
    printf("\nЗадание 10 – дано целое число N > 0. С помощью операций деления нацело и взятия остатка от деления определить, имеются ли в записи числа N нечётные цифры.\nЕсли имеются, то вывести True, если нет – вывести False.\n---\n");
    int N;
    int remainder;
    do {
        printf("Введите целое числое больше нуля: ");
        scanf("%i", &N);
    } while (N <= 0);
    do {
        remainder = N % 10;
        if (remainder % 2 != 0) {
            break;
        }
        N = (N - remainder) / 10;
    } while (N != 0);
    if (remainder % 2 != 0) printf("True.\n\n");
    else printf("False.\n\n");
}

void solution11() {
    printf("\nЗадание 11 – с клавиатуры вводятся числа, пока не будет введён 0. Подсчитать среднее арифметическое всех положительных чётных чисел, оканчивающихся на 8.\n---\n");
    int number, sum = 0, i = 0;
    do {
        printf("Введите число: ");
        scanf("%i", &number);
        if ((number % 2 == 0) && ((number % 10 == 8) || (number == 8)) && number > 0) {
            sum += number;
            i++;
        } else {
            continue;
        }
    } while (number != 0);
    if (i > 0) {
        float average = sum / i;
        printf("Среднее арифметическое всех положительных чётных чисел, оканчивающихся на 8: %.2f.\n\n", average);
    } else {
        printf("Вы не ввели ни одного положительного чётного числа, оканчивающегося на 8.\n\n");
    }
}

void solution12() {
    printf("\nЗадание 12 – написать функцию нахождения максимального из трёх чисел.\n---\n");
    int a = 0;
    int b = 0;
    int c = 0;
    printf("Введите первое число: ");
    scanf("%i", &a);
    printf("Введите второе число: ");
    scanf("%i", &b);
    printf("Введите третье число: ");
    scanf("%i", &c);
    if (a > b && a > c) {
        printf("Максимальное из трёх чисел – число: %i\n\n", a);
    } else if (b > a && b > c) {
        printf("Максимальное из трёх чисел – число: %i\n\n", b);
    } else {
        printf("Максимальное из трёх чисел – число: %i\n\n", c);
    }
}

void solution13() {
    printf("\nЗадание 13 – написать функцию, генерирующую случайное число от 1 до 100.\n---\n");
    int x, a, b, m, i, moduls;
    x = 100;
    a = 3;
    b = 2;
    m = 100;
    moduls = 100;
    printf("С использованием стандартной функции rand().\n");
    for (i = 0; i < moduls; i++) {
        printf("%i ", rand() % 100 + 1);
    }
    printf("\n");
    printf("Без использования стандартной функции rand().\n");
    for (i = 0; i < moduls; i++) {
        x = (((a * x + b) % m) + 1);
        printf("%i ", x);
    }
    printf("\n\n");
}

void solution14() {
    printf("\nЗадание 14 – автоморфные числа. Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата. Например, 25 \\ :sup: '​2' = 625. Напишите программу, которая получает на вход натуральное число N и выводит на экран все автоморфные числа, не превосходящие N.\n---\n");
    long int N;
    printf("Введите натуральное число: ");
    scanf("%li", &N);
    
    for (int number = 0; (number * number) <= N; number++) {                            // Цикл проходится по всем числам, чей квадрат не привосходит N
        int amount = 0;                                                                 // Обнуляем длину числа
        int a = (number * number);
        do {
            amount++;
            a /= 10;
        } while (a != 0);
        
        int exponent = 10;
        for (int i = 1; i < amount; i++) {
            exponent *= exponent;
        }
        
        if (((number * number) % exponent) == number) {
            printf("Число %i является автоморфным и не привосходит %li.\n", number, N);
        }
    }
    printf("\n\n");
}

int main(int argc, const char * argv[]) {
    int select = 0;
    do {
        menu();
        scanf("%i", &select);
        switch (select) {
            case 1:
                solution1();
                break;
            case 2:
                solution2();
                break;
            case 3:
                solution3();
                break;
            case 4:
                solution4();
                break;
            case 5:
                solution5();
                break;
            case 6:
                solution6();
                break;
            case 7:
                solution7();
                break;
            case 8:
                solution8();
                break;
            case 9:
                solution9();
                break;
            case 10:
                solution10();
                break;
            case 11:
                solution11();
                break;
            case 12:
                solution12();
                break;
            case 13:
                solution13();
                break;
            case 14:
                solution14();
                break;
            case 0:
                printf("Спасибо за внимание.\n");
                break;
            default:
                printf("Неверный ввод.\n");
        }
    } while (select != 0);
    return 0;
}
