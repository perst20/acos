//
// Created by kimigaev on 20.10.2021.
//

#ifndef HW2_PUZZLE_H
#define HW2_PUZZLE_H


#include <cstdio>
#include "wisdom.h"

class Puzzle : public Wisdom {
public:
    char *answer_ = (char *) calloc(DATA_SIZE, sizeof(char));
    size_t answer_size_ = DATA_SIZE;

private:
    Puzzle() = default;

    ~Puzzle();

    Puzzle(const char *text, const char *answer);

    void In(FILE *file) override;

    void Out(FILE *file) override;
};


#endif //HW2_PUZZLE_H
