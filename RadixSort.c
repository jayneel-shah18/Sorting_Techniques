/*
Jayneel M Shah
11:30, 09-06-22
Topic - Radix Sort
Time Complexity - O(d * (n + b))
d is the number of digits in highest number
b is the bin size
Number of passes = Number of digits of highest number
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

int getMax(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

void radixSort(int a[], int n)
{
    int bins[10][10], binCount[10];
    int i, j, k, noOfPasses = 0, largest, pass, r, d = 1;

    largest = getMax(a, n);

    while (largest > 0)
    {
        noOfPasses++;
        largest /= 10;
    }

    for (pass = 0; pass < noOfPasses; pass++)
    {
        for (i = 0; i < 10; i++)
        {
            binCount[i] = 0;
        }

        for (i = 0; i < n; i++)
        {
            r = (a[i] / d) % 10;
            bins[r][binCount[r]] = a[i];
            binCount[r] += 1;
        }

        i = 0;
        for (k = 0; k < 10; k++)
        {
            for (j = 0; j < binCount[k]; j++)
            {
                a[i] = bins[k][j];
                i++;
            }
        }

        d *= 10;
        printf("After Pass %d - ", pass + 1);
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

    printf("Elements entered are - ");
    display(arr, n);

    radixSort(arr, n);

    printf("Sorted Elements are -");
    display(arr, n);
}
