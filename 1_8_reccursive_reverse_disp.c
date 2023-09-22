//PROGRAM 1_8: DISPALY ARRAY ELEMENTS IN REVERSE ORDER USING A RECURSIVE FUNCTION
#include <stdio.h>

void dispRevRec(int arr[], int size, int index) {
    if (index < 0) {
        return;
    }
    
    printf("%d ", arr[index]); 
    dispRevRec(arr, size, index - 1); // Recursively calling for the previous index
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
    
    printf("Array elements in reverse order: ");
    dispRevRec(arr, size, size - 1); // Start displaying from the last index
    
    return 0;
}
