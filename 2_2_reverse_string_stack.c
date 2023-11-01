//PROGRAM 2_2:REVERSE A STRING USING STACK
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

char stack[MAX_SIZE],top=-1;
char input[MAX_SIZE];

void push(char input[20])
{
	int i,len=strlen(input);
	
	for(i=0;i<len;i++)
	{
		top++;
		stack[top]=input[i];
	}
	
}
void pop(){
	printf("\nReversed string is to reverse it : ");
	while(top>=-1)
	{
		printf("%c",stack[top]);
		top--;
	}
}
void main(){
	printf("\nEnter the string : ");
	scanf("%s",input);
	push(input);
	pop();
}



//#include <stdio.h>
//#include <string.h>
//#define MAX_SIZE 100
//
//int top = -1,i;
//char stack[MAX_SIZE];
//
//void push(char c) {
//    if (top >= MAX_SIZE - 1) {
//        printf("Stack overflow\n");
//    } else {
//        stack[++top] = c;
//    }
//}
//
//
//char pop() {
//    if (top < 0) {
//        printf("Stack underflow\n");
//        return '\0';
//    } else {
//        return stack[top--];
//    }
//}
//// Reverse
//void reverseStr(char *input) {
//    int length = strlen(input);
//
//    // Pushing each character into stack
//    for (i = 0; i < length; i++) {
//        push(input[i]);
//    }
//
//    // Pop and print characters from the stack to reverse the string
//    printf("Reversed string is : ");
//    while (top >= 0) {
//        printf("%c", pop());
//    }
//    printf("\n");
//}
//
//int main() {
//    char input[MAX_SIZE];
//    printf("Enter a string: ");
//    scanf("%s", input);
//
//    reverseStr(input);
//
//    return 0;
//}
