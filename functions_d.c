#include "monty.h"

void _add(stck_b **header, unsigned int line_number)
{
    if (*header == NULL || (*header)->next == NULL)
    {
        printf("L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*header)-> next-> x += (*header)-> x;
    (*header) = (*header) -> next;
    free((*header) -> prev);
    (*header) -> prev = NULL;
}

void _sub(stck_b **header, unsigned int line_number)
{
    if (*header == NULL || (*header)->next == NULL)
    {
        printf("L%u: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*header) -> next -> x -= (*header) -> x;
    (*header) = (*header) -> next;
    free((*header) -> prev);
    (*header) -> prev = NULL;
}

void _mul(stck_b **header, unsigned int line_number)
{
    if (*header == NULL || (*header) -> next == NULL)
    {
        printf("L%u: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*header) -> next -> x *= (*header) -> x;
    (*header) = (*header) -> next;
    free((*header) -> prev);
    (*header) -> prev = NULL;
}

void _div(stck_b **header, unsigned int line_number)
{
    if (*header == NULL || (*header) -> next == NULL)
    {
        printf("L%u: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    if ((*header) -> x == 0 || (*header) -> next -> x == 0)
    {
        printf("L%u: division by zero\n", line_number);
    }

    (*header) -> next -> x /= (*header) -> x;
    (*header) = (*header) -> next;
    free((*header) -> prev);
    (*header) -> prev = NULL;
}

void _mod(stck_b **header, unsigned int line_number)
{
	if (header == NULL || *header == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*header) -> x == 0 || (*header) -> next -> x == 0)
	{
		printf("L%u: division by zero\n", line_number);
	}

	(*header) -> next-> x %= (*header) -> x;
	(*header) = (*header) -> next;
	free((*header) -> prev);
	(*header) -> prev = NULL;
}