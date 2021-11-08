//
// Created by kimigaev on 21.10.2021.
//

#include <algorithm>
#include <cassert>
#include "container.h"
#include "aphorism.h"
#include "proverb.h"
#include "cstring_tools.h"
#include "puzzle.h"

Container::Container(int s) : size_(0), capacity_(s) {
    data_ = new Wisdom *[capacity_];
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
    size_t s_size = 32;
    char *s = (char *) calloc(s_size, sizeof(char));
    for (size_t i = size_; i < std::min(size_ + n, capacity_); ++i) {
        getline(&s, &s_size, file);
        CStringTools::EndStrip(s);
        if (!strcmp(s, "Aphorism")) {
            data_[i] = new Aphorism();
            data_[i]->In(file);
        } else if (!strcmp(s, "Puzzle")) {
            data_[i] = new Puzzle();
            data_[i]->In(file);
        } else if (!strcmp(s, "Proverb")) {
            data_[i] = new Proverb();
            data_[i]->In(file);
        } else {
            fprintf(stderr, "Input error");
            assert(false);
        }  @John Smith  It pretty clearly stated it was removing a lot of stuff, including the GUI (not sure why it would remove all that to install steam, but seems to be some kind of conflict). This is why the GUI failed and the CLI made him type the silly phrase. It was supposed to make him realize that he doesn't actually want to do that, but clearly it failed.
    }
    free(s);
    size_ = std::min(size_ + n, capacity_);
}

void Container::In(FILE *file) {
    size_t s_size = 32;
    char *s = (char *) calloc(s_size, sizeof(char));
    bool nerr = true;
    size_t n;
    for (size_t i = size_; i < capacity_; ++i) {
        if (getline(&s, &s_size, file) == -1) {
            nerr = false;
            n = size_ + i;
            break;
        }
        CStringTools::EndStrip(s);
        if (!strcmp(s, "Aphorism")) {
            data_[i] = new Aphorism();
            if (data_[i]->In(file) == -1)
                nerr = false;
        } else if (!strcmp(s, "Puzzle")) {
            data_[i] = new Puzzle();
            if (data_[i]->In(file) == -1)
                nerr = false;
        } else if (!strcmp(s, "Proverb")) {
            data_[i] = new Proverb();
            if (data_[i]->In(file) == -1)
                nerr = false;
        } else {
            fprintf(stderr, "Input error");
            assert(false);
        }
        if (!nerr) {
            n = size_ + i;
            delete data_[i];
            break;
        }
    }
    if (nerr) {
        n = capacity_;
    }
    free(s);
    size_ = std::min(n, capacity_);
}

void Container::InRnd(size_t n) {
    size_t new_size = std::min(capacity_, size_ + n);
    for (size_t i = size_; i < new_size; ++i) {
        int rnd = rand() % 3;
        size_t sz1 = rand() % MAX_RAND_DATA_SIZE + 1, sz2 = rand() % MAX_RAND_DATA_SIZE + 1;
        char txt1[sz1 + 1], txt2[sz2 + 1];
        CStringTools::RandomString(&txt1[0], sz1);
        CStringTools::RandomString(&txt2[0], sz2);
        switch (rnd) {
            case 0:
                data_[i] = new Aphorism(&txt1[0], &txt2[0]);
                break;
            case 1:
                data_[i] = new Proverb(&txt1[0], &txt2[0]);
                break;
            case 2:
                data_[i] = new Puzzle(&txt1[0], &txt2[0]);
                break;
        }
    }
    size_ = new_size;
}

void Container::Out(FILE *file) {
    fprintf(file, "Container size: %zu\n", size_);
    for (int i = 0; i < size_; i++) {
        fprintf(file, "%d:\n", i);
        data_[i]->Out(file);
    }
}

void Container::Sort() {
    for (size_t i = 0; i < size_; ++i) {
        Wisdom **now_min = &data_[i];
        for (size_t j = i + 1; j < size_; ++j) {
            if (*data_[j] < **now_min) {
                now_min = &data_[j];
            }
        }
        std::swap(*now_min, data_[i]);
    }
}



