/*
Jayneel M Shah
11:25, 09-06-22
Topic - Merge Sort
Time Complexity - O(nlogn)
Space Complexity - 2n + logn
*/
#include <stdio.h>
#include <stdlib.h>

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void merge(int a[], int l, int mid, int h)
{
    int i, j, k, b[100];
    i = l, j = mid + 1, k = l;

    while (i <= mid && j <= h)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }

    for (; i <= mid; i++)
    {
        b[k++] = a[i];
    }

    for (; j <= h; j++)
    {
        b[k++] = a[j];
    }

    for (int i = l; i <= h; i++)
    {
        a[i] = b[i];
    }
}

void mergeSort(int a[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;

        mergeSort(a, l, mid);
        mergeSort(a, (mid + 1), h);
        merge(a, l, mid, h);
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

    mergeSort(arr, 0, n - 1);

    printf("Sorted Elements are -\n");
    display(arr, n);
}
