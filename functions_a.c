#include "monty.h"

/**
 * add_lst_nd - Add node to front of doubly linked list.
 * @header: Pointer to head of list.
 * @x: Node value.
 * Return: 0 if success, -1 if failed.
 */

int add_lst_nd(stck_b **header, int x)
{
	stck_b *nw_nd;

	if (!header)
	{
		return (-1);
	}

	nw_nd = malloc(sizeof(struct stck_a));

	if (!nw_nd)
	{
		printf("Error: malloc failed");
		return (-1);
	}

	nw_nd->x = x;

	if (*header == NULL)
	{
		*header = nw_nd;
		nw_nd->next = NULL;
		nw_nd->prev = NULL;
	}
	else
	{
		nw_nd->next = *header;
		(*header)->prev = nw_nd;
		*header = nw_nd;
	}

	return (0);
}

/**
 * dlt_lst_nd - Deletes node at end of doubly linked list.
 * @header: Pointer to head of doubly linked list.
 */

void dlt_lst_nd(stck_b **header)
{
	stck_b *dlt = NULL;

	dlt = *header;
	if ((*header)->next == NULL)
	{
		*header = NULL;
		free(dlt);
	}
	else
	{
		*header = (*header)->next;
		(*header)->prev = NULL;
		free(dlt);
	}
}

/**
 * free_lst - Frees a doubly linked list with only int data.
 * @header: Pointer to head of list.
 */

void free_lst(stck_b **header)
{
	if (!header)
	{
		return;
	}

	while (*header && (*header)->next)
	{
		*header = (*header)->next;
		free((*header)->prev);
	}

	free(*header);
}
