#include <stdlib.h>
#include "colors.h"
#include "utils.h"

const char *colors[] = {
    BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE,
    BOLD_BLACK, BOLD_RED, BOLD_GREEN, BOLD_YELLOW, BOLD_BLUE, 
    BOLD_MAGENTA, BOLD_CYAN, BOLD_WHITE
};

const unsigned int NUM_COLORS = sizeof(colors) / sizeof(colors[0]);

const char *native_get_radom_color(){
    unsigned int rand_number = native_rand(NUM_COLORS);
    return colors[rand_number];
}

const char *get_radom_color(){
    srand(get_clock());
    int rand_number = rand() % NUM_COLORS;
    return colors[rand_number];
}
