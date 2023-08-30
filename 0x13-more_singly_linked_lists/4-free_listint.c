#include "lists.h"

/**
 * free_listint - Frees a linked list.
 * @head: Pointer to the listint_t list to be freed.
 *
 * Description: This function frees all the nodes of a linked list.
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	for (; head != NULL;)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
