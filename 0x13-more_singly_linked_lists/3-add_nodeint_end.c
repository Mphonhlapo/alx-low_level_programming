#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a linked list.
 * @head: A pointer to the pointer of the first element in the list.
 * @n: The integer data to insert in the new element.
 *
 * Description: This function creates a new node containing the given
 * integer data and appends it to the end of a linked list. If the list
 * is empty, the new node becomes the first element.
 *
 * Return: A pointer to the new node, or NULL if it fails to allocate memory.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node;
	listint_t *temp = *head;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new_node;

	return (new_node);
}
