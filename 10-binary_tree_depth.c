#include "binary_trees.h"

/**
 * binary_tree_depth - Custom function
 *
 * @tree: A pointer to the root of the tree.
 *
 * Description: Computes the depth of a node in a binary tree.
 * Return: The depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
