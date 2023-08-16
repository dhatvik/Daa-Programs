#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 126
int table[MAX];
char text[500];
char pattern[500];
int shifts=0;
int comp=0;

void shift(char pattern[])
{
    int i,j,m;
    m=strlen(pattern);
    for(i=0;i<MAX;i++)
    {
        table[i]=m;
    }
    for(j=0;j<m-1;j++)
    {
        table[pattern[j]]=m-1-j;
    }
}

int horspool(char pattern[],char text[])
{
    int k,m,n;
    n=strlen(text);
    m=strlen(pattern);
    int i=m-1;
    while(i<n)
    {
        k=0;
        while(k<=m-1 && pattern[m-1-k]==text[i-k])
        {
            k++;
            comp++;
        }
        if(k==m)
        {
            return i-m+1;
        }
        else
        {
            comp++;
            shifts++;
            i=i+table[text[i]];
        }
    }
    return -1;
}
void main()
{
    printf("Enter the text\n");
    gets(text);
    printf("Enter the pattern\n");
    gets(pattern);
    shift(pattern);
    int pos=horspool(pattern,text);
    if(pos>0)
    {
        printf("\n Found");
    }
    else 
    printf("\n not found");
    printf("\nnumber of comp is %d",comp);
    printf("\nNo of shifts is %d",shifts);
}