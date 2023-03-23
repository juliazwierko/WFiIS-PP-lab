#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define W 4
#define K 7

const double * min_pointer(const double * first, const double * last);
const double * min_pointers_of_rows(const double * first, const double * last);

int main() {
    double arr[W][K];

    for(int i = 0; i < W; i++)
    {
        for(int j = 0; j < K; j++)
        {
            arr[W][K] = d_array_set_random(0.0, 10.0);
        }
    }

    for(int i = 0; i < W; i++)
    {
        for(int j = 0; j < K; j++)
        {
            printf("arr[%d][%d] = %lf", i, j, a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
