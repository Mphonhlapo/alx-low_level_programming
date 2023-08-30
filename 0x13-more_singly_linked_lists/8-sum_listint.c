#include "lists.h"

/**
 * sum_listint - Calculates the sum of all the data in a listint_t list.
 * @head: Pointer to the first node in the linked list.
 *
 * Return: The resulting sum of the data in the list.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current;

	for (current = head; current != NULL; current = current->next)
	{
		sum += current->n;
	}

	return (sum);
}
