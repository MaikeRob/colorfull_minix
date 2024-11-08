#include <minix/clock.h>
#include <stdio.h>
#include "utils.h"

double get_clock(){

    clock_t current_time;

    // Coloca em current_time o tempo em que o sistema está acordado em ticks de clock 
    get_uptime(&current_time);

    if (current_time == (clock_t)-1) {
        printf("Erro de driver: Impossivel de obter o clock do sistema");
        return -1;
    }

   return (double)current_time;
}

// Retorna um numero pseudo aleatorio com um intervalo maximo de acordo com max
unsigned int native_rand(unsigned int max){
    double clock = get_clock();

    // Criacao de um numero pseudoaleatorio
    double expression = (3.9 * clock * (1 - clock));

    // Retorna o numero usando mod para deixa-lo no intervalo pretendido
    return (unsigned int)expression % max;
}

clock_t uptime_ticks;
