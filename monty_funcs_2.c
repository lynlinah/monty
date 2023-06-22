#include "monty.h"

void monty_nop(stack_t **stack, unsigned int counter);
void monty_pchar(stack_t **stack, unsigned int counter);
void monty_pstr(stack_t **stack, unsigned int counter);

/**
 * monty_nop - Does absolutely nothing.
 * @stack: A pointer to the top mode.
 * @counter: The current working line number.
 */
void monty_nop(stack_t **stack, unsigned int counter)
{
	(void)stack;
	(void)counter;
}

/**
 * monty_pchar - Prints the character in the top value
 *               node of a stack_t linked list.
 * @stack: A pointer to the top mode node.
 * @counter: The current working line number.
 */
void monty_pchar(stack_t **stack, unsigned int counter)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(counter, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(counter,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * monty_pstr - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node.
 * @counter: The current working line number.
 */
void monty_pstr(stack_t **stack, unsigned int counter)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)counter;
}
