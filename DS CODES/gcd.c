#include<stdio.h>

int gcd_2(int m , int n){
int i, min;
int opcount=0;
min = (m<n)? m:n;
for(i=min;i>=1;i++){
    opcount++;
    if(m%i==0 && n%i==0){
            printf("operation count = %d\n",opcount);
        return i;
}
}
return 0;
}

int main(){
int a,b,gcd;
printf("enter two positive numbers:\n");
scanf("%d %d",&a,&b);
if(a<=0 || b<=0){
    printf("enter valid positive numbers.\n");
return 1;
}
gcd=gcd_2(a,b);
printf("GCD of %d and %d = %d\n",a,b,gcd);
return 0;
}
