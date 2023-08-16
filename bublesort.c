/* The goods packages in a supermarket are assigned an integer label. Write a C 
program to sort the set of goods packages based on label identifier using Bubble 
Sort/Selection Sort and determine the time required to sort. Plot a graph of number 
of label identifiers versus time taken. */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
 {
    int n;
    int temp;
    clock_t start,end;
    printf("Enter number of goods packages in supermarket");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        {
              arr[i]=(int)rand();
        }
    printf("goods packages with integer lable before sorting");
    for(int i=0;i<n;i++)
        {
            printf("%d\n",arr[i]);
        }
    start=clock();
        {
    for(int i=0;i<n;i++)
        {
          for(int j=0;j<n-1-i;j++)
             {
                if(arr[j]>arr[j+1])
                  {
                      temp=arr[j+1];
                      arr[j+1]=arr[j];
                      arr[j]=temp;
                  }
             }
        }
        }
        end=clock();
        printf("the goods packages with integer lable after sorting\n");
        for(int i=0;i<n;i++)
        {
             printf("%d\t",arr[i]);
        }
    double time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Time Taken =%f",time);
  }