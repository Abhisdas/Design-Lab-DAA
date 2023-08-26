#include <stdio.h>

int comparisons = 0;

int partition(int elements[], int start, int end) {
    int i = start;
    int pivot = elements[start];
    
    for (int j = i+1; j <= end; j++) {
        comparisons++;
        if (elements[j] <= pivot) {
            i++;
            int temp = elements[i];
            elements[i] = elements[j];
            elements[j] = temp;
        }
    }
    
    int temp = elements[i];
    elements[i] = elements[start];
    elements[start] = temp;
    return i;
}

void quickSort(int elements[], int start, int end) {
    if (start < end) {
        int mid = partition(elements, start, end);
        quickSort(elements, start, mid-1);
        quickSort(elements, mid+1, end);
    }
}

int main() {
    int num;
    printf("Enter size of array: ");
    scanf("%d", &num);
    
    int elements[num];
    printf("Enter elements of the array: ");
    for (int i = 0; i < num; i++) {
        scanf("%d", &elements[i]);
    }
    
    int start = 0;
    int end = num - 1;

    quickSort(elements, start, end);
    
    printf("Sorted array is: ");
    for (int i = 0; i <= end; i++) {
        
        printf("%d, ", elements[i]);
    }
    printf("\nNumber of comparisons: %d\n", comparisons);
    
    return 0;
}
