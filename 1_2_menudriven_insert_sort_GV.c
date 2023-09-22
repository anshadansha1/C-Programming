//PROGRAM 1_2 : USE A MENU-DRIVEN PROGRAM TO INSERT, SEARCH, DELETE AND SORT ELEMENTS IN AN ARRAY USING FUNCTIONS (USE GLOBAL VARIABLES) 
#include <stdio.h>
#define MAX_SIZE 100

//Global variables
int arr[MAX_SIZE];
int size=0,i=0,j=0;

//Declaring Functions
void menu();
void insertEl();
void searchEl();
void deleteEl();
void sortArr();
void displayArr();

int main(){
	int choice;
	do{
		menu();
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				insertEl();
				break;
			case 2:
				searchEl();
				break;
			case 3:
				deleteEl();
				break;
			case 4:
				sortArr();
				break;
			case 5:
				displayArr();
				break;
			case 6:
				printf("\nExiting program...\n");
				break;
			default:
				printf("inavlid input\n");
				break;
				
				
		}
		
	}while(choice!=6);
}

void menu(){
	printf("\n----MENU----\n");
	printf("1.Insert.\n2.Search.\n3.Delete.\n4.Sort.\n5.Display.\n6.Exit.\n");
}
void insertEl(){
	int trv=0;
	printf("\nEnter how much elements to be inserted : ");
	scanf("%d",&trv);
	for(i=0;i<trv;i++)
	{
		if(size >= MAX_SIZE)
		{
			printf("Array is full.Cannot insert more elements\n");
		}
		else{
			printf("Enter the element to be inserted : ");
			scanf("%d",&arr[size]);
			size++;
			printf("Element inserted successfully.\n");
		}
	}
	
}

void searchEl(){
	int src,found=0;
	if(size==0){
		printf("Array is empty.Cannot perform search.\n");
	}
	printf("Enter the element to search : ");
	scanf("%d",&src);
	
	for(i=0;i<size;i++)
	{
		if(arr[i]==src)
		{
			printf("Element %d found at index %d.\n",src,i);
			found=1;
		}
	}
	if(!found){
		printf("Element not found .\n");
	}
}

void deleteEl(){
	int del,found=0;
	
	if(size==0)
	{
		printf("Array is empty.Cannot perform deleteion");
		
	}
	printf("Enter the element to be deleted : ");
	scanf("%d",&del);
	
	for(i=0;i<size;i++){
		if(arr[i]==del){
			found=1;
			break;
		}
	}
	if(found){
		//moving elements 
		for(j=i;i<size-1;j++){
			arr[j]=arr[j+1];
		}size--;
		printf("Element %d deleted.\n",del);
	
	}else{
		printf("Element not found in array.Deletion failed\n");
	}	
}

void sortArr(){
	int temp;
	
	for(i=0;i<size-1;i++)
	{
		for(j=i+1;j<size;j++){
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	printf("Array sorted in ascending order .\n");
}

void displayArr(){
	if(size==0)
	{
		printf("Array is empty.\n");
		
	}
	printf("Array elements :- \n");
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}



