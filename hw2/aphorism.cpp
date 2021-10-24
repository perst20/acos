//
// Created by kimigaev on 20.10.2021.
//

#include "aphorism.h"
#include "cstring_tools.h"

Aphorism::Aphorism(const char *text, const char *author) : Wisdom(text) {
    author_size_ = strlen(author) + 1;
    author_ = (char *) malloc(author_size_ * sizeof(char));
    strcpy(author_, author);
}

size_t Aphorism::In(FILE *file) {
    if (Wisdom::In(file) == -1)
        return -1;
    if (getline(&author_, &author_size_, file) == -1) {
        return -1;
    }
    CStringTools::EndStrip(author_);
    return 0;
}

void Aphorism::Out(FILE *file) {
    fprintf(file, "Aphorism\n");
    Wisdom::Out(file);
    fprintf(file, "author: %s\n", author_);
}

Aphorism::~Aphorism() {
    free(author_);
}

Aphorism::Aphorism() :
        Wisdom(),
        author_((char *) calloc(DEFAULT_DATA_SIZE, sizeof(char))),
        author_size_(DEFAULT_DATA_SIZE) {}
