#include "binary_trees.h"

/**
 * binary_trees_ancestor - Custom function
 *
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Description: Gets the lowest common ancestor of 2 nodes.
 * Return: A pointer to the lowest common ancestor of the 2 given nodes.
 *         NULL if no common ancestor was found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second) {
    binary_tree_t *left_parent, *right_parent;

    if (!first || !second)
        return (NULL);
    if (first == second)
        return ((binary_tree_t *) first);

    right_parent = first->parent, left_parent = second->parent;
    if (first == left_parent || !right_parent ||
        (!right_parent->parent && left_parent))
        return (binary_trees_ancestor(first, left_parent));
    else if (right_parent == second || !left_parent ||
             (!left_parent->parent && right_parent))
        return (binary_trees_ancestor(right_parent, second));

    return (binary_trees_ancestor(right_parent, pop));
}
