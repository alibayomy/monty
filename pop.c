#include "monty.h"
/**
 * f_pop - prints the top
 * @head: stack head
 * @counter: line_number of the given instruction
 * Return: no return
*/
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(input.file);
		free(input.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

