#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
 *
 * @head: Pointer to head of the list.
 * @index: Index of the node to search for, starting from 0.
 *
 * Return: The nth node or NULL if the node is not found.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	/* Initialize variables */
	unsigned int size;
	dlistint_t *tmp;

	size = 0;	/* Initialize the size to 0 */
	if (head == NULL)
		return (NULL);	/* If the list is empty, return NULL */

	tmp = head;	/* Initialize a temporary pointer to the head of the list */

	/* Traverse the list */
	while (tmp)
	{
		if (index == size)
			return (tmp);	/* Return the node if the index matches the current size */

		size++;		/* Increment the size */
		tmp = tmp->next;	/* Move to the next node */
	}

	return (NULL);	/* Return NULL if the node is not found */
}
