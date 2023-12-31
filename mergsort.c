/*A library maintains details of N books where every book is assigned a unique ISBN. 
Develop a program in C to sort the books based on ISBN using merge sort technique. 
Determine the time required to sort. Repeat the experiment for different values of N
and plot a graph of the time taken versus N.*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void merge(int a[],int low,int mid,int high)
{
  int i,j,k,b[30000];
  i=low;j=mid+1;k=low;

  while(i<=mid && j<=high)
  {
    if(a[i]<=a[j])
      b[k++]=a[i++];
    else
      b[k++]=a[j++];
  }

  while(i<=mid) b[k++]=a[i++];
  while(j<=high)b[k++]=a[j++];


  for(k=low;k<=high;k++)
  a[k]=b[k];
}




void mergesort(int a[],int low,int high)
{
  int mid;
  if(low>=high)
  return;
  

  mid=floor((low+high)/2);
  mergesort(a,low,mid);
  mergesort(a,mid+1,high);
  merge(a,low,mid,high);
}




void main()
{
  int n,a[30000],k,r;

  clock_t start,end;
  double totaltime;
  printf("\nEnter The Number Of Books In Library");
  scanf("%d",&n);
  printf("Enter The ISBN ID Of Each Book");
  for(k=1;k<=n;k++)
  {
    r=(int)rand();
    a[k]=r;
  }


  start=clock();
  mergesort(a,1,n);
  end=clock();


  printf("\nISBN ID Of Books After Sorting\t");
  for(k=1;k<=n;k++)
  printf("%d\t",a[k]);
  totaltime=(double)(end-start)/CLOCKS_PER_SEC;
  printf("time taken is %f",totaltime);
}
