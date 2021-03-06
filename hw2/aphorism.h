//
// Created by kimigaev on 20.10.2021.
//

#ifndef HW2_APHORISM_H
#define HW2_APHORISM_H


#include <cstdio>
#include "wisdom.h"

class Aphorism : public Wisdom {
private:
    char *author_;
    size_t author_size_;

public:
    Aphorism();

    ~Aphorism();

    Aphorism(const char *text, const char *author);

    size_t In(FILE *file) override;

    void Out(FILE *file) override;
};


#endif //HW2_APHORISM_H
