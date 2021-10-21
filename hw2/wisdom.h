//
// Created by kimigaev on 19.10.2021.
//

#ifndef HW2_WISDOM_H
#define HW2_WISDOM_H


#include <cstring>
#include <cstdlib>
#include "constants.h"

class Wisdom {
protected:
    char *text_ = (char *) calloc(DATA_SIZE, sizeof(char));
    size_t text_size_ = DATA_SIZE;

public:
    Wisdom() = default;

    Wisdom(const char *text);

    ~Wisdom();

    virtual void In(FILE *file);

    virtual void Out(FILE *file);

    virtual double PunctuationDivide();

    bool operator<(const Wisdom &rhs) const;

    bool operator>(const Wisdom &rhs) const;

    bool operator<=(const Wisdom &rhs) const;

    bool operator>=(const Wisdom &rhs) const;

};


#endif //HW2_WISDOM_H
