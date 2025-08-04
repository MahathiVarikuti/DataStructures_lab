#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int isEmpty(int top, int stack_arr[]);
void push(int x, int *top, int stack_arr[]);
int pop(int *top, int stack_arr[]);
void DecToBin(int num);

int main()
{
        int num;
        printf("Enter an integer : ");
        scanf("%d",&num);
        printf("Binary Equivalent is : ");
        DecToBin(num);

        return 0;

}

void DecToBin(int num)#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char s[]) {
    int length = strlen(s);
    int mid = length / 2;
    int i;
    char stack[mid];

    for (i = 0; i < mid; i++) {
        stack[i] = s[i];
    }

    if (length % 2 != 0) {
        i++;
    }

    while (s[i] != '\0') {
        char ele = stack[--i];
        if (ele != s[i]) {
            return false;
        }
        i++;
    }

    return true;
}

int main() {
    char s[] = "madam";
    if (isPalindrome(s)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}

{
        int stack[MAX], top=-1, rem;
        while(num!=0)
        {
                rem = num%2;
                push(rem, &top, stack);
                num/=2;
        }
        while(top!=-1)
                printf("%d", pop(&top, stack));
        printf("\n");
}


void push(int x, int *top, int stack_arr[])
{
        if(*top == (MAX-1))
                printf("Stack Overflow\n");
        else
        {
                *top=*top+1;
                stack_arr[*top] = x;
        }
}/*End of push()*/

int pop(int *top, int stack_arr[])
{
        int x;
        if(*top == -1)
        {
                printf("Stack Underflow\n");
                exit(1);
        }
        else
        {
                x = stack_arr[*top];
                *top=*top-1;
        }
        return x;
}
