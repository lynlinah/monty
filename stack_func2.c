#include "monty.h"

void monty_rotl(stack_t **stack, unsigned int counter);
void monty_rotr(stack_t **stack, unsigned int counter);
void monty_stack(stack_t **stack, unsigned int counter);

/**
 * monty_rotl - Rotates the top value of a stack_t linked list to the bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @counter: The current working line number of a Monty bytecodes file.
 */
void monty_rotl(stack_t **stack, unsigned int counter)
{
	{
	stack_t *runner = *stack;

	int aux1 = 0;

	if (!counter || !stack || !*stack || !(*stack)->next)
		return;

	aux1 = runner->n;

	while (runner->next)
	{
		runner = runner->next;
		runner->prev->n = runner->n;
	}

	runner->n = aux1;
}

/**
 * monty_rotr - mod top of stack y second top stacks
 * @stack: pointer to lists for monty stack
 * @counter: number of line opcode occurs on
 */
void monty_rotr(stack_t **stack, unsigned int counter)
{
	stack_t *runner = *stack;

	int aux1 = 0;

	if (!counter || !stack || !*stack || !(*stack)->next)
		return;

	while (runner->next)
		runner = runner->next;

	aux1 = runner->n;

	while (runner->prev)
	{
		runner = runner->prev;
		runner->next->n = runner->n;
	}

	runner->n = aux1;
}

/**
 * monty_stack - Converts a queue to a stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @counter: The current working line number of a Monty bytecodes file.
 */
void monty_stack(stack_t **stack, unsigned int counter)
{
	(*stack)->n = STACK;
	(void)counter;
}
