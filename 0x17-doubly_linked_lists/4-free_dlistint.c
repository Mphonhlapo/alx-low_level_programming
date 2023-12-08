#include "lists.h"

/**
 * free_dlistint - Frees a dlistint_t list.
 * @head: Pointer to the head of the list.
 *
 * Return: Nothing.
 */
void free_dlistint(dlistint_t *head)
{
	if (head == NULL)
		return; /* If the list is already empty, nothing to free */

	/* Traverse the list and free each node */
	while (head->next != NULL)
	{
		head = head->next;   /* Move to the next node */
		free(head->prev);    /* Free the previous node */
	}

	free(head); /* Free last node (or the only node if the list has 1 element) */
}
