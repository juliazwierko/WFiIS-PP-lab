#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

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

int main(void){
    srand(time(NULL));

    printf("->Duza losowa litera: %c\n", rand_letter(UPPER));
    printf("->Mala losowa litera: %c\n\n", rand_letter(LOWER));

    char name[20];
    rand_name(name, sizeof(name));
    printf("->Losowe imię/nazwisko: %s\n\n", name);

    char email[50];
    rand_email(email, sizeof(email));
    printf("->Random email: %s\n", email);

    Student *student = rand_student();
    if (student != NULL) {
        printf("\nLosowy student:\n");
        print_student(student);
        free(student);
    }
    return 0;
}

//OutPut:
// ->Duza losowa litera: G
// ->Mala losowa litera: w
// ->Losowe imię/nazwisko: G
// ->Random email: DBMPLANLLQWDQHSVJEOGJPB@@student.agh.edu.pl
// Losowy student:
// Dane studenta: Clri Uscrfgkwvcbigrjiyikyayizikwgaythjceorkwurglbco, wiek: 24, adres: F@@student.agh.edu.pl
