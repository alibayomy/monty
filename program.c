#include "monty.h"
#include <stdio.h>
input_t input = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments passed to the program
* @argv: array of arguments passed
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t line_n = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	input.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (line_n > 0)
	{
		content = NULL;
		line_n = getline(&content, &size, file);
		input.content = content;
		counter++;
		if (line_n > 0)
		{
			execute(content, &stack, counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}

