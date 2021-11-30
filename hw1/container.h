//
// Created by kimigaev on 29.11.2021.
//

#ifndef HW1MY_CONTAINER_H
#define HW1MY_CONTAINER_H

#include <stddef.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include "wisdom.h"
#include "cstring_tools.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
typedef struct {
    enum {
        max_len = 50000
    }; // максимальная длина
    size_t size; // текущая длина
    wisdom *data[max_len];
} container;

// Инициализация контейнера
void ContainerInit(container *c);

// Очистка контейнера от элементов (освобождение памяти)
void ContainerClear(container *c);

// Ввод содержимого контейнера из указанного потока
void ContainerIn(container *c, FILE *file);

// Случайный ввод содержимого контейнера
void ContainerInRnd(container *c, size_t size);

// Вывод содержимого контейнера в указанный поток
void ContainerOut(container *c, FILE *file);

// Сортировка контейнера по значимой строке
void ContainerSort(container *c);

#endif //HW1MY_CONTAINER_H
