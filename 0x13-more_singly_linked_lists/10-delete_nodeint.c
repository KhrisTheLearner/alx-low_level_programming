#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at the given index of a list
 * @head: pointer to the head node of the list
 * @index: index of the node to delete
 *
 * Return: 1 if successful, -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *prev = NULL;
	listint_t *nxt = NULL;
	unsigned int i = 0;

	if (!head || !(*head))
		return (-1);

	nxt = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		free(nxt);
		return (1);
	}

	for (i = 0; nxt && i < index; i++)
	{
		prev = nxt;
		nxt = nxt->next;
	}

	if (!nxt)
		return (-1);

	prev->next = nxt->next;
	free(nxt);

	return (1);
}
