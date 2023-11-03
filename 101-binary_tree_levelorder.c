#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_levelorder - Perform level-order traversal on a binary tree.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node. The value in the node
 *        must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (!tree || !func)
        return;

    if (tree)
    {
        int front = 0;
        int rear = 0;
        const binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 10000);
        const binary_tree_t *temp = tree;

        if (!queue)
            return;

        queue[rear] = temp;
        rear++;

        while (front != rear)
        {
            temp = queue[front];
            front++;

            func(temp->n);

            if (temp->left)
            {
                queue[rear] = temp->left;
                rear++;
            }
            if (temp->right)
            {
                queue[rear] = temp->right;
                rear++;
            }
        }

        free(queue);
    }
}
