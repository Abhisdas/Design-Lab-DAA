#include <stdio.h>
#include <stdlib.h> 

int recursiveMin(int a[], int n) {
    if (n == 1) {
        return a[0];
    } else {
        int minRest = recursiveMin(a, n - 1);
        return (a[n - 1] < minRest) ? a[n - 1] : minRest;
    }
}

int countRecursionDepth(int a[], int n) {
    int depth = 0;

    int recursiveMinWithDepth(int a[], int n) {
        if (n == 1) {
            return a[0];
        } else {
            depth++;
            int minRest = recursiveMinWithDepth(a, n - 1);
            return (a[n - 1] < minRest) ? a[n - 1] : minRest;
        }
    }

    recursiveMinWithDepth(a, n);
    return depth;
}

int main() {
    int num_sizes;
    printf("Enter the number of sizes: ");
    scanf("%d", &num_sizes);

    for (int i = 0; i < num_sizes; i++) {
        int size;
        printf("Enter size for array %d: ", i + 1);
        scanf("%d", &size);

        if (size <= 0) {
            printf("Invalid size. Please enter a positive integer.\n");
            i--; 
            continue;
        }

        int* input_array = (int*)malloc(size * sizeof(int));
        if (input_array == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        for (int j = 0; j < size; j++) {
            input_array[j] = size - j;
        }

        int depth = countRecursionDepth(input_array, size);
        double c1 = (size > 0) ? (double)depth / size : 0;

        printf("\nSize of problem (|a|): %d\n", size);
        printf("Observed depth of recursion: %d\n", depth);
        printf("Estimated parameter c1: %lf\n\n", c1);

        free(input_array); 
    }

    return 0;
}
