#include <stdio.h>
#include "utils.h"

double get_seed(){
   int local_variable;
   unsigned long seed = (unsigned long)&local_variable;

   return (double)seed;
}

// Retorna um numero pseudo aleatorio com um intervalo maximo de acordo com max
unsigned int native_rand(unsigned int max){
    double seed = get_seed();

    // Criacao de um numero pseudoaleatorio
    double expression = (3.9 * seed * (1 - seed));

    // Retorna o numero usando mod para deixa-lo no intervalo pretendido
    return (unsigned int)expression % max;
}

