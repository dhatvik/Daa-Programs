#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void quicksort(int a[20000],int low,int high)
{  
    int i,j,pivot,temp;
    if(low<high)
    {
        i=low;
        j=high;
        pivot=low;
        while(i<j)
        {
            while(a[i]<=a[pivot] && i<high)
                i++;
            while(a[j]>a[pivot])
                j--;
            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp=a[j];
        a[j]=a[pivot];
        a[pivot]=temp;
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}
void main()
{
    int n;
    int a[20000];
    clock_t start,end;
    printf("Enter Number of elements\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        a[i]=(int)rand();
    }
    start=clock();
    quicksort(a,0,n-1);
    end=clock();

    printf("\nAfter sorting");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    double time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nTime Taken is %f",time);
}