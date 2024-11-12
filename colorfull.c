#include <stdio.h>
#include <stdlib.h>
#include <minix/syslib.h>
#include "colors.h"

int main(int argc, char **argv){

    sef_startup();

    const char *radom_color = native_get_radom_color();
    printf("%s", radom_color);

   return EXIT_SUCCESS;
    return 0;
}
