/*
Proszę uzupełnić poniższy kod tak, żeby prawidłowo wypełniał wiersze 
dwuwymiarowej tablicy oraz wypisywał je. Kod można edytować tylko w 
zaznaczonych miejscach.
*/

int main(void)
{
    srand(time(NULL));
    double array[ROWS][COLS];
    for (double *p =            ;            ;            )
    {
        d_array_set_random(           ,            ,
                           ((double(*)[COLS])p - array) * 10,
                           (((double(*)[COLS])p - array) + 1) * 10);
    }

    for (double(*row)[COLS] =            ;            ;            )
    {
        d_array_print(           ,            ,
                      (const char[]){'w', '=', row - array + '0', '\0'});
    }

    return 0;
}
