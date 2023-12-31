#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert node as left-child of
 *                 of another in a binary tree.
 * @parent: pointer to the node to insert the left-child in.
 * @value: Value to store in new node
 * Return: if parent is NULL or an error occurs - NULL.
 *         otherwise - pointer to new node
 * Description: if parent already has left-child, new node
 *           takes its place and old left-child is set as
 *           left-child of new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    if (parent == NULL)
        return (NULL);

    new_node = binary_tree_node(parent, value);
    if (new_node == NULL)
        return (NULL);

    if (parent->left != NULL)
    {
        new_node->left = parent->left;
        parent->left->parent = new_node;
    }
    parent->left = new_node;

    return (new_node);
}

