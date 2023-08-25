#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a linked list and its string elements
 * @head: pointer to the head of the list
 */
void free_list(list_t *head)
{
    list_t *current = head;
    list_t *next;

    while (current != NULL)
    {
        next = current->next;
        if (current->str != NULL)
        {
            free(current->str);
        }
        free(current);
        current = next;
    }
}
