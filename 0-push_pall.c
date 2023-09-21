#include "monty.h"
/**
 * push - pushes an element of the stack
 * @stack: the stack to push the element in
 * @line_number: the number of the line of the instruction
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *top_element;
	stack_t *new_element;

	new_element = malloc(sizeof(stack_t));
	if (new_element == NULL)
	{
		fprintf(stderr, "Error: malloc failed/n");
		exit(EXIT_FAILURE);
	}
	new_element->n = line_number;
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
	if (*stack == NULL)
	{
		printf("\n");
	}
	else
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

