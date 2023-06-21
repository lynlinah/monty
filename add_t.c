#include "monty.h"

/**
 * add_t - adds the top two elements of the stack.
 * @head: double pointer to the stack
 * @line_number: line number of the instruction
 * Return: no return
*/
void add_t(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len = 0, top;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	top = h->n + h->next->n;
	h->next->n = top;
	*head = h->next;
	free(h);
}
