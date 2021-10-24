//
// Created by kimigaev on 21.10.2021.
//

#ifndef HW2_CONTAINER_H
#define HW2_CONTAINER_H

#include <cstdio>
#include "wisdom.h"

class Container {
public:
    Container(int s);

    ~Container();

    void In(size_t size, FILE *file);

    void In(FILE *file);

    void InRnd(size_t n);

    void Out(FILE *file);

    double Perimeter();

    void Clear();

    void Sort();

private:
    size_t size_, capacity_;
    Wisdom **data_;
};

#endif //HW2_CONTAINER_H
