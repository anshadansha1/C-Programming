//PROGRAM 1_4 : SEARCH FOR ALL OCCURENCES OF AN ELEMENT IN AN INTEGER ARRAY
#include <stdio.h>
#define MAX_SIZE 100
int i,arr[MAX_SIZE];

void findOcc(const int arr[], int size, int element) {
    int found = 0;
    
    printf("Occurrences of %d at positions: ", element);
    
    for (i = 0; i < size; i++) {
        if (arr[i] == element) {
            printf("%d ", i);
            found = 1;
        }
    }
    
    if (!found) {
        printf("None");
    }
    
    printf("\n");
}

int main() {
    
    int size, element;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid array size.\n");
        
    }
    
    printf("\nEnter the elements of the array : \n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("\nEnter the element to search for : ");
    scanf("%d", &element);
    
    findOcc(arr, size, element);
    
    return 0;
}
