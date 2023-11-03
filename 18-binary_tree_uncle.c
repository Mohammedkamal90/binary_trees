#include "binary_trees.h"

/**
 * binary_tree_uncle - Find the uncle of a node in a binary tree
 * @node: A pointer to the node to find the uncle
 * Return: A pointer to the uncle node, or NULL if the node has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
        return NULL;

    if (node->parent->parent->left != NULL && node->parent->parent->left != node->parent)
        return node->parent->parent->left;

    if (node->parent->parent->right != NULL && node->parent->parent->right != node->parent)
        return node->parent->parent->right;

    return NULL;
}
