#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "student.h"
#include "list.h"

typedef enum { 
    LOWER,
    UPPER 
} LETTER_CASE;

int i_rand(int min, int max)
{
    assert(min <= max);
    return rand() % (max - min + 1) + min;
}

int cmp_student_by_last_name(const void *a, const void *b)
{
    const Student *student_a = (const Student *)a;
    const Student *student_b = (const Student *)b;

    return strcmp(student_a->last_name, student_b->last_name);
}

char rand_letter(LETTER_CASE letter_case)
{
    int start_index;

    if (letter_case == LOWER)
    {
        start_index = 'a';
    }
    else
    {
        start_index = 'A';
    }

    int random_index = i_rand(0, 25);
    char random_letter = start_index + random_index;

    return random_letter;
}

void rand_name(char *array, size_t max_len)
{
    assert(array != NULL && max_len > 0);

    size_t name_len = i_rand(1, max_len - 1);
    array[0] = rand_letter(UPPER);

    for (size_t i = 1; i < name_len; i++)
    {
        array[i] = rand_letter(LOWER);
    }

    if (name_len < max_len)
    {
        array[name_len] = '\0'; 
    }
    else
    {
        array[max_len - 1] = '\0'; 
    }
}

void print_student(const void *student)
{
    assert(student != NULL);
    const Student *student_a = (const Student *)student;
    printf("Dane studenta: %s %s, wiek: %u, adres: %s\n",
                                    student_a->first_name, 
                                    student_a->last_name, 
                                    student_a->age, 
                                    student_a->email);
}

void rand_email(char *array, size_t max_len)
{
    assert(array != NULL && max_len > 0);
    char email[max_len];

    size_t max_name_len = max_len - strlen("@student.agh.edu.pl") - 1; 
    size_t name_len = i_rand(1, max_name_len);

    //generowanie losowej czesci
    for (size_t i = 0; i < name_len; i++)
    {
        array[i] = rand_letter(UPPER); //wielkie litery
    }
    array[name_len] = '@';
   
    const char *mail = "@student.agh.edu.pl";
    strcpy(array + name_len + 1, mail);
}

Student *rand_student(void)
{
    Student *student = (Student *)malloc(sizeof(Student));
    if (student == NULL) {
        fprintf(stderr, "Błąd alokacji pamięci dla studenta.\n");
        return NULL;
    }

    rand_name(student->first_name, F_NAME_MAX);
    rand_name(student->last_name, L_NAME_MAX);
    student->age = (unsigned short)i_rand(18, 30);
    rand_email(student->email, EMAIL_MAX);

    return student;
}

int main(int argc, char *argv[]){
    if(argc != 3)
    {
        printf("Podaj liczbe calkowita n i nazwe pliku.\n");
        return 1;
    }
    //a
    int n = atoi(argv[1]); 
    const char * filename = argv[2]; 
    printf("Liczba n: %d\n", n);
    printf("Nazwa pliku: %s\n", filename);

    //b
    srand(time(NULL));

    SortedList student_list;
    initialize_list(&student_list);

    for (int i = 0; i < n; i++) {
        Student* student = rand_student(); 
        add(&student_list, student, cmp_student_by_last_name); 
    }

    printf("Wartosci utworzonej listy:\n");
    print_list(&student_list, print_student);

    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Błąd otwarcia pliku do zapisu.\n");
        remove_all(&student_list);  // Zwolnienie pamięci przed zakończeniem programu
        return 1;
    }

    Node *current = student_list.head;
    while (current != NULL) {
        // Zapisanie struktury Student do pliku
        fwrite(current->data, sizeof(Student), 1, file);
        current = current->next;
    }

    fclose(file);

    //safefree
    remove_all(&student_list);
    return 0;
}
//kompilowanie gcc leclerc.c lista.c
// ./a.out
// Liczba n: 12
// Nazwa pliku: yo
// Wartosci utworzonej listy:
// LISTA:
// Dane studenta: Ecpkunchwrshkrwsyaim Aefafbdcqfgdfmeqntskxdftszcipiftmwkvzmgsuucslkoo, wiek: 24, adres: RNNMESOWHYSJSDXUNMPYIDLPMXXROCDFJU@@student.agh.edu.pl
// Dane studenta: Nvxgsxxkcoohbetlljnedgazkkhgpujbyyru Bknrmlaztccdgqbziws, wiek: 18, adres: OBJIEWYRSXEVRNXOQLCBQSCWGTCHFEPHKFKIDDAIWB@@student.agh.edu.pl
// Dane studenta: B Cdahfiarcungchbnmkyjemwu, wiek: 22, adres: OUBRTMAMXWWPKKUNZXJOZ@@student.agh.edu.pl
// Dane studenta: Garabaocqfqriei Fzeuzcpmpiclcyffosrfhjbcmtdqodlxrlqmo, wiek: 20, adres: WLASMCMSX@@student.agh.edu.pl
// Dane studenta: Rtlobhwizjxjynilzwniqimuiovdtmislygfmpukyhyo Iuwgxdyyplojhiiazmzogksmwfezbrvpaoviysrbxoetscenjaiysxyifd, wiek: 30, adres: QFSCGRWTQOPOXVQOAXKPMQGR@@student.agh.edu.pl
// Dane studenta: Oelkrfnrzatindztnxkmwunohgpgtubmeqzykndnihxzd Joivbnrfdidnnjvycuimzkjbobojnfoihtcwjqkguxbbmwgampq, wiek: 18, adres: RBHEZVIDDSLVRF@@student.agh.edu.pl
// Dane studenta: Eymromgwwae Lszugwodtkixquodyoxx, wiek: 30, adres: MUJTRAYYNAC@@student.agh.edu.pl
// Dane studenta: Qcwnopcvxvckbojicblnxmqvqbc Olxgohppzvmfwqkrmlnpltldurzabkltiqstnjpdcodaqoohnyatgw, wiek: 24, adres: GLTVNF@@student.agh.edu.pl
// Dane studenta: Qedbvoyeoetfwocivigqaf Tfgflvigngpirkcxkoujdeslvfmtxmgoniqz, wiek: 18, adres: JGDSZLTJDEGZCXYNPXWDAKFOVCTFFPKQTWVM@@student.agh.edu.pl
// Dane studenta: Fuqrxmlcehbbwwfftjkcgnbelitjwsjcvkmcsoowiczn Vlgoejaxavdqwgvhhmwdtcamtdkncdhnscyzjiupxwpqkbczxorffmdiabpr, wiek: 20, adres: OHHGLFMLTQNCHVPSYNPHVGQBALOGEXITRTXGUB@@student.agh.edu.pl
// Dane studenta: Bvydxotvofrlqeyhmahzltepvhgfkpdbfo Yqakewlumyubntktrivlhodzufeaioxy, wiek: 22, adres: ZJFTJWWTXCTZF@@student.agh.edu.pl
// Dane studenta: X Zgtimyixdnbjeuvothpfrlgxnjxgdoshdtpzsqsdxueeawmzbk, wiek: 20, adres: KFEDFAAOKMTDESPI@@student.agh.edu.pl
// julia_zverko@MacBook-Pro-Julia-5 Desktop % 
