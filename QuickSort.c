/*
Jayneel M Shah
11:20, 09-06-22
Topic - Quick Sort
Worst Case Time Complexity - O(n^2)
Best Case Time Complexity - O(nlogn)
Divide and Conquer
*/
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
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

int partition(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;

    do
    {
        do
        {
            i++;
        } while (a[i] <= pivot);

        do
        {
            j--;
        } while (a[j] > pivot);

        if (i < j)
        {
            swap(&a[i], &a[j]);
        }

    } while (i < j);

    swap(&a[l], &a[j]);

    return j;
}

void quickSort(int a[], int l, int h, int n)
{
    int j;
    if (l < h)
    {
        j = partition(a, l, h);
        printf("After Partition - ");
        //After every partition the pivot element is placed at its proper place
        display(a, n);
        quickSort(a, l, j, n);
        quickSort(a, j + 1, h, n);
    }
}

int main()
{
    int n, *arr;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(n + 1));
    arr[n + 1] = __INT32_MAX__;
    printf("Enter the elements -\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", (i + 1));
        scanf("%d", &arr[i]);
    }

    printf("Elements entered are - \n");
    display(arr, n);

    quickSort(arr, 0, n, n);

    printf("Sorted Elements are -\n");
    display(arr, n);
}
