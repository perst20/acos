#ifndef HW1MY_WISDOM_H
#define HW1MY_WISDOM_H

#include <stdio.h>
#include <stddef.h>
#include "constants.h"
#include "cstring_tools.h"

static char const punct[] = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся высказывания
typedef struct {
    // значения ключей для каждого из высказываний
    enum key {
        APHORISM,
        PROVERB,
        PUZZLE
    } k;
    char *text, *additional_data;
    size_t text_size, additional_data_size;
} wisdom;

// Создать высказывание
wisdom *WisdomInit();

// Удалить высказывание
void WisdomDelete(wisdom *wsd);

// Ввод обобщенного высказывания
size_t WisdomIn(wisdom *wsd, FILE *file);

// Случайный ввод обобщенного высказывания
void WisdomInRnd(wisdom *wsd);

// Вычисления частного от деления количества знаков препинания в значимой строке на ее длину
double WisdomPunctuationDivide(const wisdom *wsd);

// Вывод обобщенного высказывания
void WisdomOut(const wisdom *wsd, FILE *file);


#endif //HW1MY_WISDOM_H
