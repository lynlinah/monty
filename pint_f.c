#include "monty.h"

/**
 * pint_f - Prints the value at the top of the stack
 * @stack: Double pointer to the stack
 * @counter: Line number of the instruction
 * Return: no return
*/
void pint_f(stack_t **stack, unsigned int counter)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack_t(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
