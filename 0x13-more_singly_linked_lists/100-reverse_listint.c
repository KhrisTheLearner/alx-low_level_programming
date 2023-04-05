#include "lists.h"

/**
 * reverse_listint - Reverses a linked list in place.
 *
 * @head: A pointer to a pointer to the first node in the list.
 *
 * Return: A pointer to the first node in the new list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous = NULL;
	listint_t *current = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		current = *head;
		next = current->next;
		current->next = previous;
		previous = current;
		*head = next;
	}

	*head = previous;

	return (*head);
}
