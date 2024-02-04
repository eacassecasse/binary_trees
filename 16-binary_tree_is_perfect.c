#include "binary_trees.h"

int _is_perfect(const binary_tree_t *tree,
                size_t depth, size_t level);

const binary_tree_t *get_leaf(const binary_tree_t *tree);

size_t _depth(const binary_tree_t *tree);

int _is_leaf(const binary_tree_t *node);

/**
 * binary_tree_is_perfect - Custom function
 *
 * @tree: A pointer to the root of the tree.
 *
 * Description: Checks whether a binary tree is perfect or not.
 *
 * Return: 1 if the tree is perfect, otherwise 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree) {
    if (!tree)
        return (0);
    return (_is_perfect(tree, _depth(get_leaf(tree)), 0));
}

/**
 * _depth - Custom function
 * @tree: A pointer to the root of the tree.
 *
 * Description: Computes the depth of a node in a binary tree.
 * Return: The depth.
 */
size_t _depth(const binary_tree_t *tree) {
    return ((tree && tree->parent) ? 1 + _depth(tree->parent) : 0);
}

/**
 * get_leaf - Custom function
 * @tree: A pointer to the root of the tree.
 *
 * Description: Gets a leaf on a binary tree.
 * Return: A pointer to the first leaf encountered.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree) {
    if (_is_leaf(tree) == 1)
        return (tree);
    return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * _is_perfect - Custom function
 * @tree: A pointer to the root of the tree.
 * @depth: The depth of one leaf in the binary tree.
 * @level: Level of current node.
 *
 * Description: Checks recursively whether a tree is perfect or not.
 * Return: 1 if the tree is perfect, otherwise 0.
 */
int _is_perfect(const binary_tree_t *tree,
                size_t depth, size_t level) {
    if (_is_leaf(tree))
        return (level == depth ? 1 : 0);
    if (!tree->left || !tree->right)
        return (0);
    return (_is_perfect(tree->left, depth, level + 1) &&
            _is_perfect(tree->right, depth, level + 1));
}

/**
 * _is_leaf - Custom function.
 *
 * @node: The node to be check.
 *
 * Description: Checks if a node is or not a leaf.
 * Return: 1 if node is a leaf, otherwise 0.
 */
int _is_leaf(const binary_tree_t *node) {
    return ((!node->left && !node->right) ? 1 : 0);
}
