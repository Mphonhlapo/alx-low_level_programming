#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all the data (n) of a doubly linked list.
 *
 * @head: Pointer to the head of the list.
 *
 * Return: Sum of the data.
 */
int sum_dlistint(dlistint_t *head)
{
	/* Initialize sum to 0 */
	int sum;

	sum = 0;

	if (head != NULL)
	{
		/* Move to the beginning of the list if needed */
		while (head->prev != NULL)
			head = head->prev;

		/* Traverse the list and accumulate the sum */
		while (head != NULL)
		{
			sum += head->n;
			head = head->next;
		}
	}

	return (sum);
}
