#include <stdlib.h>
#include <stdio.h>

//Многомерные массивы
int main(int argc, char const *argv[])
{
    

    int numbers[3][2] = { {1, 2}, {4, 5}, {7, 8} };
    /*
    Macierz:
        (0)(1) 
    (0)  1	2
    (1)  4	5
    (2)  7	8
    */
    printf("numbers[1][0] = %d \n", numbers[1][0]); // 4
    for(int i =0; i < 3; i++)
    {
        // проходим по 2 столбцам каждой строки
        for(int j =0; j<2; j++)
        {
            printf("numbers[%d][%d] = %d \n", i, j, numbers[i][j]);
        }
    }

    int nunmers_2[2][3] = { {1, 2, 4}, {5, 7, 8} };
    /*
    Macierz:
        (0)(1)(2) 
    (0)  1	2  4 
    (1)  5	7  8
    */

    return 0;
}
