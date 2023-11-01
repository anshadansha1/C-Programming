//PROGRAM 7_4 :Declare a structure for Books having author_name and book_name. Create an array of books using a pointer variable. Provide functions for reading n books and displaying the same using pointers.
#include<stdio.h>
#include<malloc.h>
struct books{
	char author_name[30];
	char book_name[50];
};

void read();
void disp();

int main(){
	int n;
	struct books *p;
	printf("\nEnter the number of books : ");
	scanf("%d",&n);
	p=(struct books *)calloc(n,sizeof(struct books));
	read(p,n);
	disp(p,n);
	return 0;
}

void read(struct books *p,int n){
	int i;
	printf("\n----------Enter the details of books------------");
	for(i=0;i<n;i++){
		printf("\n\n\nBook %d ------------>",i+1);
		printf("\nEnter name of book : ");
		scanf(" %[^\n]",(p + i)->book_name);//[^\n] : Reads strings with whitespaces
		printf("\nEnter the name of author : ");
		scanf(" %[^\n]",(p + i)->author_name);
		
	}
}

void disp(struct books *p,int n){
	int i;
	printf("\n---------------BOOK DETAILS----------------");
	for(i=0;i<n;i++){
		printf("\n\n\nBook %d ------------>",i+1);
		printf("\nName of Book : %s\n",(p+i)->book_name);
		printf("\nName of author : %s\n",(p+i)->author_name);
	}
}