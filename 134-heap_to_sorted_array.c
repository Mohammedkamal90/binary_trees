#include "binary_trees.h"

/**
 * heap_to_sorted_array - convert Binary Max Heap to a sorted array.
 * @heap: pointer to root node of the heap.
 * @size: adress to store size of the array.
 * Return: pointer to the sorted array (in descending order).
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *sorted_array = NULL;

    if (heap == NULL || size == NULL)
        return (NULL);

    *size = binary_tree_size(heap);
    if (*size == 0)
        return (NULL);

    sorted_array = malloc(sizeof(int) * (*size));
    if (sorted_array == NULL)
        return (NULL);

    for (size_t i = 0; i < *size; i++) {
        sorted_array[i] = heap->n;
        heap = heap_extract(&heap);
    }

    return (sorted_array);
}
