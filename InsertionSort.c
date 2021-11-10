/*
Jayneel M Shah
18:44,10-11-21
Topic - Insertion Sort
Worst Case Time Complexity - O(n^2)  --> List is sorted in descending order
Best Case Time Complexity - O(n)  --> List is sorted in ascending order
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

void insertionSort(int a[], int n)
{
    int i, j, x;
    // loop for number of passes, it starts from 1 as the first element of the array is already sorted
    for (i = 1; i < n; i++)
    {
        j = i - 1; // position of the previous element
        x = a[i];  // current element (which is inserted)
        while (j > -1 && a[j] > x)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;

        printf("Elements after pass %d - ", i);
        display(a, n);
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

    insertionSort(arr, n);

    printf("Sorted Elements are -\n");
    display(arr, n);
}
