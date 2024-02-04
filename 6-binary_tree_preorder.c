#include "binary_trees.h"

/**
 * binary_tree_preorder - Custom function
 *
 * @tree: A pointer to the root node of the tree.
 * @func: A function to call for each iteration.
 *
 * Description: Transverses a binary trees in pre-order
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
