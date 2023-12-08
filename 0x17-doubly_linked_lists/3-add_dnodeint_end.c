#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list.
 *
 * @head: Head of the list.
 * @n: Value of the element.
 *
 * Return: The address of the new element.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	/* Allocate memory for the new node */
	dlistint_t *h, *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	h = *head;

	/* If the list is not empty, move to the end of the list */
	if (h != NULL)
	{
		while (h->next != NULL)
			h = h->next;
		h->next = new;
	}
	else
	{
		/* If the list is empty, set the new node as the head */
		*head = new;
	}

	/* Adjust pointers for the new node */
	new->prev = h;

	/* Return the address of the new element */
	return (new);
}
