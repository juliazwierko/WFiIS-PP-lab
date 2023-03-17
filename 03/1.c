/*
  Na przykładzie zmiennej unsigned int i = 0x11223344;
  proszę napisać program sprawdzający, jaka konwencja kolejności 
  zapisu bajtów danych (tworzących jedną wartość całkowitą) 
  jest przyjęta na używanym komputerze: little endian czy big endian. 
*/

#include <stdio.h>
#include <stdlib.h>

void show_mem_rep(char *start, unsigned int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

int main() {
    unsigned int i = 0xAABBCCDD;
    show_mem_rep((char *)&i, sizeof(i));
    return 0;
}
