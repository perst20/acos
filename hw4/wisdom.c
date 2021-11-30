
#include <string.h>
#include "wisdom.h"

wisdom *WisdomInit() {
    wisdom *wsd = (wisdom *) malloc(sizeof(wisdom));
    wsd->text_size = 0;
    wsd->additional_data_size = 0;
    return wsd;
}

void WisdomDelete(wisdom *wsd) {
    if (wsd->text_size != 0)
        free(wsd->text);
    if (wsd->additional_data_size != 0)
        free(wsd->additional_data);
    free(wsd);
}

size_t WisdomIn(wisdom *wsd, FILE *file) {
    size_t s_size = 0;
    char *s = NULL;
    if (getline(&s, &s_size, file) == -1) {
        if (s_size != 0)
            free(s);
        return -1;
    }
    EndStrip(s);
    if (!strcmp(s, "Aphorism")) {
        wsd->k = APHORISM;
    } else if (!strcmp(s, "Puzzle")) {
        wsd->k = PUZZLE;
    } else if (!strcmp(s, "Proverb")) {
        wsd->k = PROVERB;
    } else {
        if (s_size != 0)
            free(s);
        return -1;
    }
    free(s);
    if (getline(&wsd->text, &wsd->text_size, file) == -1)
        return -1;
    EndStrip(wsd->text);
    if (getline(&wsd->additional_data, &wsd->additional_data_size, file) == -1)
        return -1;
    EndStrip(wsd->additional_data);
    return 0;
}

void WisdomInRnd(wisdom *wsd) {
    if (wsd->text_size != 0)
        free(wsd->text);
    if (wsd->additional_data_size != 0)
        free(wsd->additional_data);
    wsd->k = rand() % 3;
    size_t size1 = rand() % MAX_RAND_DATA_SIZE + 2, size2 = rand() % MAX_RAND_DATA_SIZE + 2;
    char *text = (char *) calloc(size1, sizeof(char));
    char *data = (char *) calloc(size2, sizeof(char));
    RandomString(text, size1 - 1);
    RandomString(data, size2 - 1);
    wsd->text = text;
    wsd->additional_data = data;
    wsd->text_size = size1;
    wsd->additional_data_size = size2;
}

void WisdomOut(const wisdom *wsd, FILE *file) {
    char const *type, *data_type;
    switch (wsd->k) {
        case APHORISM:
            type = "Aphorism";
            data_type = "author";
            break;
        case PROVERB:
            type = "Proverb";
            data_type = "country";
            break;
        case PUZZLE:
            type = "Puzzle";
            data_type = "answer";
            break;
    }
    fprintf(file, "%s\n", type);
    fprintf(file, "result of PunctuationDivide function: %f\n", WisdomPunctuationDivide(wsd));
    fprintf(file, "text: %s\n", wsd->text);
    fprintf(file, "%s: %s\n", data_type, wsd->additional_data);

}

double WisdomPunctuationDivide(const wisdom *wsd) {
    int cnt = 0, size = 0;
    for (char const *i = wsd->text; *i != '\0'; ++i) {
        for (char const *j = punct; *j != '\0'; ++j) {
            if (*j == *i) {
                ++cnt;
                break;
            }
        }
        ++size;
    }
    return (double) cnt / size;
}
