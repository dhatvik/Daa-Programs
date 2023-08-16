/*Consider a list of ‘n’ files numbered using ID’s. Write a C program to sort files based
on its ID using Quick sort. Determine the time required sort the files. Plot a graph of
number of IDs versus time taken.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int a[10000], int low, int high)
{
    int i,j,pivot,temp;
    if (low < high)

    {
        pivot = low;
        i = low;
        j = high;
        while (i < j)
        {
            while (a[i] <= a[pivot] && i < high)
                i++;
            while (a[j] > a[pivot])
                j--;
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            } // End of inner if
        }     // End of while
        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;
        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    } // End of outer if
} // End of quicksort

void main()
{
    double total_time;
    clock_t start, end;
    int a[10000], i, size;
    start = clock();
    printf("Enter the size of the Array:\n");
    scanf("%d", &size);

    printf("Elements of the array before sorting are :\n");
    srand(time(0));
    for (i = 0; i < size; i++)
    {
        int r = rand();
        a[i] = r;
        printf("%d\t", a[i]);
    } // End of for
    quicksort(a, 0, size - 1);

    printf("Elements of the array after sorting are :\n");
    for (i = 0; i < size; i++)
    {
        printf("%d\t", a[i]);
    } // End of for

    end = clock();
    total_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Total time taken is %lf", total_time);
} // End of main
