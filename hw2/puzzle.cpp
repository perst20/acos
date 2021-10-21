//
// Created by kimigaev on 20.10.2021.
//

#include "puzzle.h"

Puzzle::Puzzle(const char *text, const char *answer) : Wisdom(text){
    answer_ = (char *) realloc(answer_, (strlen(text) + 1) * sizeof(char));
    answer_size_ = strlen(text) + 1;
    strcpy(answer_, text);
}

void Puzzle::In(FILE *file) {
    Wisdom::In(file);
    getline(&answer_, &answer_size_, file);
}

void Puzzle::Out(FILE *file) {
    Wisdom::Out(file);
    fprintf(file, "%s\n", answer_);
}

Puzzle::~Puzzle() {
    free(answer_);
}
