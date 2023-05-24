// Struct i jego inicjalizacja + korzystanie z wskaźników do structa + korzystanie z operatorów "." i "->". 
// Uzupełnienie deklaracji wskaźnika, wywołania printf'a i napisane co się wypisze.

#include <stdio.h>
#include <stdlib.h>

int main(){
    typedef struct{
        int x;
        int y;
    } Pepa_Pig;
    Pepa_Pig a = {.x = 12, .y = 10};
    Pepa_Pig *pa = &a;
    Pepa_Pig **ppa = &pa;

    printf("%d %d\n", (*ppa)->x, (*ppa)->y);
    printf("%d %d\n", (**ppa).x, (**ppa).y); 
    printf("\n");
    printf("%d %d\n", (pa)->x, (pa)->y);
    printf("%d %d\n", (*pa).x, (*pa).y); 
    return 0;
}
//OutPut
// 12 10
// 12 10

// 12 10
// 12 10
