#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Custom function.
 *
 * @node: The node to be check.
 *
 * Description: Checks if a node is or not a leaf.
 * Return: 1 if node is a leaf, otherwise 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node || node->left || node->right)
		return (0);

	return (1);
}
