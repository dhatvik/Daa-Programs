#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int h[50];
void heapify(int h[],int n)
{
    int i,j,k,v,heap;
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=h[k];
        heap=0;
        while(!(heap) && 2*k<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(h[j]<h[j+1])
                j++;
            }
            if(v>=h[j])
            {
                heap=1;
            }
            else
            {
                h[k]=h[j];
                k=j;
            }
            h[k]=v;

        }
    }
}
void main()
{
    int n,i;
    clock_t start,end;
    printf("enter Number of elements\t");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
    }
    printf("Bef sorting the array is\n ");
    for(i=1;i<=n;i++)
    printf("%d\t",h[i]);

    start=clock();
    heapify(h,n);
    
    int temp,size;
    for(int i=n;i>=1;i--)
    {
        temp=h[i];
        h[i]=h[1];
        h[1]=temp;
        size=i-1;
        heapify(h,size);
    }
    end=clock();
    double time=(double)(end-start)/CLOCKS_PER_SEC;
    
    printf("After sorting\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",h[i]);
    }
    printf("Time taken is %d",time);
}



