#include <stdio.h>
#include <math.h>

int is_identity(const short *first, const short *last);

int main() {
    short tab[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}; 
    short tab2[4][4] = {{1, 0, 1, 0}, {0, 1, 0, 0}, {1, 0, 1, 0}, {0, 0, 0, 1}}; 
    short tab3[3][4] = {{1, 0, 1, 0}, {0, 1, 0, 0}, {1, 0, 1, 0}};

    printf("%d", is_identity(&tab[0][0], &tab[3][3]+1));
    printf("%d", is_identity(&tab2[0][0], &tab2[3][3]+1));
    printf("%d", is_identity(&tab3[0][0], &tab[2][4]+1));

    return 0;
}

int is_identity(const short *first, const short *last){
    int suma_jedynek = 0;
    unsigned a = last - first; // ilosc elementow //unsigned float_a
    int b = sqrt(a); //wymiar  //double; int a = (int)(float_a)


    const short* ptr = first;
    while(ptr != last){
        if(*ptr == 1){
            suma_jedynek += 1;
        }
        ptr++;
    }

    if(suma_jedynek == b){
        
        return 1;

    }
    else 
        return 0; 
}    
