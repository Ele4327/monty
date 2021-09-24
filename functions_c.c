#include "monty.h"

/**
 * x_eql_nmbr - Function
 * @x: Pointer to constant character.
 * Return: Always 0.
 */

int x_eql_nmbr(const char *x)
{
	int z = 0;

	if (*x == '-')
	{
		z = 1;
	}

	for (z = 1; *(x + z) != '\0'; z++)
	{
		if (isdigit(*(x + z)) == 0)
		{
			return (-1);
		}
	}

	return (0);
}

/**
 * push - Pushes an element to the stack.
 * @header: Head of linked list.
 * @line_number: Bytecode number.
 * @x: Integer.
 */

void push(stck_b **header, unsigned int line_number, const char *x)
{
	if (!header)
	{
		return;
	}

	if (x_eql_nmbr(x) == -1)
	{
		printf("L%u: usage: push integer\n", line_number);
		free_lst(header);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_lst_nd(header, atoi(x)) == -1)
		{
			free_lst(header);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * pop - Removes the top element of the stack.
 * @header: Head of linked list.
 * @line_number: Bytecode number.
 */

void pop(stck_b **header, unsigned int line_number)
{
	if (header == NULL || *header == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		free_lst(header);
		exit(EXIT_FAILURE);
	}
	else
	{
		dlt_lst_nd(header);
	}
}
