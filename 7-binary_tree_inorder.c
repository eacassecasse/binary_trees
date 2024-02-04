#include "binary_trees.h"

/**
 * binary_tree_inorder - Custom function
 *
 * @tree: A pointer to the root node of the tree.
 * @func: A  function to call for each iteration.
 *
 * Description: Transverses a binary trees in in-order
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
