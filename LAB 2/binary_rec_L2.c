//binary search using recursion
#include<stdio.h>
int binary(int arr[],int left,int right , int target)
{
    if(right>=left)
    {
        int mid=left+((right-left)/2);
        if (arr[mid]==target)
            return mid;
        if (arr[mid]>target)
            return binary(arr,left,mid-1,target);
        return binary(arr,mid+1,right,target);
    }
    return -1;
}
int main()
{
    int arr[50],i,n;
    printf("enter the number of elements in an array : ");
    scanf("%d",&n);
    printf("\nenter the elements of an array:\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int target;
    printf("enter the target element : ");
    scanf("%d",&target);
    int result = binary(arr,0,n-1,target);
    if(result == -1)
        printf("element not present.");
    else
        printf("element found at index %d",result);
    return 0 ;
}
