//
// Created by kimigaev on 23.10.2021.
//

#ifndef HW2_CSTRING_TOOLS_H
#define HW2_CSTRING_TOOLS_H


#include <cstddef>
#include <random>
#include <ctime>

namespace CStringTools {
    void EndStrip(char *str);

    void RandomString(char *str, size_t n);
}


#endif //HW2_CSTRING_TOOLS_H
