#include <stdlib.h>
#include <stdio.h>
#include "main.h"
int main(void)
{

    int SIZE = 0, searched_element = 0;
    printf("how many  array's elements you want: ");
    scanf("%d", &SIZE);

    // memory allocation for array in heap segement
    int *array = malloc(SIZE * sizeof(int));
    // init of array
    array_init(array, SIZE);
    // sort array using bubble sort
    bubble_sort(array, SIZE);
    // print array after sorting it
    array_print(array, SIZE);
    // asking for searched element
    printf("which element you're searching for: ");
    scanf("%d", &searched_element);
    // call binary_search function
    int final_result = binary_search(array, 0, (SIZE - 1), searched_element);
    if(final_result < 0)
    {
        printf("not found");
    }
    else
    {
        printf("%d", final_result);
    }
    // de-allocate the allocated space in heap memory for the array
    free(array);
    return 0;
}
void array_init(int *array, int SIZE)
{
    printf("add values to your array:\n");
    int i;
    for(i = 0 ; i < SIZE ; i++)
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
void bubble_sort(int *array, int SIZE)
{
    int i, j;
    for(i = 0 ; i < SIZE -1 ; i++)
    {
        for(j = 0 ; j < SIZE - i - 1; j++)
        {
            if(array[j] > array[j+1])
            {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}
void array_print(int *array, int SIZE)
{
    int i;
    for(i = 0 ; i < SIZE ; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int binary_search(int *array, int min, int max_one, int searched_number)
{
    if(max_one >= min)
    {
        int middle = (max_one + min) / 2;

        if(array[middle] == searched_number)
        {
            printf("Found : ");
            return middle;
        }
        if(searched_number > array[middle])
        {
            return binary_search(array, (middle+1), max_one, searched_number);
        }

        return binary_search(array, min, (middle-1), searched_number);
    }
    return -1;
}
