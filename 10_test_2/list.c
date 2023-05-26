#include "list.h"

void initialize_list(SortedList *list)
{
    list->head = NULL;
}

void add(SortedList *list, void *data, CMP cmp)
{
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL)
        return;
    new_node->data = data;
}

void print_list(const SortedList *list, PRINT print)
{
    /* TODO */
}

void *get_data(const SortedList *list, CMP cmp, const void *data)
{
    /* TODO */
    return NULL;
}

void remove_data(SortedList *list, CMP cmp, void *data) 
{
    /* TODO */
}

void remove_all(SortedList *list)
{
    /* TODO */
}
