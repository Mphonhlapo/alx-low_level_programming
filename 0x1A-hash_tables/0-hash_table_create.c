#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table.
 * @size: The size of the array.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	/* Allocate memory for the hash table structure */
	hash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	/* Set the size of the array */
	ht->size = size;

	/* Allocate memory for the array of hash nodes */
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht); /* Free the previously allocated memory */
		return (NULL);
	}

	/* Initialize each element in the array to NULL */
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	/* Return a pointer to the newly created hash table */
	return (ht);
}
