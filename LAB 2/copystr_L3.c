//To copy one string to another using Recursion.
#include<stdio.h>
#include<string.h>
int copy(char str1[],char str2[],int index){
    str2[index]=str1[index];
    if(str1[index]=='\0')
    return ;
    copy(str1,str2,index+1);
}
int main(){
char str1[10],str2[10];
printf("enter the string : ");
gets(str1);
copy(str1,str2,0);
printf("copied string in str2 is : %s",str2);
return 0;
}
