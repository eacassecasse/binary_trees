#include "binary_trees.h"

/**
 * binary_tree_size - Custom function.
 *
 * @tree: A pointer to the root node of the tree.
 *
 * Description: Computes the size of a binary tree.
 * Return: The current size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t tree_size = 0;

	if (tree)
	{
		tree_size++;
		tree_size += binary_tree_size(tree->left);
		tree_size += binary_tree_size(tree->right);
	}

	return (tree_size);
}
