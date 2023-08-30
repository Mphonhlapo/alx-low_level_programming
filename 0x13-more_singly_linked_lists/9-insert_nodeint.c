#include "lists.h"

/**
 * insert_nodeint_at_index - puts a new node in a linked list at a position.
 * @head: Pointer to the pointer of the first node in the list.
 * @idx: Index where the new node is added.
 * @n: Data to insert in the new node.
 *
 * Return: Pointer to the new node, or NULL if it fails.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i = 0;
	listint_t *new;
	listint_t *current = *head;

	new = malloc(sizeof(listint_t));
	if (!new || !head)
		return (NULL);

	new->n = n;
	new->next = NULL;

	switch (idx)
	{
		case 0:
			new->next = *head;
			*head = new;
			return (new);

		default:
			while (current)
			{
				if (i == idx - 1)
				{
					new->next = current->next;
					current->next = new;
					return (new);
				}
				current = current->next;
				i++;
			}
	}

	free(new);
	return (NULL);
}
