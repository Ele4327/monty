#include "monty.h"

void (*opfunc(char *tkn_a))(stck_b **stack, unsigned int line_number)
{
	strck_op_out strk_op[] = 
	{
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"add", _add},
		{"nop", nop},
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
