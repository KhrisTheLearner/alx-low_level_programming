#include "lists.h"

/**
 * free_listint2 - Frees a listint_t linked list.
 * @head: A pointer to a pointer to the first node of the list.
 *
 * Description: This function frees a listint_t list and sets the
 * head to NULL.
 *
 * Return: Nothing.
 */
void free_listint2(listint_t **head)
{
	listint_t *current;

	if (head == NULL || *head == NULL)
		return;

	while (*head != NULL)
	{
		current = *head;
		*head = (*head)->next;
		free(current);
	}

	*head = NULL;
}
