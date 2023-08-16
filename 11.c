#include<stdio.h>
int count=0;
int noattack(char board[10][10],int col,int row,int n)
{
    for(int x=0;x<n;x++)
    {
        if(board[x][col]=='Q')
        return 0;
    }
    for(int y=0;y<n;y++)
    {
        if(board[row][y]=='Q')
        return 0;
    }
    int x=row;
    int y=col;
    while(x>=0 && y>=0)
    {
        if(board[x][y]=='Q')
        return 0;
            
        x--;
        y--;
    }
    int x1=row;
    int y1=col;
    while(x1>=0 && y1<n)
    {
        if(board[x1][y1]=='Q')
        return 0;
            
        x1--;
        y1++;
    }
    return 1;
}

int solve(char board[10][10],int n,int row)
{
    if(row==n)
    {
        count++;
        printf("\nSolution %d is\n ",count);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%c\t",board[i][j]);
            }
            printf("\n");
        }
        return 0;
    }

    for(int col=0;col<n;col++)
    {
        if(noattack(board,col,row,n))
        {
            board[row][col]='Q';
            int canPlaceQueen=solve(board,n,row+1);
            if(canPlaceQueen==1)
            return 1;

            board[row][col]='-';
        }
    }
    return 0;
}
void main()
{
    int n;
    printf("\nEnter number of Queens");
    scanf("%d",&n);
    char board[10][10];
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    {
    board[i][j]='-';
    }
    }
    solve(board,n,0);
}