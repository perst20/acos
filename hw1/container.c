//
// Created by kimigaev on 29.11.2021.
//

#include "container.h"

void ContainerInit(container *c) {
    c->size = 0;
}

void ContainerClear(container *c) {
    for (size_t i = 0; i < c->size; ++i) {
        WisdomDelete(c->data[i]);
    }
    c->size = 0;
}

void ContainerIn(container *c, FILE *file) {
    size_t nerr = 0;
    for (; nerr == 0 && c->size < max_len; ++c->size) {
        c->data[c->size] = WisdomInit();
        nerr = WisdomIn(c->data[c->size], file);
        if (nerr != 0) {
            WisdomDelete(c->data[c->size]);
            break;
        }
    }
}

void ContainerInRnd(container *c, size_t size) {
    c->size = size;
    for (size_t i = 0; i < size; ++i) {
        c->data[i] = WisdomInit();
        WisdomInRnd(c->data[i]);
    }
}

void ContainerOut(container *c, FILE *file) {
    fprintf(file, "Container size: %zu\n", c->size);
    for (size_t i = 0; i < c->size; ++i) {
        fprintf(file, "%zu:\n", i);
        WisdomOut(c->data[i], file);
    }
}

void ContainerSort(container *c) {
    size_t size = c->size;
    wisdom **end = c->data + size;
    for (wisdom **i = c->data; i != end; ++i) {
        for (wisdom **j = i + 1; j != end; ++j) {
            if (strcmp((*i)->text, (*j)->text) > 0) {
                wisdom *temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
}
