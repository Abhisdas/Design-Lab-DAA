#include <stdio.h>

int main() {
    int size, comparisons = 0;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    
    printf("Enter elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    
    for (int i = 1; i < size; i++) {
        int current = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
        }
        
        arr[j + 1] = current;
    }
    
    printf("Sorted array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n%d comparisons\n", comparisons);
    
    return 0;
}
