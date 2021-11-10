/*
Jayneel M Shah
18:42, 10-11-21
Topic - Bubble Sort
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubbleSort(int a[], int n)
{
    int i, j, flag = 0; // flag to check if the elements are already sorted, set to 0 after every pass
    // loop for number of passes
    for (i = 0; i < n - 1; i++)
    {
        // loop for comparing all elements in every pass
        for (j = 0; j < n - 1 - i; j++) // after every pass the comparison reduces so j < n - 1 - i
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                flag = 1;
            }
        }

        printf("Elements after pass %d - ", (i + 1));
        display(a, n);

        // we break out of the loop as it is already sorted.
        if (flag == 0)
        {
            break;
        }
    }
}

int main()
{
    int n, *arr;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int));

    printf("Enter the elements -\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", (i + 1));
        scanf("%d", &arr[i]);
    }

    printf("Elements entered are - \n");
    display(arr, n);

    bubbleSort(arr, n);

    printf("Sorted Elements are -\n");
    display(arr, n);
}
