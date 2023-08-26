#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>

int unique(int a[], int n, int result[]) {
    int idx = 0;
    
    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        
        for (int j = 0; j < idx; j++) {
            if (a[i] == result[j]) {
                isDuplicate = true;
                break;
            }
        }
        
        if (!isDuplicate) {
            result[idx] = a[i];
            idx++;
        }
    }
    
    return idx;
}

int main() {
    int num_sizes;
    printf("Enter the number of sizes: ");
    scanf("%d", &num_sizes);
    
    int sizes[num_sizes];
    for (int i = 0; i < num_sizes; i++) {
        printf("Enter size for array %d: ", i + 1);
        scanf("%d", &sizes[i]);
    }
    
    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        int input_array[size];
        
        for (int j = 0; j < size; j++) {
            // printf("Enter element %d of array %d: ", j + 1, i + 1);
            // scanf("%d", &input_array[j]);

            input_array[j]=rand();
        }
        for (int i = 0; i < size; i++)
        {
            printf("%d ",input_array[i]);
        }
        
        int unique_array[size];  // Assuming worst case where all elements are unique
        int num_unique = unique(input_array, size, unique_array);
        int num_operations = size * size;  // Assuming worst case where all elements need to be compared
        
        double c1 = (double)num_operations / (size * size);
        
        printf("\n\nSize of problem (|a|): %d\n", size);
        printf("Observed number of basic operations: %d\n", num_operations);
        printf("Estimated parameter c1: %lf\n\n", c1);
    }
    
    return 0;
}
