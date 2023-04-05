#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * looped_listint_len - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list
 */
size_t looped_listint_len(const listint_t *head)
{
	listint_t *slow, *fast;
	size_t count = 0;

	if (!head)
		return (0);

	slow = (listint_t *)head;
	fast = head->next;

	while (fast && fast->next)
	{
		if (slow == fast)
			break;

		slow = slow->next;
		fast = fast->next->next;
	}

	if (slow != fast)
		return (0);

	count = 1;
	slow = slow->next;

	while (slow != fast)
	{
		count++;
		slow = slow->next;
	}

	return (count);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	listint_t *node;
	int *visited = NULL, size = 0, i;

	if (!head)
		return (0);

	node = (listint_t *)head;
	while (node)
	{
		for (i = 0; i < size; i++)
		{
			if (visited[i] == (int)node)
			{
				printf("-> [%p] %d\n", (void *)node, node->n);
				return (count);
			}
		}

		printf("[%p] %d\n", (void *)node, node->n);
		count++;

		visited = realloc(visited, sizeof(int) * (size + 1));
		if (!visited)
			exit(98);

		visited[size] = (int)node;
		size++;

		node = node->next;
	}

	return (count);
}
