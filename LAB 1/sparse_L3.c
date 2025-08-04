#include<stdio.h>

int isSparse(int arr[][10], int m, int n)
{
int counter = 0,i,j;
for (i = 0; i < m; i++)
for (j = 0; j < n;j++)
if (arr[i][j] == 0)
counter++;
return (counter > ((m * n) / 2));
}


int main(){
    int a[10][10],r1,c1,i,j;
printf("enter the number of rows & columns OF matrix A = \n");
scanf("%d %d",&r1,&c1);
printf("enter the first matrix elements=\n");
for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
{
scanf("%d",&a[i][j]);
}
}
if(isSparse(a,r1,c1)){
    printf("the matrix is sparse .\n");
}
else
    printf("the matrix is not sparse. ");
}
