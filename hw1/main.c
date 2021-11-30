#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    srand((time(NULL)));
    if (argc != 4) {
        errMessage1();
        return 1;
    }

    printf("Start\n");
    container c;
    ContainerInit(&c);

    if (!strcmp(argv[1], "-f")) {
        FILE *in = fopen(argv[2], "r");
        ContainerIn(&c, in);
        fclose(in);
    } else if (!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("incorrect number of figures = %i. Set 0 < number <= 10000\n", size);
            return 3;
        }
        ContainerInRnd(&c, size);
    } else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    FILE *out = fopen(argv[3], "w");
    fprintf(out, "Filled container:\n");
    ContainerOut(&c, out);
    fprintf(out, "\nSorted container:\n");
    ContainerSort(&c);
    ContainerOut(&c, out);
    fclose(out);
    printf("Stop\n");
    return 0;
}

