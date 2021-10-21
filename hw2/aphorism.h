//
// Created by kimigaev on 20.10.2021.
//

#ifndef HW2_APHORISM_H
#define HW2_APHORISM_H


#include <cstdio>
#include "wisdom.h"

class Aphorism : public Wisdom {
private:
    char *author_ = (char *) calloc(DATA_SIZE, sizeof(char));
    size_t author_size_ = DATA_SIZE;

public:
    Aphorism() = default;

    ~Aphorism();

    Aphorism(const char *text, const char *author);

    void In(FILE *file) override;

    void Out(FILE *file) override;
};


#endif //HW2_APHORISM_H
