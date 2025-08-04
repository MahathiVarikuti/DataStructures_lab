//To implement selection
#include<stdio.h>
void selection(int list1[],int i,int j, int Size ,int flag)
{
    int temp;
    if(i<Size - 1){
        if(flag)
        j=i+1;
    if(j<Size){
        if(list1[i]>list1[j])
    {
        temp = list1[i];
        list1[i]=list1[j];
        list1[j]=temp;
    }
    selection(list1,i,j+1,Size,0);}
    selection(list1,i+1,0,Size,1);}
}
int main()
{
    int list1[30], size1, temp, i, j;
    printf("Enter the size of the list: ");
    scanf("%d", &size1);
    printf("Enter the elements in list:\n");
    for (i = 0; i < size1; i++)
    {
        scanf("%d", &list1[i]);
    }
    selection(list1, 0, 0, size1, 1);
    printf("The sorted list in ascending order is\n");
    for (i = 0; i < size1; i++)
    {
        printf("%d  ", list1[i]);
    }

    return 0;
}
