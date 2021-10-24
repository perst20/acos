//
// Created by kimigaev on 20.10.2021.
//

#include "puzzle.h"
#include "cstring_tools.h"

Puzzle::Puzzle(const char *text, const char *answer) : Wisdom(text) {
    answer_size_ = strlen(answer) + 1;
    answer_ = (char *) malloc(answer_size_ * sizeof(char));
    strcpy(answer_, answer);
}

size_t Puzzle::In(FILE *file) {
    if (Wisdom::In(file) == -1)
        return -1;
    if (getline(&answer_, &answer_size_, file) == -1) {
        return -1;
    }
    CStringTools::EndStrip(answer_);
    return 0;
}

void Puzzle::Out(FILE *file) {
    fprintf(file, "Puzzle\n");
    Wisdom::Out(file);
    fprintf(file, "answer: %s\n", answer_);
}

Puzzle::~Puzzle() {
    free(answer_);
}

Puzzle::Puzzle() :
        Wisdom(),
        answer_((char *) calloc(DEFAULT_DATA_SIZE, sizeof(char))),
        answer_size_(DEFAULT_DATA_SIZE) {}
