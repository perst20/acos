//
// Created by kimigaev on 20.10.2021.
//

#include "aphorism.h"

Aphorism::Aphorism(const char *text, const char *author) : Wisdom(text) {
    author_ = (char *) realloc(author_, (strlen(text) + 1) * sizeof(char));
    author_size_ = (strlen(text) + 1);
    strcpy(author_, text);
}

void Aphorism::In(FILE *file) {
    Wisdom::In(file);
    getline(&author_, &author_size_, file);
}

void Aphorism::Out(FILE *file) {
    Wisdom::Out(file);
    fprintf(file, "%s\n", author_);
}

Aphorism::~Aphorism() {
    free(author_);
}
