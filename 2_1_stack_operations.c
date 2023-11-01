//PROGRAM 2_1: IMPLEMENT STACK OPERATIONS USING ARRAY
#include <stdio.h>
#define MAX_SIZE 10

int stack[MAX_SIZE];
int top=-1;

int menu()
{
	int choice;
	printf("\n_________Stack Operations_________\n");
	printf("1.PUSH\n2.POP\n3.PEEK\n4.Exit\n");
	printf("\nEnter your choice : ");
	scanf("%d",&choice);
	return choice;
}
void push(int val)
{
	if(top==MAX_SIZE-1)
	{
		printf("\nStack Overflow.Cannot PUSH %d \n",val);
	}
	else
	{
		stack[++top]=val;
		printf("\n%d is pushed to stack \n",val);
	}
	
}
void pop()
{
	if(top== -1)
	{
		printf("\nStack Underflow.Cannot perform POP\n");
	}
	else
	{
		printf("\n%d Popped from stack.\n",stack[top--]);
	}
}
void peek()
{
	if(top== -1)
	{
		printf("\nStack Underflow.Cannot perform PEEK\n");
	}
	else
	{
		printf("\nTop of stack is : %d\n",stack[top]);
	}
}

int main()
{
	int choice,val;
	for(choice=menu();choice!=4;choice=menu())
	{
			switch(choice)
		{
			case 1:
				printf("\nEnter the value to PUSH : ");
				scanf("%d",&val);
				push(val);
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				printf("\nExiting......\n");
				break;
			default:
				printf("\nInvalid choice.please enter valid choice");
			
		}
	}

	return 0;
}

