//
// Created by kimigaev on 22.10.2021.
//

#ifndef HW2_PROVERB_H
#define HW2_PROVERB_H


#include <cstdio>
#include "wisdom.h"

class Proverb : public Wisdom {
private:
    char *country_;
    size_t country_size_;

public:
    Proverb();

    ~Proverb() override;

    Proverb(const char *text, const char *answer);

    size_t In(FILE *file) override;

    void Out(FILE *file) override;

};


#endif //HW2_PROVERB_H
