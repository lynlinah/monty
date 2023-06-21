#include "monty.h"

/**
 * addnode_t - add node to the head stack
 * @head: double pointer to the head of the stack
 * @n: value to be added
 * @line_number: line number of the instruction
 * Return: no return
*/
void addnode_t(stack_t **head, int n, unsigned int line_number)
{

	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "L%d: unable to allocate memory\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
