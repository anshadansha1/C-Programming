//PROGRAM 1_5 : SORT THE ARRAY ELEMENTS IN  ASCENDING ORDER(min three functions:read,disp,sort)
#include <stdio.h>
int i,j;
//Read array elements
void read(int arr[], int size) {
	
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

//Display array elements
void disp(int arr[], int size) {
    printf("Array elements: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//Sort array elements in asc order - Bubble Sort
void sort(int arr[], int size) {
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    read(arr, size);

    printf("Before sorting:\n");
    disp(arr, size);

    sort(arr, size);

    printf("After sorting in ascending order:\n");
    disp(arr, size);

    return 0;
}
