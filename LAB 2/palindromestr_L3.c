//To Check whether a given String is Palindrome or not using Recursion
int isPalindrome(char *inputString, int leftIndex, int rightIndex) {
    if(leftIndex >= rightIndex) return 1;
        if(inputString[leftIndex] == inputString[rightIndex])
            return isPalindrome(inputString, leftIndex + 1, rightIndex - 1);
    return 0;
}
int main(){
char str[10];
printf("enter the string : ");
gets(str);
if(isPalindrome(str,0,strlen(str)-1))
    printf("%s is a palindrome",str);
else
    printf("%s is not a palindrome ",str);
}
