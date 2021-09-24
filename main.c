#include "monty.h"

int main(int argc, char *argv[])
{
	int y, psh = 0;
	unsigned int ln = 1;
	ssize_t x_rd;
	char *bffr, *tkn;
	stck_b *header = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	y = open(argv[1], O_RDONLY);
	
	if (y == -1)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	bffr = malloc(sizeof(char) * 10000);

	if (!bffr)
		return (0);
	x_rd = read(y, bffr, 10000);

	if (x_rd == -1)
	{
		free(bffr);
		close(y);
		exit(EXIT_FAILURE);
	}

	tkn = strtok(bffr, "\n\t\a\r ;:");
	
	while (tkn != NULL)
	{
		if (psh == 1)
		{
			push(&header, ln, tkn);
			psh = 0;
			tkn = strtok(NULL, "\n\t\a\r ;:");
			ln++;
			continue;
		}
		else if (strcmp(tkn, "push") == 0)
		{
			psh = 1;
			tkn = strtok(NULL, "\n\t\a\r ;:");
			continue;
		}
		else
		{
			if (opfunc(tkn) != 0)
			{
				opfunc(tkn)(&header, ln);
			}
			else
			{
				free_lst(&header);
				printf("L%d: unknown instruction %s\n", ln, tkn);
				exit(EXIT_FAILURE);
			}
		}

		ln++;
		tkn = strtok(NULL, "\n\t\a\r ;:");
	}

	free_lst(&header); 
	free(bffr);
	close(y);
	return (0);
}
