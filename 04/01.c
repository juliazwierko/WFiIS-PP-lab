#include <stdlib.h>
#include "../my_functions/functions_0d.c"
#include "../my_functions/functions_1d.c"
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

bool is_symmetric(const short *first, const short *last);

int main() {
    short tab[2][2] = { {1,5}, {5,7} };
    short tab2[3][3] = { {2,3,5}, {3,6,1}, {5,1,8} };
    short tab3[2][4] = {{1,2,3,4}, {1,2,3,4}};

    printf("%d", is_symmetric(&tab[0][0], &tab[1][1]));
    printf("%d", is_symmetric(&tab2[0][0], &tab2[2][2]));
    printf("%d", is_symmetric(&tab3[0][0], &tab3[1][3]));
    return 0;
}

bool is_symmetric(const short *first, const short *last){
    unsigned int n = (last - first); // ilosc elementow;
    int size = round(sqrt(n)); // ilosc rows;

    // sprawdzanie czy macierz kwadratowa:
    int iloczyn = pow(size, 2);
    if (iloczyn == n)
    {
        printf("Macierz jest kwadratowa\n");
        // symetrycznosc macierzy:
        int licz = 0;
        for(int w = 0; w < size; w++){

            for(int k = w+1; k < size; k++){


                short tmp = *(first + w*size + k);
                short tmp2 = *(first + k*size + w);
                if (tmp != tmp2){
                    return 0;
                }
            }
        }

        return 1;

    }
    else 
    {
        printf("Macierz nie jest kwadratowa\n");
        return 0;
    }


   

}
