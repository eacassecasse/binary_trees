#include "binary_trees.h"

/**
 * binary_tree_uncle - Custom function
 *
 * @node: A pointer to the node to find the uncle.
 *
 * Description: Gets the uncle of a node.
 * Return: The uncle or NULL if the parent has no sibling.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent ||
	    !node->parent->parent)
		return (NULL);

	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	return (node->parent->parent->left);
}
