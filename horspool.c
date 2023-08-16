#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX 126
int table[MAX];
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
    int k;
    int m=strlen(pattern);
    int n=strlen(text);
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
        return i-m+1;
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
    char text[500],pattern[500];
    printf("Enter the text ");
    // scanf("%s",text);
    gets(text);
    printf("Enter the pattern");
    // scanf("%s",pattern);
    gets(pattern);
    shift(pattern);
    int pos =horspool(pattern,text);
    if(pos>=0)
    printf("\nFound");
    else
    printf("Not Found");
    printf("\nshifts\t %d",shifts);
    printf("\nNo of comparisions %d\t",comp);
}