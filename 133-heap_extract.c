#include "binary_trees.h"

/**
 * heapify_down - helper function to fix max heap property.
 * @root: double pointer to root node of heap.
 */
void heapify_down(heap_t **root)
{
    heap_t *current = *root;
    heap_t *max_child = NULL;
    int temp;

    while (1) {
        max_child = current->left;

        if (!max_child)
            break;

        if (current->right && current->right->n > max_child->n)
            max_child = current->right;

        if (current->n < max_child->n) {
            temp = current->n;
            current->n = max_child->n;
            max_child->n = temp;
            current = max_child;
        } else {
            break;
        }
    }
}

/**
 * get_last_node - helper function to get last level-order node.
 * @root: pointer to root node of the heap.
 * Return: pointer to last level-order node.
 */
heap_t *get_last_node(heap_t *root)
{
    while (root->left || root->right) {
        if (root->right)
            root = root->right;
        else
            root = root->left;
    }
    return (root);
}

/**
 * heap_extract - extract root node of a Max Binary Heap.
 * @root: double pointer to root node of the heap.
 * Return: value stored in root node.
 */
int heap_extract(heap_t **root)
{
    int value;
    heap_t *last_node;

    if (root == NULL || *root == NULL)
        return (0);

    value = (*root)->n;
    last_node = get_last_node(*root);

    if (last_node->parent) {
        if (last_node->parent->left == last_node)
            last_node->parent->left = NULL;
        else
            last_node->parent->right = NULL;
    } else {
        *root = NULL;
    }

    (*root)->n = last_node->n;
    free(last_node);
    heapify_down(root);

    return (value);
}

