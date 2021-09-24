#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @header: Node to be swapped.
 * @line_number: Node number.
 */

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

/**
 * pall - Prints all the values on the stack,
 * starting from the top of the stack.
 * @header: Head of list.
 * @line_number: Bytecode number.
 */

void pall(stck_b **header, unsigned int line_number)
{
	stck_b *prvsnl = NULL;

	if (!header || !*header)
	{
		return;
	}

	(void)line_number;
	prvsnl = *header;

	while (prvsnl != NULL)
	{
		printf("%d\n", prvsnl->x);
		prvsnl = prvsnl->next;
	}
}

/**
 * pint - Prints the value at the top of the stack,
 * followed by a new line.
 * @header: Head of list.
 * @line_number: Bytecode number.
 */

void pint(stck_b **header, unsigned int line_number)
{
	if (!header || !*header)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*header)->x);
}

/**
 * nop - Doesn’t do anything.
 * @header: Head of list.
 * @line_number: Bytecode number.
 */

void nop(stck_b **header, unsigned int line_number)
{
	(void)header;
	(void)line_number;
}
