#include "monty.h"

/**
 * pchar_f - prints the char at the top of the stack,
 * followed by a new line
 * @stack: Double pointer to the stack
 * @counter: Line number of the instruction
 * Return: no return
*/
void pchar_f(stack_t **stack, unsigned int counter)
{
	stack_t *h;

	h = *stack;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack_t(*stack);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack_t(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
