#include "hash_tables.h"

/**
 * hash_table_get - Retrieve the value associated with
 *                  a key in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
	unsigned long int index;

	/* Check for NULL pointers and empty strings */
	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	/* Calculate the index using the key */
	index = key_index((const unsigned char *)key, ht->size);

	/* Check if the index is out of bounds */
	if (index >= ht->size)
		return (NULL);

	/* Search for the key in the linked list at the calculated index */
	for (node = ht->array[index]; node != NULL && strcmp(node->key, key) != 0; node = node->next)
	{
		/* Continue iterating through the linked list */
	}

	/* Return the value associated with the key, or NULL if not found */
	return ((node == NULL) ? NULL : node->value);
}
