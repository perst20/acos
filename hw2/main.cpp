#define _GLIBCXX_DEBUG
#include <iostream>
#include "container.h"

void errMessage1() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile\n"
           "  Or:\n"
           "     command -n number outfile\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n"
           "  Waited:\n"
           "     command -f infile outfile\n"
           "  Or:\n"
           "     command -n number outfile\n");
}


int main(int argc, char *argv[]) {
    srand(static_cast<unsigned int>(time(nullptr)));
    if (argc != 4) {
        errMessage1();
        return 1;
    }

    printf("Start\n");
    Container c{10000};

    if (!strcmp(argv[1], "-f")) {
        FILE *in = fopen(argv[2], "r");
        c.In(in);
        fclose(in);
    } else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("incorrect number of figures = %i. Set 0 < number <= 10000\n", size);
            return 3;
        }
        c.InRnd(size);
    } else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    FILE *out = fopen(argv[3], "w");
    fprintf(out, "Filled container:\n");
    c.Out(out);
    fprintf(out, "\nSorted container:\n");
    c.Sort();
    c.Out(out);
    fclose(out);
    printf("Stop\n");
    return 0;
}
