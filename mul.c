#include "monty.h"
/**
 * mul -  mul the top two elements of the stack.
 * @stack: the given stack to add on;
 * @line_number: the number of the line of the instruction
*/
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *before;
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
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
		before->n = (top->n) * (before->n);
		before->next = NULL;
		free(top);
	}
	else
	{
		*stack = top;
		top->n = (top->n) * (before->n);
		top->next = NULL;
		top->prev = NULL;
		free(before);
	}
}
