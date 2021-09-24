#ifndef MONTY_H
#define MONTY_H

/* Libraries */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* Structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @x: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stck_a
{
	int x;
	struct stck_a *prev;
	struct stck_a *next;
} stck_b;

/**
 * strck_op - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct strck_op
{
	char *opcode;
	void (*f)(stck_b **stack, unsigned int line_number);
} strck_op_out;

/* Main Functions Prototypes */

void (*opfunc(char *tkn_a))(stck_b **stack, unsigned int line_number);
void push(stck_b **h, unsigned int line_number, const char *n);
void pop(stck_b **h, unsigned int line_number);
void pint(stck_b **h, unsigned int line_number);
void pall(stck_b **h, unsigned int line_number);
void swap(stck_b **h, unsigned int line_number);
void nop(stck_b **h, unsigned int line_number);

void _add(stck_b **header, unsigned int line_number);
void _sub(stck_b **header, unsigned int line_number);
void _mul(stck_b **header, unsigned int line_number);
void _div(stck_b **header, unsigned int line_number);
void _mod(stck_b **header, unsigned int line_number);

/* Stacks Prototypes */
int add_lst_nd(stck_b **h, int n);
void dlt_lst_nd(stck_b **h);
void free_lst(stck_b **h);

#endif
