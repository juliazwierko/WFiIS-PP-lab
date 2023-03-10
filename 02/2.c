/*
    W katalogu lab_02 proszę utworzyć program testujący funkcję d_rand, 
    obliczając histogram. W tym celu podzielimy przedział losowania 
    [MIN,MAX] = [-15, 84.999999] na MAX_HIST = 10  podprzedziałów, 
    każdy o szerokości dx = 10.0. Zliczymy, ile pseudolosowych wartości 
    należy do którego z nich. Testowanie implementujemy w następujący sposób:
    
    ->Tworzymy wyzerowaną tablicę typu całkowitego o MAX_HIST elementach 
      (element o indeksie i odpowiada i-temu podprzedziałowi).
      
    ->10^7 razy wywołujemy d_rand dla zadanego przedziału [MIN,MAX]
    
    ->Dla każdej wylosowanej wartości sprawdzamy, do którego należy podprzedziału, 
    i zwiększamy odpowiedni element tablicy histogramu.
    
    ->Wypisujemy tablicę histogramu.
*/
#include <stdlib.h>
#include "../my_functions/functions_0d.c"
#include <stdio.h>
#include <time.h>

#define MAX_HIST 10 // podprzedziałów 
#define dx 10.0 //  szerokośc

int main(){
    srand(time(NULL));

    int histogram[MAX_HIST] = {0};

    double MIN = -15;
    double MAX =  84.999999;

    for (int i=0; i<(1e1); i++){
        double x;
        x = d_rand(MIN, MAX);
        printf("x - %g\n", x);
        if(x>=MIN && x<MIN+dx){
            histogram[0]++;
        }
        else if(x < MIN + 2*dx){
            histogram[1]++;
        }
        else if(x < MIN + 3*dx){
            histogram[2]++;
        }
        else if(x < MIN + 4*dx){
            histogram[3]++;
        }
        else if(x < MIN + 5*dx){
            histogram[4]++;
        }
        else if(x < MIN + 6*dx){
            histogram[5]++;
        }
        else if(x < MIN + 7*dx){
            histogram[6]++;
        }
        else if(x < MIN + 8*dx){
            histogram[7]++;
        }
        else if(x < MIN + 9*dx){
            histogram[8]++;
        }
        else
            histogram[9]++;
    }
    
    //  wypisywanie
    for(int i=0; i<MAX_HIST; i++){
        printf("%d ", histogram[i]);
    }

    return 0;
}
