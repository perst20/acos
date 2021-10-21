//
// Created by kimigaev on 21.10.2021.
//

#include <algorithm>
#include "container.h"

Container::Container(int s) : size_(0), capacity_(s) {
    data_ = new Wisdom *[s];
}

Container::~Container() {
    Clear();
    delete[] data_;
}

void Container::Clear() {
    for (int i = 0; i < size_; i++) {
        delete data_[i];
    }
    size_ = 0;
}

void Container::In(size_t n, FILE *file) {
    for (size_t i = size_; i < std::min(size_ + n, capacity_); ++i) {
        data_[i]->In(file);
    }
}

void Container::Out(FILE *file) {
    for (int i = 0; i < size_; i++) {
        fprintf(file, "%d:\n", i);
        data_[i]->Out(file);
    }
}

void Container::Sort() {
    for (size_t i = 0; i < size_; ++i) {
        Wisdom *now_min = data_[i];
        for (size_t j = i + 1; j < size_; ++j) {
            if (*data_[i] < *now_min) {
                now_min = data_[i];
            }
        }
        std::iter_swap(now_min, data_[i]);
    }
}



