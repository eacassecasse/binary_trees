#include "binary_trees.h"

int _is_full(const binary_tree_t *tree);

/**
 * binary_tree_is_full - Custom function
 *
 * @tree: A pointer to the root of the tree.
 *
 * Description: Checks whether a binary tree is full or not.
 * Return: 1 if the tree is full, otherwise 0.
 */
int binary_tree_is_full(const binary_tree_t *tree) {
    if (!tree)
        return (0);
    return (_is_full(tree));
}

/**
 * _is_full - Custom function.
 *
 * @tree: A pointer to the root node of the tree.
 *
 * Description: Checks recursively whether a tree is full or not.
 * Return: 1 if the tree is full, otherwise 0.
 */
int _is_full(const binary_tree_t *tree) {
    if (tree != NULL) {
        if ((tree->left && !tree->right) ||
            (!tree->left && tree->right) ||
            _is_full(tree->left) == 0 ||
            _is_full(tree->right) == 0)
            return (0);
    }

    return (1);
}
