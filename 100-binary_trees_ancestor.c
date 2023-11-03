#include "binary_trees.h"

/**
 * binary_trees_ancestor - Find the lowest common ancestor of two nodes
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 * Return: A pointer to the lowest common ancestor node, or NULL if none is found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    const binary_tree_t *temp1, *temp2;
    size_t depth1, depth2;

    if (!first || !second)
        return NULL;

    temp1 = first;
    temp2 = second;
    depth1 = depth2 = 0;

    while (temp1->parent || temp1)
    {
        depth1++;
        temp1 = temp1->parent;
    }

    while (temp2->parent || temp2)
    {
        depth2++;
        temp2 = temp2->parent;
    }

    temp1 = first;
    temp2 = second;

    while (depth1 > depth2)
    {
        temp1 = temp1->parent;
        depth1--;
    }

    while (depth2 > depth1)
    {
        temp2 = temp2->parent;
        depth2--;
    }

    while (temp1 && temp2 && temp1 != temp2)
    {
        temp1 = temp1->parent;
        temp2 = temp2->parent;
    }

    if (temp1 && temp2)
        return (binary_tree_t *)temp1;

    return NULL;
}
