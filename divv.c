#include "monty.h"
/**
 * div -  div the top two elements of the stack.
 * @stack: the given stack to add on;
 * @line_number: the number of the line of the instruction
*/
void divv(stack_t **stack, unsigned int line_number)
{
	stack_t *before;
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too div\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	while (top->next)
	{
		top = top->next;
		before = top->prev;
	}
	if (before->prev)
	{
		if (top->n == 0)
		{
			fprintf(stderr, "L%d: can't div, division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		before->n =  (before->n) / (top->n);
		before->next = NULL;
		free(top);
	}
	else
	{
		*stack = top;
		if (top->n == 0)
		{
			fprintf(stderr, "L%d: can't div, division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		top->n = (before->n) / (top->n); 
		top->next = NULL;
		top->prev = NULL;
		free(before);
	}
}

