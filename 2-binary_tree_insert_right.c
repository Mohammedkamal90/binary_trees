#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - insert node as right-child
 *          of another in binary tree
 * @parent: pointer to the node to insert right-child in
 * @value: value to store in new node
 * Return:  parent is NULL or an error occur - NULL
 *         Otherwise - pointer to new node
 * Description: If parent already has a right-child, the new node
 *            take its place and old right-child is set as
 *            right-child of new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    if (parent == NULL)
        return (NULL);

    new_node = binary_tree_node(parent, value);
    if (new_node == NULL)
        return (NULL);

    if (parent->right != NULL)
    {
        new_node->right = parent->right;
        parent->right->parent = new_node;
    }
    parent->right = new_node;

    return (new_node);
}

