#include <stdio.h>
#include "utils.h"

double get_seed(){
   int local_variable;
   unsigned long seed = (unsigned long)&local_variable;

   return (double)seed;
}

// Retorna um numero pseudo aleatorio com um intervalo maximo de acordo com max
unsigned int native_rand(unsigned int max){
    static unsigned int seed = 0; 
    if (seed == 0) {
      seed = get_seed();
    }
    // Criacao de um numero pseudoaleatorio
    seed = (seed * 1103515245 + 12345) & 0x7fffffff;

    // Retorna o numero usando mod para deixa-lo no intervalo pretendido
    return seed % max;
}

