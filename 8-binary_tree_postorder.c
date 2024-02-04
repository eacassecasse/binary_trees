#include "binary_trees.h"

/**
 * binary_tree_postorder - Custom function
 *
 * @tree: A pointer to the root node of the tree.
 * @func: A function to call for each iteration.
 *
 * Description: Transverses a binary trees in post-order
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
