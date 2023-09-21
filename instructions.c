#include "monty.h"
/**
 * instruction_prc - implement the instruction given in the file
 * @buffer: the given instruction
 * @stack: the given stack to work on
 * Return: 0 on success, else 1
*/
int instruction_prc(char buffer[], stack_t **stack)
{
	instruction_t code_lst[] = {{"push", push}, {"pall", pall},
				{NULL, NULL}};
	char *token;
	int x;

	token = strtok(buffer, " ");
	for (x = 0; code_lst[x].opcode != NULL; x++)
	{
		if (strcmp(token, code_lst[x].opcode) == 0)
		{
			if (strcmp(token, "push") == 0)
			{
				token = strtok(NULL, " \n");
				code_lst[x].f(stack, atoi(token));
				return (0);
			}
			else
			{
				code_lst[x].f(stack, 0);
				return (0);
			}
		}
	}
	return (1);

}

