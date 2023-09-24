#include "monty.h"

/**
 * push - pushes an element of the stack
 * @stack: the stack to push the element in
 * @value: the value of the given stack to push
 * @line_number: the number of the line of the instruction
*/
void push(stack_t **stack, char  *value, unsigned int line_number)
{
	stack_t *top_element;
	stack_t *new_element;
	int i, n;


	for (i = 0; value[i] != '\0'; i++)
	{
		if (value[i] == '-' && i == 0)
			continue;
		if (value[i] < 48 || value[i] > 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(value);
	new_element = malloc(sizeof(stack_t));
	if (new_element == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_element);
		exit(EXIT_FAILURE);
	}
	new_element->n = n;
	new_element->next = NULL;
	new_element->prev = NULL;
	if ((*stack) == NULL)
	{
		*(stack) = new_element;
	}
	else
	{
		top_element = *stack;
		while (top_element->next)
			top_element = top_element->next;
		top_element->next = new_element;
		new_element->prev = top_element;
		top_element = top_element->next;
	}

}
/**
 * pall - prints all the values on the stack, starting from
 *		the top of the stack.
 * @stack: the given stack to be printed
 * @line_number: the number of the line of the instruction
 *
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	(void) line_number;
	if (!(*stack == NULL))
	{
		top = *stack;
		while (top->next)
			top = top->next;
		while (top)
		{
			printf("%d\n", top->n);
			top = top->prev;
		}
	}
}
/**
 * nop - doesn't do anything
 * @stack: the given stack
 * @line_number: the number line of the instruction
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

