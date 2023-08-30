#include "lists.h"

/**
 * free_listint2 - Frees a linked list and sets the head to NULL.
 * @head: Pointer to the pointer of the listint_t list to be freed.
 *
 * Description: This function frees all the nodes of a linked list and
 * sets the head pointer to NULL.
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
		return;

	for (; *head != NULL;)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}

	*head = NULL;
}
