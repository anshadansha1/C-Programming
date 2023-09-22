//PROGRAM 1_7: DISPLAY ARRAY ELEMENTS IN THE SAME ORDER USING A RECURSIVE FUNCTION
#include <stdio.h>

void dispRecc(int arr[], int size, int index) {
    if (index == size) {
        return;
    }
    
    printf("%d ", arr[index]); 
    dispRecc(arr, size, index + 1); // Recursively calling  for the next index
}

int main() {
    int size,i;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    
    printf("Enter array elements:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Array elements in the same order: ");
    dispRecc(arr, size, 0); 
    
    return 0;
}
