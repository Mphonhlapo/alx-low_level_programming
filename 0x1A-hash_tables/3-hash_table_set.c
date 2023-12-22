#include "hash_tables.h"

/**
 * hash_table_set - Add or update an element in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to add - cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: Upon failure - 0.
 *         Otherwise - 1.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	/* Declare variables */
	hash_node_t *new;
	char *value_copy;
	unsigned long int index, i;

	/* Check for NULL pointers and empty strings */
	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	/* Duplicate the value string */
	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	/* Calculate the index using the key */
	index = key_index((const unsigned char *)key, ht->size);
	i = index;

	/* Search for an existing key in the hash table */
	while (ht->array[i] != NULL)
	{
		/* If the key is found, update the value and return */
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = value_copy;
			return (1);
		}

		/* Increment the index, wrap around if necessary */
		i++;
		if (i == ht->size)
			i = 0; /* Wrap around to the beginning of the array */
	}

	/* Allocate memory for a new hash node */
	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
	{
		free(value_copy);
		return (0);
	}

	/* Duplicate the key string for the new node */
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (0);
	}

	/* Set the value and next pointer for the new node */
	new->value = value_copy;
	new->next = ht->array[index];
	ht->array[index] = new;

	return (1);
}
