#include "binary_trees.h"

/**
 * binary_tree_preorder - go throug binary tree use pre-order traversal
 * @tree: pointer to root node of tree to traverse
 * @func: pointer to function to call for each node
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    func(tree->n);  // Call the function with the value of the current node
    binary_tree_preorder(tree->left, func);    // Recursively traverse the left subtree
    binary_tree_preorder(tree->right, func);   // Recursively traverse the right subtree
}

