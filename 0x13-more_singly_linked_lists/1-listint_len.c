#include "lists.h"

/**
 * listint_len - Counts the number of elements in a linked list.
 * @h: Pointer to the linked list of type listint_t to traverse.
 *
 * Return: The number of nodes (elements) in the linked list.
 */
size_t listint_len(const listint_t *h)
{
	size_t num = 0;

	for (; h != NULL; h = h->next)
	{
		num++;
	}

	return (num);
}
