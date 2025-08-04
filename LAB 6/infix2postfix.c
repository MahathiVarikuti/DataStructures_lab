infix to postfix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
 typedef struct {
 char arr[MAX];
 int top ;
 } Stack ;

 void initstack (Stack * s){
 s->top = -1 ;
 }

 int isfull(Stack *s){
 return (s->top==MAX-1);
 }
 int isempty(Stack *s){
    return (s->top == - 1);
 }
void push(Stack * s , int value){
 if(isfull(&s))
    return ;
 s->arr[++(s->top)] = value ;
 }
 int pop(Stack *s){
    if(isempty(&s))
   return -1;
 return  s->arr[(s->top)--] ;
 }
 char peek(Stack *s){
    return s->arr[s->top];
 }
 int isoperand(char ch)
 {
    return isalnum(ch);
 }
char precedence(char ch){
switch(ch){
case '+':
case '-':
    return 1;
case '*':
case '/':
    return 2;
case '^':
    return 3;
}
return 0;
}
void infixToPostfix(char *exp){
    Stack s;
    initstack(&s);
    int i=0,j=0;
    char postfix[MAX];
while(exp[i]){
    if(isoperand(exp[i]))
        postfix[j++] = exp[i];
    else if (exp[i]== '(')
                push(&s, exp[i]);
    else if (exp[i] == ')')
    while (!isempty(&s) && peek(&s)!= '('){
             postfix[j++] = pop(&s ) ;
           }
    else {
        while( !isempty(&s) && precedence(peek(&s))>=precedence(exp[i]) )
    {
        postfix[j++]= pop(&s);
    }
    push(&s,exp[i]);}
      i++;
}
while(!isempty(&s)){
    postfix[j++]= pop(&s);
}
//postfix[j] = '\0'; // null terminate the postfix expression
printf("%s\n",postfix);
}
int main(){
char expr[MAX];
   printf("Enter infix expression\n");
    scanf("%s", expr);
    printf("postfix:\n");
    infixToPostfix(expr);

}
