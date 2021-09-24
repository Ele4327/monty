#include "monty.h"

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
