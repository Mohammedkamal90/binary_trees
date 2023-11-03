#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect
 * @tree: A pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    /* Calculate the height of the left and right subtrees */
    int left_height = binary_tree_height(tree->left);
    int right_height = binary_tree_height(tree->right);

    /* Check if the tree is balanced and all levels are filled */
    if (left_height == right_height)
    {
        /* If it's a leaf node, return 1; otherwise, check subtrees */
        if (tree->left == NULL && tree->right == NULL)
            return 1;
        else
            return binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right);
    }

    return 0;
}
