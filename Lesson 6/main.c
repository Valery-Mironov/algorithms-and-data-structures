//
//  main.c
//  Homework
//
//  Created by Валерий on 25.11.2019.
//  Copyright © 2019 Valery Mironov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256

typedef int T;

typedef struct Node {
    T data;                                         // Данные
    struct Node * left;                             // Ссылка на левую ветвь
    struct Node * right;                            // Ссылка на правую ветвь
    struct Node * parent;                           // Ссылка на родителя
} Node;

typedef struct Card {
    char name[SIZE];                                // Имя
    int age;                                        // Возраст
    int number;                                     // Табельный номер
} Card;

typedef struct Database {
    Card info;
    struct Database * left;                         // Ссылка на левую ветвь
    struct Database * right;                        // Ссылка на правую ветвь
    struct Database * parent;                       // Ссылка на родителя
} Database;

void menu(void);                                    // Меню домашнего задания
void task1(void);                                   // Задание 1
void task2(void);                                   // Задание 2
void task3(void);                                   // Задание 3
void printTree(Node * root);                        // Распечатка двоичного дерева в виде скобочной последовательности
void insert(Node ** head, int value);               // Вставка узла
void preOrderTravers(Node * root);                  // КЛП – «корень – левый – правый»​(обход в прямом порядке, pre-order)
void inOrderTravers(Node * root);                   // ЛКП – «левый – корень – правый»​(симметричный обход, in-order)
void postOrderTravers(Node * root);                 // ЛПК – «левый–правый–корень»​(обход в обратном порядке, post-order)
void binarySearch(int number, Node * root);         // Бинарный поиск по дереву
void fileRead(int choice, int * numbers);           // Чтение данных из файла и конверсия из формата строки в формат чисел

void insertCard(Database ** head, char * name, int age, int number);
void printStudentCard(Database * root);
void binaryCardSearch(Database * root, int number);

Node* getFreeNode(T value, Node *parent);           // Создание нового узла
Database * getFreeCard(char * name, int age, int number, Database * parent);


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
    printf("2 задание – решено;\n");
    printf("3 задание – решено.\n");
    printf("Введите номер задания для просмотра, или ноль для выхода: ");
}

/* Задача 1 ######################################################################################################################################### */

void task1() {
    printf("Реализовать простейшую хэш-функцию. На вход функции подается строка, на выходе получается сумма кодов символов.\n");
    printf("\n");
    char string[SIZE];                              // Инициализация массива для хранения стоки
    printf("Введите строку: ");                     // Запрос ввода строки
    scanf("%s", string);                            // Запись ввода с экрана в массив хранящий строку
    int hash = 0;                                   // Инициализация массива для хранения хеша
    for (int i = 0; string[i] != '\0'; i++) {       // Цикл перебирающий символы  до конца строки
        hash = (hash + (unsigned char)string[i]);   // Суммирование кодов символов
    }
    printf("Сумма кодов символов: %i.\n", hash);    // Вывод суммы кодов символов
    printf("\n\n");
}

void printTree(Node * root) {                       // Распечатка двоичного дерева в виде скобочной последовательности
    if (root) {
        printf("%d", root->data);
        if (root->left || root->right) {
            printf("(");
            if (root->left) {
                printTree(root->left);
            } else {
                printf("NULL");
            }
            printf(",");
            if (root->right) {
                printTree(root->right);
            } else {
                printf("NULL");
            }
            printf(")");
        }
    }
}

Node * getFreeNode(T value, Node * parent) {        // Создание нового узла
    Node * tmp = (Node *) malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

void insert(Node ** head, int value) {              // Вставка узла
    Node * tmp = NULL;
    if (* head == NULL) {
        * head = getFreeNode(value, NULL);
        return;
    }
    tmp = * head;
    while (tmp) {
        if (value > tmp->data) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = getFreeNode(value, tmp);
                return;
            }
        } else if (value < tmp->data) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = getFreeNode(value, tmp);
                return;
            }
        } else {
            exit(2);                                // Дерево построено неправильно
        }
    }
}

void preOrderTravers(Node * root) {                 // КЛП – «корень – левый – правый»​(обход в прямом порядке, pre-order)
    if (root) {
        printf("%d ", root->data);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

void inOrderTravers(Node * root) {                  // ЛКП – «левый – корень – правый»​(симметричный обход, in-order)
    if (root) {
        preOrderTravers(root->left);
        printf("%d ", root->data);
        preOrderTravers(root->right);
    }
}

void postOrderTravers(Node * root) {                // ЛПК – «левый–правый–корень»​(обход в обратном порядке, post-order)
    if (root) {
        preOrderTravers(root->left);
        preOrderTravers(root->right);
        printf("%d ", root->data);
    }
}

void binarySearch(int number, Node * root) {        // Бинарный поиск по дереву
    if (root) {
        if (number == root->data) {
            printf("Число %d, найдено! Адрес структуры хрянящей число: %p.\n", number, root);
        } else if (number > root->data) {
            binarySearch(number, root->right);
        } else {
            binarySearch(number, root->left);
        }
    } else {
        printf("Число %d, не найдено.\n", number);
    }
}

void fileRead(int choice, int * numbers) {          // Чтение данных из файла и конверсия из формата строки в формат чисел
    char text[SIZE];                                // Инициализация массива для записи строки из файла
    FILE * file = NULL;                             // Инициализация переменной для хранения данных из файла
    if (choice == 1) {                              // Если выбран файл 1...
        file = fopen("data1.txt", "r");             // Присвоение переменной «file» указателя на реальный файл, где «r» – режим чтения
    } else if (choice == 2) {                       // Если выбран файл 2...
        file = fopen("data2.txt", "r");             
    } else if (choice == 3) {                       // Если выбран файл 1...
        file = fopen("data3.txt", "r");
    } else {                                        // Другое...
        printf("Ошибка выбора файла.\n");
    }
    if (file == NULL) {                             // Если файл пустой
        puts("Невозможно открыть файл.");           // Вевести информацию об ошибке
        exit(1);                                    // Завершить программу с кодом 1
    }
    int i = 0;                                      // Инициализация переменной счётчика
    while (!feof(file)) {                           // Функция !feof возвращает ноль если конец файла не достигнут
        fscanf(file, "%s", text);                   // Считываем строки из файла и записываем в массив
        //        printf("%s ", text);
        numbers[i] = atoi(text);                    // Каждое число переводим из формата строки в формат числа
        i++;                                        // Увеличиваем переменную счётчика на еденицу
    }
//    printf("Распечатка массива чисел: ");
//    for(int j = 0; j < i; j++) {
//        printf("%i ", numbers[j]);
//    }
//    printf("\n");
    fclose(file);                                   // Закрываем файл
}

/* Задача 2 ######################################################################################################################################### */

void task2() {
    printf("Переписать программу, реализующее двоичное дерево поиска:\n");
    printf("\n");
    int numbers[SIZE];                              // Инициализация массива для хранения чисел, прочитаных из файла
    Node * Tree = NULL;                             // Инициализация пустой структуры
    fileRead(1, numbers);                           // Вызов функции чтения и конверсии чисел из файла 1
    for (int i = 0; i < 15; i++) {
        insert(&Tree, numbers[i]);
    }
    printTree(Tree);                                // Распечатка двоичного дерева в виде скобочной последовательности
    printf("\n\n");
    
    /* Пункт a. ===================================================================================================================================== */
    
    printf("a. Добавить в него обход дерева различными способами.\n");
    printf("\n");
    printf("КЛП: ");
    preOrderTravers(Tree);
    printf("\n");
    printf("ЛКП: ");
    inOrderTravers(Tree);
    printf("\n");
    printf("ЛПК: ");
    postOrderTravers(Tree);
    printf("\n\n");
    
    /* Пункт b. ===================================================================================================================================== */
    
    printf("b. Реализовать поиск в нём.\n");
    printf("\n");
    int number;
    printf("Введите число, которое нужно найти в дереве: ");
    scanf("%d", &number);
    binarySearch(number, Tree);
    printf("\n");
    
    /* Пункт c. ===================================================================================================================================== */
    
    printf("c. Добавить в программу обработку командной строки с помощью которой можно указывать, из какого файла считывать данные, каким образом обходить дерево.\n");
    printf("\n");
    int choice = 0;                                 // Инициализация переменной для хранения выбора
    printf("1 – файл data1.txt с адаптированным для бинарного поиска порядком чисел.\n");
    printf("2 – файл data2.txt с отсортированными в порядке возрастания числами.\n");
    printf("3 – файл data3.txt с отсортированными в обратном порядке числами.\n");
    printf("Укажите из какого файла считывать данные: ");
    scanf("%i", &choice);                           // Считываем выбор файла
    printf("\n");
    fileRead(choice, numbers);                      // Вызов функции чтения и конверсии чисел из выбранного файла
    Node * anotherTree = NULL;                      // Инициализация пустой структуры другого дерева
    for (int i = 0; i < 15; i++) {                  // Счётный цикл для перебора чисел из массива
        insert(&anotherTree, numbers[i]);           // Отправка чисел на запись в структуру дерева
    }
    printTree(anotherTree);                         // Распечатка двоичного дерева в виде скобочной последовательности
    printf("\n\n");
    printf("1 – обход в прямом порядке.\n");
    printf("2 – симметричный обход.\n");
    printf("3 – обход в обратном порядке.\n");
    printf("Введите номер способа: ");
    scanf("%i", &choice);                           // Считываем выбор способа
    if (choice == 1) {
        printf("\n");
        printf("Результат обхода в прямом порядке: ");
        preOrderTravers(anotherTree);
    } else if (choice == 2) {
        printf("\n");
        printf("Результат симметричного обхода: ");
        inOrderTravers(anotherTree);
    } else if (choice == 3) {
        printf("\n");
        printf("Результат обхода в обратном порядке: ");
        postOrderTravers(anotherTree);
    } else {
        printf("Некорректный ввод.");
    }
    printf("\n\n\n");
}

/* Задача 3 ######################################################################################################################################### */

void task3() {
    printf("Разработать базу данных студентов, состоящую из полей «Имя», «Возраст», «Табельный номер», в которой использовать все знания, полученные на уроках.\nДанные следует считать в двоичное дерево поиска.\nРеализовать поиск по какому-нибудь полю базы данных.\n");
    printf("\n");
    char name[SIZE];                                // Инициализация массива для записи имени
    unsigned int age;                               // Инициализация переменной для записи возраста
    int number = 0;                                 // Инициализация переменной для записи табильного номера
    int add = 1;                                    // Инициализация переменной для проверки добавления очередной карточки
    Database *Students = NULL;                      // Инициализация пустой структуры
    while (add == 1) {                              // Пока переменная проверки добавления очереди равна 1...
        printf("Введите имя: ");
        scanf("%s", name);
        printf("Введите возраст: ");
        scanf("%d", &age);
        number++;
        printf("Карточке присвоен табильный номер %i.\n", number);
        insertCard(&Students, name, age, number);
        printf("Если хотите добавить ещё одну карточку студента введите 1, другое – выход: ");
        scanf("%i", &add);
    }
    int search;                                     // Инициализация переменной искомого табельного номера
    printf("Введите табильный номер студента для поиска его карточки: ");
    scanf("%i", &search);
    binaryCardSearch(Students, search);             // Поиск карточки с заданым табильным номером
    printf("\n\n");
}

Database * getFreeCard(char name[SIZE], int age, int number, Database * parent) {
    Database * tmp = (Database*) malloc(sizeof(Database));
    strcpy(tmp->info.name, name);
    tmp->left = tmp->right = NULL;
    tmp->info.age = age;
    tmp->info.number = number;
    tmp->parent = parent;
    return tmp;
}

void insertCard(Database ** head, char * name, int age, int number) {
    Database * tmp = NULL;
    if (* head == NULL) {
        * head = getFreeCard(name, age, number, NULL);
        return;
    }
    tmp = * head;
    while (tmp) {
        if (number > tmp->info.number) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = getFreeCard(name, age, number, tmp);
                return;
            }
        } else if (number < tmp->info.number) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = getFreeCard(name, age, number, tmp);
                return;
            }
        } else {
            exit(2);                                // Дерево построено неправильно
        }
    }
}

void binaryCardSearch(Database * root, int number) {
    if (root) {
        if (number == root->info.number) {
            printf("Карточка с табильным номером %d, найдена! Адрес структуры хрянящей её: %p.\n", number, root);
            printf("Имя – %s.\n", root->info.name);
            printf("Возраст – %d.\n", root->info.age);
            printf("Табильный номер – %i.\n", root->info.number);
        } else if (number > root->info.number) {
            binaryCardSearch(root->right, number);
        } else {
            binaryCardSearch(root->left, number);
        }
    } else {
        printf("Карточка с табильным номером %d, не найдена.\n", number);
    }
}
