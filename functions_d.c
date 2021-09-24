#include "monty.h"

/**
 * _add - Adds the top two elements of the stack.
 * @header: Head of linked list.
 * @line_number: Bytecode number.
 * Return: Nothing.
 */

void _add(stck_b **header, unsigned int line_number)
{
	if (*header == NULL || (*header)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*header)->next->x += (*header)->x;
	(*header) = (*header)->next;
	free((*header)->prev);
	(*header)->prev = NULL;
}

/**
 * _sub -  Subtracts the top element of the stack,
 * from the second top element of the stack.
 * @header: Head of linked list.
 * @line_number: Bytecode number.
 * Return: Nothing.
 */

void _sub(stck_b **header, unsigned int line_number)
{
	if (*header == NULL || (*header)->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*header)->next->x -= (*header)->x;
	(*header) = (*header)->next;
	free((*header)->prev);
	(*header)->prev = NULL;
}

/**
 * _mul - Multiplies the second top element of the stack
 * with the top element of the stack.
 * @header: Head of linked list.
 * @line_number: Bytecode number.
 * Return: Nothing.
 */

void _mul(stck_b **header, unsigned int line_number)
{
	if (*header == NULL || (*header)->next == NULL)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*header)->next->x *= (*header)->x;
	(*header) = (*header)->next;
	free((*header)->prev);
	(*header)->prev = NULL;
}

/**
 * _div - Divides the second top element of the stack
 * by the top element of the stack.
 * @header: Head of linked list.
 * @line_number: Bytecode number.
 * Return: Nothing.
 */

void _div(stck_b **header, unsigned int line_number)
{
	if (*header == NULL || (*header)->next == NULL)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*header)->x == 0 || (*header)->next->x == 0)
	{
		printf("L%u: division by zero\n", line_number);
	}

	(*header)->next->x /= (*header)->x;
	(*header) = (*header)->next;
	free((*header)->prev);
	(*header)->prev = NULL;
}

/**
 * _mod - Computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @header: Head of linked list.
 * @line_number: Bytecode number.
 * Return: Nothing.
 */

void _mod(stck_b **header, unsigned int line_number)
{
	if (header == NULL || *header == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*header)->x == 0 || (*header)->next->x == 0)
	{
		printf("L%u: division by zero\n", line_number);
	}

	(*header)->next->x %= (*header)->x;
	(*header) = (*header)->next;
	free((*header)->prev);
	(*header)->prev = NULL;
}
