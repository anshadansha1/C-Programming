//PROGRAM 1_3 : USE A MENU-DRIVEN PROGRAM TO INSERT, SEARCH, DELETE AND SORT ELEMENTS IN AN ARRAY USING FUNCTIONS (USE ONLY LOCAL VARIABLES) 
#include <stdio.h>
#define MAX_SIZE 100

void insertEl(int arr[], int *size) {
	int trv=0,i,element;
	printf("\nEnter how much elements to be inserted : ");
	scanf("%d",&trv);
	for(i=0;i<trv;i++)
	{
    	if (*size < MAX_SIZE) {
    		printf("Enter element to insert: ");
            scanf("%d", &element);
        	arr[(*size)++] = element;
    	} else {		
        	printf("Array is full. Cannot insert more elements.\n");
    	}
    }
}

void searchEl(const int arr[], int size, int element) {
    int found = 0,i;
    for (i = 0; i < size; i++) {
        if (arr[i] == element) {
            printf("Element %d found at index %d.\n", element, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the array.\n", element);
    }
}

void deleteEl(int arr[], int *size, int element) {
    int found = 0,i,j;
    for (i = 0; i < *size; i++) {
        if (arr[i] == element) {
            found = 1;
            for (j = i; j < *size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*size)--;
            printf("Element %d deleted successfully.\n", element);
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the array. Deletion failed.\n", element);
    }
}
void sortArr(int arr[], int size) {
	int i,j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted successfully.\n");
}
void displayArr(int arr[],int size){
	int i;
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


int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element;
    
    do {
        printf("\n----Menu----\n1. Insert element\n2. Search element\n3. Delete element\n4. Sort array\n5. Display.\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                insertEl(arr, &size);
                break;
            case 2:
                printf("Enter element to search: ");
                scanf("%d", &element);
                searchEl(arr, size, element);
                break;
            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &element);
                deleteEl(arr, &size, element);
                break;
            case 4:
                sortArr(arr, size);
                break;
            case 5:
            	displayArr(arr, size);
            	break;
                
            case 6:
            	printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);
    
    return 0;
}
