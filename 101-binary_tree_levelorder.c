#include "binary_trees.h"

levelorder_t *create_node(binary_tree_t *node);
void print_enqueue(binary_tree_t *node, levelorder_t *head,
		levelorder_t **tail, void (*func)(int));
void clean_queue(levelorder_queue_t *head);
void dequeue(levelorder_t **head);

/**
 * binary_tree_levelorder - Custom function
 *
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 *
 * Description: Transverses a binary trees in level-order.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		pint_push(head->node, head, &tail, func);
		pop(&head);
	}
}

/**
 * create_node - Custom function
 *
 * @node: The binary tree node for the new node to contain.
 *
 * Description: Creates a new node on a levelorder queue.
 * Return: A pointer to the new node, otherwise NULL.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new_node;

	new_node = malloc(sizeof(levelorder_t));
	if (!new_node)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}

/**
 * enqueue - Custom function
 *
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 * @func: A pointer to the function to call on @node.
 *
 * Description: Executes a function on a binary tree enqueueing its
 *              children into a levelorder queue
 */
void print_enqueue(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new_node;

	func(node->n);
	if (node->left)
	{
		new_node = create_node(node->left);
		if (!new_node)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new_node;
		*tail = new_node;
	}
	if (node->right)
	{
		new_node = create_node(node->right);
		if (!new_node)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new_node;
		*tail = new_node;
	}
}

/**
 * free_queue - Custom function
 *
 * @head: A pointer to the head of the queue.
 *
 * Description: Frees the levelorder queue.
 */
void clean_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * dequeue - Custom function
 *
 * @head: A double pointer to the head of the queue.
 *
 * Description: Removes the head of a levelorder queue.
 */
void dequeue(levelorder_t **head)
{
	levelorder_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}
