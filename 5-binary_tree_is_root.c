#include "binary_trees.h"

/**
 * binary_tree_is_root - check if node is root of binary tree
 * @node: A pointer to node to check
 * Return: if node is root - 1
 *         Otherwise - 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
    if (node == NULL)
        return (0);

    if (node->parent == NULL)
        return (1);

    return (0);
}

