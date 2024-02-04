#include "binary_trees.h"

/**
 * binary_tree_sibling - Custom function
 *
 * @node: A pointer to the node to get the sibling.
 *
 * Description: Gets a sibling of a node.
 * Return: The sibling or NULL if node has no sibling or parent has no child.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}
