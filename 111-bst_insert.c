#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST).
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node;

    if (tree == NULL)
        return (NULL);

    if (*tree == NULL)
    {
        new_node = binary_tree_node(NULL, value);
        if (new_node == NULL)
            return (NULL);
        *tree = new_node;
        return (new_node);
    }

    if (value < (*tree)->n)
    {
        if ((*tree)->left == NULL)
        {
            new_node = binary_tree_node(*tree, value);
            if (new_node == NULL)
                return (NULL);
            (*tree)->left = new_node;
            return (new_node);
        }
        else
        {
            return bst_insert(&((*tree)->left), value);
        }
    }
    else if (value > (*tree)->n)
    {
        if ((*tree)->right == NULL)
        {
            new_node = binary_tree_node(*tree, value);
            if (new_node == NULL)
                return (NULL);
            (*tree)->right = new_node;
            return (new_node);
        }
        else
        {
            return bst_insert(&((*tree)->right), value);
        }
    }

    return (NULL);  /* Value is already in the tree, ignore it */
}
