#include "binary_trees.h"

/**
 * binary_tree_nodes - Custom function.
 *
 * @tree: A pointer to the root node of the tree to count the number of nodes.
 *
 * Description: Counts the amount of nodes in a binary tree.
 * Return: The amount of nodes on the tree.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t tree_nodes = 0;

	if (tree)
	{
		tree_nodes += (tree->left || tree->right) ? 1 : 0;
		tree_nodes += binary_tree_nodes(tree->left);
		tree_nodes += binary_tree_nodes(tree->right);
	}

	return (tree_nodes);
}
