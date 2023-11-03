#include "binary_trees.h"

/**
 * binary_tree_size - Measure the size of a binary tree
 * @tree: A pointer to the root node of the tree to measure the size
 * Return: The size (number of nodes) of the binary tree, or 0 if the tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    /* Recursively calculate the size of the left and right subtrees */
    size_t left_size = binary_tree_size(tree->left);
    size_t right_size = binary_tree_size(tree->right);

    /* The size of the tree is the sum of the left and right subtree sizes plus 1 (for the current node) */
    return left_size + right_size + 1;
}
