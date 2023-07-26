#include "shell.h"

/**
 * als_end_add - Adds a node to the end of a alias_t linked list.
 * @head: pointer to the head of the list_t list.
 * @name: name of the new alias to be added.
 * @value: value of the new alias to be added.
 *
 * Return: If an error - NULL. Otherwise - pointer to new node.
 */
alias_t *als_end_add(alias_t **head, char *name, char *value)
{
	alias_t *new_node = malloc(sizeof(alias_t));
	alias_t *last;

	if (!new_node)
		return (NULL);

	new_node->next = NULL;
	new_node->name = malloc(sizeof(char) * (_strlen(name) + 1));
	if (!new_node->name)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = value;
	_strcpy(new_node->name, name);

	if (*head)
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
	else
		*head = new_node;

	return (new_node);
}

/**
 * add_on_node_end - node to the end of a list_t linked list.
 * @head: pointer to the head of the list_t list.
 * @dir: directory path for the new node to contain.
 *
 * Return: If an error - NULL.Otherwise - pointer to new node.
 */
list_t *add_on_node_end(list_t **head, char *dir)
{
	list_t *new_node = malloc(sizeof(list_t));
	list_t *last;

	if (!new_node)
		return (NULL);

	new_node->dir = dir;
	new_node->next = NULL;

	if (*head)
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
	else
		*head = new_node;

	return (new_node);
}

/**
 * als_free_list - Free  linked list.
 * @head: THe head of list.
 */
void als_free_list(alias_t *head)
{
	alias_t *next;

	while (head)
	{
		next = head->next;
		free(head->name);
		free(head->value);
		free(head);
		head = next;
	}
}

/**
 * free_list - Free linked list.
 * @head: The head of ist.
 */
void free_list(list_t *head)
{
	list_t *next;

	while (head)
	{
		next = head->next;
		free(head->dir);
		free(head);
		head = next;
	}
}
