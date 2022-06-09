/*
Jayneel M Shah
11:16, 09-06-22
Topic - Selection Sort
Worst Case Time Complexity - O(n^2)
Number of Comparisons - O(n^2)
Number of swaps - O(n)
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

void selectionSort(int a[], int n)
{
    int i, j, k;

    // for loop for number of passes = n - 1;
    for (i = 0; i < n - 1; i++)
    {
        // for loop for finding the index of smallest element
        for (j = k = i; j < n; j++)
        {
            // calling k to the index where the element is smaller than the element at j
            if (a[j] < a[k])
            {
                k = j;
            }
        }
        swap(&a[i], &a[k]);
        printf("After Pass %d - ", (i + 1));
        display(a, n);
    }
}

int main()
{
    int n, *arr;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(n));

    printf("Enter the elements -\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", (i + 1));
        scanf("%d", &arr[i]);
    }

    printf("Elements entered are - \n");
    display(arr, n);

    selectionSort(arr, n);

    printf("Sorted Elements are -\n");
    display(arr, n);
}
