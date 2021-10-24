//
// Created by kimigaev on 20.10.2021.
//

#ifndef HW2_PUZZLE_H
#define HW2_PUZZLE_H


#include <cstdio>
#include "wisdom.h"

class Puzzle : public Wisdom {
private:
    char *answer_;
    size_t answer_size_;

public:
    Puzzle();

    ~Puzzle();

    Puzzle(const char *text, const char *answer);

    size_t In(FILE *file) override;

    void Out(FILE *file) override;
};


#endif //HW2_PUZZLE_H
