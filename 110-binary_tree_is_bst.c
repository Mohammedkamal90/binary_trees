#include "binary_trees.h"

/**
 * is_bst_util - Check if a binary tree is a valid BST using a helper function.
 * @tree: A pointer to the root node of the tree to check.
 * @min: The minimum allowed value for the nodes.
 * @max: The maximum allowed value for the nodes.
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
int is_bst_util(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1);

    if (tree->n < min || tree->n > max)
        return (0);

    return (is_bst_util(tree->left, min, tree->n - 1) &&
            is_bst_util(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - Check if a binary tree is a valid BST.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return is_bst_util(tree, INT_MIN, INT_MAX);
}
