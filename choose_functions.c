#include "monty.h"

void (*opfunc(char *tkn_a))(stck_b **stack, unsigned int line_number)
{
	strck_op_out strk_op[] = 
	{
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"nop", nop},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL}
	};

	int x = 0;

	while (strk_op[x].f != NULL)
	{
		if (strcmp(tkn_a, strk_op[x].opcode) == 0)
		{
			return(strk_op[x].f);
		}
		x++;
	}
	return (NULL);
}
