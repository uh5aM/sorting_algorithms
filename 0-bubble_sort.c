#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble Sort algorithm.
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp;
    int swapped;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                /* Swap array[j] and array[j + 1] */
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                print_array(array, size);
                swapped = 1;
            }
        }

        /* If no two elements were swapped, the array is already sorted */
        if (swapped == 0)
            break;
    }
}
