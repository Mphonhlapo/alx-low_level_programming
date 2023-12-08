#include "lists.h"

/**
 * dlistint_len - Returns the number of elements in a double linked list.
 *
 * @h: Head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	/* Variable to count the number of nodes */
	int count;

	/* Initialize count to zero */
	count = 0;

	/* Check for an empty list */
	if (h == NULL)
		return (count);

	/* Move to the beginning of the list */
	for (; h->prev != NULL; h = h->prev)
		;  /* Empty loop body */

	/* Count nodes in the list */
	for (; h != NULL; h = h->next)
	{
		count++;
	}

	/* Return the total number of nodes */
	return (count);
}
