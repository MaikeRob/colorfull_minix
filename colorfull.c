#include <stdio.h>
#include "colors.h"


int main(){
    const char *radom_color = get_radom_color();

    printf("%s Teste", radom_color);

    return 0;
}
