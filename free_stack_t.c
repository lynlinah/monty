#include "monty.h"

/**
* free_stack_t - frees a doubly linked list
* @stack: double pointer to the head of the stack
* Return: no return
*/
void free_stack_t(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}
