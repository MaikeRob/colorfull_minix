#ifndef COLORS_H
#define COLORS_H

#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

#define BOLD_BLACK       "\033[1;30m"
#define BOLD_RED         "\033[1;31m"
#define BOLD_GREEN       "\033[1;32m"
#define BOLD_YELLOW      "\033[1;33m"
#define BOLD_BLUE        "\033[1;34m"
#define BOLD_MAGENTA     "\033[1;35m"
#define BOLD_CYAN        "\033[1;36m"
#define BOLD_WHITE       "\033[1;37m"

#define RESET       "\033[0m"  // Reset color

extern const unsigned int NUM_COLORS;

extern const char *colors[];

extern const char *get_radom_color();

extern const char *native_get_radom_color();

#endif
