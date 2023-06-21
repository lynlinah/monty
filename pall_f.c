#include "monty.h"

/**
 * pall_f_t - Prints all the values on the stack
 * @stack: Pointer to the stack
 * @counter: Line number of the instruction
 * Return: no return
*/
void pall_f_t(stack_t **stack, unsigned int counter)
{
	stack_t *current;
	(void)counter;

	current = *head;
	if (current == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * push_f - Pushes an element to the stack.
 * @stack: Double pointer to the stack.
 * @counter: Line number of the instruction.
 * Return: No return value.
 */
void push_f(stack_t **stack, unsigned int counter)
{
	char *arg = bus.arg;

	if (!arg || !isdigit(*arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack_t(*stack);
		exit(EXIT_FAILURE);
	}

	int value = atoi(arg);
	stack_t *new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(bus.file);
		free(bus.content);
		free_stack_t(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
