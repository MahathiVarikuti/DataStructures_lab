//tower of hanoi using recursion
#include<stdio.h>
void hanoi(int n , char x, char y , char a)
{
    if(n==1)
    {
        printf("move disk 1 from rod %c to rod %c\n",x,y);
        return ;
    }
    hanoi(n-1,x,a,y);
    printf("move disk %d from rod %c to rod %c\n",n,x,y);
    hanoi(n-1,a,y,x);
}
int main()
{
    int n =4;
    hanoi (n,'A','C','B');
    return 0 ;
}
