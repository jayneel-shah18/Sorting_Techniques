/*
Jayneel M Shah
11:32, 09-06-22
Topic - Shell Sort
Time Complexity can vary depending on selection of gaps.
O(nlogn) is general best time complexity.
O(n^(3/2)) when gaps selected are prime numbers.
*/
#include <stdio.h>
#include <stdlib.h>

int k = 1;

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void shellSort(int a[], int n)
{
    int i, j, gap, temp;

    for (gap = n / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = a[i];
            j = i - gap;
            while (j >= 0 && a[j] > temp)
            {
                a[j + gap] = a[j];
                j = j - gap;
            }
            a[j + gap] = temp;
        }

        printf("Pass %d - ",k);
        display(a, n);
        k++;
    }
}

int main()
{
    int n, *arr;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements -\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", (i + 1));
        scanf("%d", &arr[i]);
    }

    printf("Elements entered are - ");
    display(arr, n);

    shellSort(arr, n);

    printf("Sorted Elements are - ");
    display(arr, n);
}
