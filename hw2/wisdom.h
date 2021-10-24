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
    char *text_;
    size_t text_size_;

public:
    Wisdom();

    Wisdom(const char *text);

    virtual ~Wisdom();

    virtual size_t In(FILE *file);

    virtual void Out(FILE *file);

    virtual double PunctuationDivide();

    bool operator<(const Wisdom &rhs) const;

    bool operator>(const Wisdom &rhs) const;

    bool operator<=(const Wisdom &rhs) const;

    bool operator>=(const Wisdom &rhs) const;

};


#endif //HW2_WISDOM_H
