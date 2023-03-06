#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("^_^\n");
    int *arr = calloc(12, sizeof(int));
    free(arr);
    return 0;
}

/*
  TESTOWANIE:
julia_zverko@MacBook-Pro-Julia tests % $(brew --prefix llvm)/bin/clang 2.c -fsanitize=address                 
julia_zverko@MacBook-Pro-Julia tests % ASAN_OPTIONS=detect_leaks=1 LSAN_OPTIONS=suppressions=lsan.supp ./a.out
^_^
-----------------------------------------------------
Suppressions used:
  count      bytes template
    134       4288 realizeClassWithoutSwift
-----------------------------------------------------
*/
