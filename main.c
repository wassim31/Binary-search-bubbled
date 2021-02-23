#include <stdlib.h>
#include <stdio.h>
#include "main.h"
int main(void)
{

    int size = 0, searched_element = 0;
    printf("how many  array's elements you want: ");
    scanf("%d", &size);

    // memory allocation for array in heap segement
    int *array = malloc(size * sizeof(int));
    printf("add values to your array:\n");
    array_init(array, size);

    bubble_sort(array, size);

    array_print(array, size);
    printf("which element you're searching for: ");
    scanf("%d", &searched_element);
    // call binary_search function
    int final_result = binary_search(array, 0, size - 1, searched_element);
    if(final_result < 0)
    {
        printf("not found");
    }
    else
    {
        printf("it's situated in index : %d", final_result);
    }
    // de-allocate the allocated space in heap memory for the array
    free(array);
    return 0;
}
void array_init(int *array, int size)
{
    int i;
    for(i = 0 ; i < size ; i++)
    {
        scanf("%d", &array[i]);
    }

}
void swap(int *a, int *b)
{
    if(*a > *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}
void bubble_sort(int *array, int size)
{
    int i, j;
    for(i = 0 ; i < size -1 ; i++)
    {
        for(j = 0 ; j < size - i - 1; j++)
        {
            if(array[j] > array[j+1])
            {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}
void array_print(int *array, int size)
{
    int i;
    for(i = 0 ; i < size ; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int binary_search(int *array, int start, int finish, int searched_number)
{
    if(finish >= start)
    {
        int middle = (finish + start) / 2;

        if(array[middle] == searched_number)
            return middle;
        if(searched_number > array[middle])
            return binary_search(array, middle + 1, finish, searched_number);
        else
        return binary_search(array, start, middle - 1, searched_number);
    }
    return -1;
}
