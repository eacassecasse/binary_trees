#include "binary_trees.h"

/**
 * binary_tree_node - Custom function.
 *
 * @parent: A pointer to the parent of the node.
 * @value: The value of the new node.
 *
 * Description: Creates a binary tree node
 * Return: a pointer to the new node, otherwise NULL.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
