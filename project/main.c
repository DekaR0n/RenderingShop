#include <stdio.h>
#include "stdlib.h"
#include "../library/shop.h"
#include "windows.h"
#include <time.h>


int main() {
    int is_start = 1;
    const_init();
    while (is_start) {
        start();
    }
    return 0;
}


