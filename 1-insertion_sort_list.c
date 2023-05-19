#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of int in ascending order
 * @list: doubly list of interger
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *aux, *node_prev;

	if (list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (current != NULL)
	{
		aux = current;
		while (aux->prev != NULL && aux->n < aux->prev->n)
		{
			node_prev = aux->prev;
			if (aux->next != NULL)
				aux->next->prev = node_prev;

			if (node_prev->prev != NULL)
				node_prev->prev->next = aux;
			else
				*list = aux;

			node_prev->next = aux->next;
			aux->prev = node_prev->prev;
			aux->next = node_prev;
			node_prev->prev = aux;

			print_list(*list);
		}
		current = current->next;
	}
}

