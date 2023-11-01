#include "binary_trees.h"

/**
 * binary_tree_inorder - go through binary tree using in-order traversal
 * @tree: pointer to root node of tree to traverse
 * @func: pointer to function to call for each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    binary_tree_inorder(tree->left, func);    // Recursively traverse the left subtree
    func(tree->n);  // Call the function with the value of the current node
    binary_tree_inorder(tree->right, func);   // Recursively traverse the right subtree
}

