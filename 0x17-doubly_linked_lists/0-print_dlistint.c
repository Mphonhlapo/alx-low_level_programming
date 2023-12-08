#include "lists.h"

/**
 * print_dlistint - Prints all the elements of a doubly linked list.
 *
 * @h: Pointer to the head of the dlistint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_dlistint(const dlistint_t *h)
{
	/* Variable to count the number of nodes */
	int count;

	/* Initialize count to zero */
	count = 0;

	/* Check for an empty list */
	if (h == NULL)
		return (count);

	/* Move to the beginning of the list */
	while (h->prev != NULL)
		h = h->prev;

	/* Print and count nodes in the list */
	while (h != NULL)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}

	/* Return the total number of nodes */
	return (count);
}
