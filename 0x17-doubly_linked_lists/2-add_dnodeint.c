#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the beginning of a dlistint_t list.
 *
 * @head: Head of the list.
 * @n: Value of the element.
 *
 * Return: The address of the new element.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	/* Allocate memory for the new node */
	dlistint_t *new;
	dlistint_t *h;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	/* Set the value of the new node */
	new->n = n;
	new->prev = NULL;
	h = *head;

	/* If the list is not empty, move to the beginning of the list */
	if (h != NULL)
	{
		while (h->prev != NULL)
			h = h->prev;
	}

	/* Adjust pointers for the new node */
	new->next = h;

	if (h != NULL)
		h->prev = new;

	/* Update the head of the list to the new node */
	*head = new;

	/* Return the address of the new element */
	return (new);
}
