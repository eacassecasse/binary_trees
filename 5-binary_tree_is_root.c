#include "binary_trees.h"

/**
 * binary_tree_is_root - Custom function
 *
 * @node: A pointer to the node to check.
 *
 * Description: Checks if a node is or not a root.
 * Return: 1 if the node is a root, otherwise 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node || node->parent)
		return (0);

	return (1);
}
