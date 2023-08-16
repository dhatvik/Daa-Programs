// #include<stdio.h>

// int weight[20],profit[20],selected[20]={0},table[20][20],capacity;
// int max(int a,int b){
//     if(a>b){
//         return a;
//     }
//     return b;
// }

// void knapsack(int n){

//     for(int i=0;i<=capacity;i++){
//         table[0][i] = 0;
//     }
//     for(int i=0;i<=n;i++){
//         table[i][0] = 0;
//     }

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=capacity;j++){
//             if(weight[i] <=j){
//                 table[i][j] = max(table[i-1][j],table[i-1][j-weight[i]]+profit[i]);
//             }
//             else{
//                 table[i][j] = table[i-1][j];
//             }
//         }
//     }
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=capacity;j++){
//             printf("%d ",table[i][j]);
//         }
//         printf("\n");
//     }

//     //The above code will fill up the table.
//     //Now we have to identify the elements.
//     int netCap = capacity;
//     for(int i=n;i>=1 && netCap !=0;i--){
//         if(table[i][netCap] != table[i-1][netCap]){
//             selected[i] = 1;
//             netCap = netCap - weight[i];
//         }
//         else{
//             selected[i] = 0;
//         }
//     }
//     int maxProfit = 0;
//     printf("\nThe items selectes are:\t");
//     for(int i=1;i<=n;i++){
//         if(selected[i]){
//             printf("%d ",i);
//             maxProfit += profit[i];
//         }
//     }
//     printf("\nThe maximum profit is %d\n",maxProfit);
// }

// void main(){

//     int n;
//     printf("\nEnter the number of objects:\t");
//     scanf("%d",&n);

//     printf("Enter the profit and weight of each of the following item:\t");
//     for(int i=1;i<=n;i++){
//         scanf("%d",&profit[i]);
//         scanf("%d",&weight[i]);
//     }
//     printf("\nEnter the capacity of the knapsack:\t");
//     scanf("%d",&capacity);
    
//     knapsack(n);
// }

#include<stdio.h>
#include<stdlib.h>
int w[10],p[10],v[10][10],i,j,m,n;
int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}
void knapsack()
{
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                v[i][j] = 0;
            else if(j-w[i]<0)
                v[i][j] = v[i-1][j];
            else
                v[i][j] = max(v[i-1][j], p[i]+v[i-1][j-w[i]]);
        }
    }
    printf("The optimum solution is:\n");
    printf("tabular column is :\n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            printf("%d\t",v[i][j]);
        }
        printf("\n");
    }
}
void element()
{
    int x[n+1];
    int maxprofit=0;
    for(i=0;i<=n;i++)
    {
        x[i] = 0;
    }
    i = n;
    j = m;
    while(i>0 && j>0)
    {
        if(v[i][j]!=v[i-1][j])
        {
            x[i] = 1;
            j = j-w[i];
        }
        i--;
    }
    for(i=1;i<=n;i++)
    {
        if(x[i]==1)
        {
        maxprofit = maxprofit+p[i];
        printf("%d\t",i);
        }
    }
    printf("\nmaximum profit is %d",maxprofit);
}

void main()
{
    printf("ENter the capacity of the knapsack:\n");
    scanf("%d",&m);
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    printf("Enter the weights of the elements:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
    }
    printf("Enter the profits of each element:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    knapsack();
    printf("\n");
    element();
}

