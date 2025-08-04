#include<stdio.h>
void bubblesort(int a[],int n){
    int i,j,temp;
    int opcount=0;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            opcount++;
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\noperation count : %d",opcount);
}
int main(){
    int a[100],n,i,choice;

    printf("enter the number of elements: ");
    scanf("%d",&n);
    printf("enter %d elements : \n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("\nbefore sorting:");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    bubblesort(a,n);
    printf("\nafter sorting:");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
        return 0;
}
