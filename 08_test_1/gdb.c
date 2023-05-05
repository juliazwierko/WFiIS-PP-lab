// Do polecenia kompilacji dopisujemy opcję -g lub -ggdb, np.:
// gcc program.c -o program.out -g

// Włączamy debuggera GDB poleceniem:
// gdb program.out

Pokecenia debuggera
// list - wypisuje 10 kolejnych linii kodu analizowanego programu.
// list n - wypisuje 5 linii przed i 5 linii od linii nr n.
// list n:m - wypisuje linie od n do m włącznie, np. list 15,28.
// list nazwa_funkcji, n - wypisuje linie od początku funkcji o podanej nazwie do linii numer n.
// list nazwa_funkcji - wypisuje 5 linii przed i 5 linii po nagłówku funkcji o podanej nazwie.

// set args arg1 arg2 ... - ustawia parametry wywołania programu, np. set args 10 20 ustawi dwa parametry: "10" oraz "20".
// run - uruchamia analizowany program bez parametrów wywołania, chyba że były ustawione wcześniej poleceniem set args.
// run args1 arg2 ... - uruchamia program z parametrami wywołania, np. run 10 20 uruchomi program z dwoma parametrami: "10" oraz "20". 
// quit - wyjście z GDB.
// file a.out - załadowanie symboli z pliku wykonywalnego (na nowo lub z nowego pliku).

// break nazwa_funkcji - ustawia punkt przerwania (tzw. pułapkę) na początek funkcji o podanej nazwie.
// break n - ustawia punkt przerwania na linię numer n.
// info break - wyświetla listę ustawionych punktów przerwania.
// watch wyrażenie - ustawia punkt obserwacji, tzn.zatrzymuje działanie programu, jeśli podane wyrażenie uległo zmianie, np.: watch x - jeśli wartość zmiennej x uległa zmianie, watch x > 5 - jeśli wartość wyrażenia logicznego x > 5 uległa zmianie.
// info watchpoints - wyświetla listę ustawionych punktów obserwacji.
// clear nazwa_funkcji - usuwa punkt przerwania ustawiony wcześniej na funkcji o podanej nazwie.
// delete n - usuwa ustawiony wcześniej punkt przerwania o numerze n.

// step - wykonuje jedną linię kodu (jeśli jest to wywołanie funkcji, to wchodzi do niej i tam przerywa).
// step n - wykonuje n linii kodu w sposób taki, jak samo polecenie step.
// next - wykonuje jedną linię kodu (jeśli jest to wywołanie funkcji, to traktuje je nadal jako jedną linię - czyli wykonuje całą funkcję).
// finish - wykonuje instrukcje aż do zakończenia funkcji.
// continue - wznawia działanie programu (do kolejnego punktu przerwania, napotkanego błędu lub do końca programu).

// backtrace - wyświetla podsumowanie informacji o wywoływanych aktualnie funkcjach.
// info locals - wyświetla informacje o zmiennych lokalnych w aktualnej funkcji.
// set - pozwala ustawić wartość zmiennej, np. set x=0 lub set variable x=0 ustawia x = 0;
// print - pozwala wyświetlić i ustawić wartość zmiennej, np. print x wyświetli wartość zmiennej x, natomiast print x=5 przypisze wartość 5 do zmiennej x oraz wyświetli przypisaną wartość (przydatne przy bardziej skomplikowanych wyrażeniach do obliczenia i przypisania).
// print /c x - wyświetla wartość zmiennej x jako znak (niektóre inne sposoby:  /s - łańcuch, /u - unsigned, /f - floating point, /t - system binarny, /a - adres).
