#include "monty.h"
/**
 * instruction_prc - implement the instruction given in the file
 * @buffer: the given instruction
 * @stack: the given stack to work on
 * @line_number: the number of the line of the given instruction
 * Return: 0 on success, else 1
*/
int instruction_prc(char buffer[], stack_t **stack, int line_number)
{
	instruction_t code_lst[] = {{"pall", pall},
								{"pint", pint},
								{"pop", pop},
								{"swap", swap},
								{"add", add},
								{"nop", nop},
								{NULL, NULL}};
	char *token;
	int x;

	token = strtok(buffer, " \n\t");
	if (strcmp(token, "push") == 0)
	{
		token = strtok(NULL, " \n");
		push(stack, token, line_number);
		return (0);
	}
	else
	{
		for (x = 0; code_lst[x].opcode != NULL; x++)
		{
			if (strcmp(token, code_lst[x].opcode) == 0)
			{
				code_lst[x].f(stack, line_number);
				return (0);
			}
		}
	}
	return (1);

}

