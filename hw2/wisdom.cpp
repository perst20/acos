//
// Created by kimigaev on 19.10.2021.
//

#include <cstdio>
#include "wisdom.h"
#include "cstring_tools.h"

Wisdom::Wisdom(const char *text) {
    text_size_ = strlen(text) + 1;
    text_ = (char *) malloc(text_size_ * sizeof(char));
    strcpy(text_, text);
}

size_t Wisdom::In(FILE *file) {
    if (getline(&text_, &text_size_, file) == -1)
        return -1;
    CStringTools::EndStrip(text_);
    return 0;
}

void Wisdom::Out(FILE *file) {
    fprintf(file, "result of PunctuationDivide function: %f\n", PunctuationDivide());
    fprintf(file, "text: %s\n", text_);
}

double Wisdom::PunctuationDivide() {
    char puct[] = R"(!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~)";
    int cnt = 0, size = 0;
    for (char *c = &text_[0]; *c != '\0'; ++c) {
        char i = *c;
        for (auto j: puct) {
            if (j == i) {
                ++cnt;
                break;
            }
        }
        ++size;
    }
    return (double) cnt / size;
}

Wisdom::~Wisdom() {
    free(text_);
}

bool Wisdom::operator<(const Wisdom &rhs) const {
    return (strcmp(text_, rhs.text_) < 0);
}

bool Wisdom::operator>(const Wisdom &rhs) const {
    return rhs < *this;
}

bool Wisdom::operator<=(const Wisdom &rhs) const {
    return !(rhs < *this);
}

bool Wisdom::operator>=(const Wisdom &rhs) const {
    return !(*this < rhs);
}

Wisdom::Wisdom() :
        text_((char *) calloc(DEFAULT_DATA_SIZE, sizeof(char))),
        text_size_(DEFAULT_DATA_SIZE) {}
