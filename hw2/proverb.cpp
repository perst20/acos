//
// Created by kimigaev on 22.10.2021.
//

#include "proverb.h"
#include "cstring_tools.h"

Proverb::Proverb(const char *text, const char *country) : Wisdom(text){
    country_size_ = strlen(country) + 1;
    country_ = (char *) malloc(country_size_ * sizeof(char));
    strcpy(country_, country);
}

size_t Proverb::In(FILE *file) {
    if (Wisdom::In(file) == -1)
        return -1;
    if (getline(&country_, &country_size_, file) == -1) {
        return -1;
    }
    CStringTools::EndStrip(country_);
    return 0;
}

void Proverb::Out(FILE *file) {
    fprintf(file, "Proverb\n");
    Wisdom::Out(file);
    fprintf(file, "country: %s\n", country_);
}

Proverb::~Proverb() {
    free(country_);
}

Proverb::Proverb() :
        Wisdom(),
        country_((char *) calloc(DEFAULT_DATA_SIZE, sizeof(char))),
        country_size_(DEFAULT_DATA_SIZE) {}
