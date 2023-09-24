#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 * @stack: the given stack
 * @line_number: the value of the stack
*/
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	while (top->next)
		top = top->next;
	printf("%d\n", top->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: the given stack
 * @line_number: the  value of the element
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *tmp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	while (top->next)
		top = top->next;
	if (top->prev)
	{
		tmp = top->prev;
		tmp->next = NULL;
	}
	else
		*stack = NULL;
	free(top);
}
/**
 * swap - swap the top two elements of the stack
 * @stack: the given stack
 * @line_number: the given line number of the instruction in the file
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *before;
	stack_t *top;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
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
		temp = before->prev;
		temp->next = top;
		top->prev = temp;
		top->next = before;
		before->prev = top;
		before->next = NULL;
	}
	else
	{
		*stack = top;
		top->prev = NULL;
		top->next = before;
		before->prev = top;
		before->next = NULL;
	}
}
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

