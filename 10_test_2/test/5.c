// Struct i jego inicjalizacja + korzystanie z wskaźników do structa + korzystanie z operatorów "." i "->". 
// Uzupełnienie deklaracji wskaźnika, wywołania printf'a i napisane co się wypisze.

#include <stdio.h>

int main(void) {
  typedef struct {
    int x;
    int y;
  } Point;

  Point p = {.y = 2};
  Point* ptr1 = &p; // uzupelnic
  Point** ptr2 = &ptr1; // uzupelnic

  printf("%d, %d\n", (*ptr2)->x, (**ptr2).y); // uzupelnic + co sie wypisze

  return 0;
}
