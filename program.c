#include "monty.h"
/**
 * main - creat an interpreter for Monty ByteCode files
 * @argc: number of arguments passed to the program
 * @argv: array of strings of the given arguments to the program
 * Return: 0 on sucess, FALIURE_STATUS on faliure
*/
int main(int argc, char **argv)
{
	FILE *fptr;
	char input[1204];
	int line_number = 0, status;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fptr = fopen(argv[1], "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(input, 1204, fptr) != NULL)
	{
		line_number++;
		status = instruction_prc(input, &stack);
		if (status == 1)
		{
			fprintf(stderr, "L%d unknown instruction %s\n", line_number, input);
		}
	}
	fclose(fptr);
	return (0);
}

