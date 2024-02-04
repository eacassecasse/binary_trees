#include "binary_trees.h"

/**
 * binary_tree_delete - Custom function
 *
 * @tree: A pointer to the root node of the tree to delete.
 *
 * Description: Deletes an entire binary tree.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
