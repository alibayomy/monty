#include "monty.h"
/**
 * add - add adds the top two elements of the stack.
 * @stack: the given stack to add on;
 * @line_number: the number of the line of the instruction
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *before;
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
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
		before->n = (top->n) + (before->n);
		before->next = NULL;
		free(top);
	}
	else
	{
		*stack = top;
		top->n = (top->n) + (before->n);
		top->next = NULL;
		top->prev = NULL;
		free(before);
	}
}
