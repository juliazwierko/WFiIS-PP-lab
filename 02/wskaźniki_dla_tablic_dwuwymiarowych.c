#include <conio.h>
#include <stdio.h>
 
void main() {
    int A[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p = A[0];
 
    printf("%d\n", p[2]);
 
    getch();
}
