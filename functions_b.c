#include "header.h"

void swap(stck_b **header, unsigned int line_number)
{
	stck_b *tmp = NULL;

	if (*header == NULL || (*header)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*header)->next;

	if (tmp->next != NULL)
	{
		(*header)->next = tmp->next;
		(*header)->next->prev = *header;

	}
	else
	{
		tmp->prev->prev = tmp;
		tmp->prev->next = NULL;
	}

	tmp->prev = NULL;
	tmp->next = *header;
	(*header) = tmp;
}

void pall(stck_b **header, unsigned int line_number)
{
	stck_b *prvsnl = NULL;

	if (!header || !*header)
	{
		return;
	}

	(void) line_number;
	prvsnl = *header;
	
	while (prvsnl != NULL)
	{
		printf("%d\n", prvsnl-> x);
		prvsnl = prvsnl-> next;
	}
}

void pint(stck_b **header, unsigned int line_number)
{
	if (!header || !*header)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	printf("%d\n", (*header) -> x);
}

void nop(stck_b **header, unsigned int line_number)
{
	(void)header;
	(void)line_number;
}
