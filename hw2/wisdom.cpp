//
// Created by kimigaev on 19.10.2021.
//

#include <cstdio>
#include "wisdom.h"

Wisdom::Wisdom(const char *text) : Wisdom() {
    text_ = (char *) realloc(text_, (strlen(text) + 1) * sizeof(char));
    text_size_ = strlen(text) + 1;
    strcpy(text_, text);
}

void Wisdom::In(FILE *file) {
    getline(&text_, &text_size_, file);
}

void Wisdom::Out(FILE *file) {
    fprintf(file, "%s\n", text_);
}

double Wisdom::PunctuationDivide() {
    char puct[] = R"(.,<>/\?'";:[]{}`~!@#$%^&*()_+-=)";
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
