#include <stdio.h>
int comparisons = 0;

int partition(int arr[], int p, int q) {
    int i = p;
    
    int pivot = arr[p];
    for (int j = i+1; j <= q; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int temp = arr[i];
    arr[i] = arr[p];
    arr[p] = temp;
    return i;
}

//7 9 2 11 19 17 12 5 7 12
void quickSort(int arr[], int p, int q) {
    if (p < q) {
        
        int mid = partition(arr, p, q);
        
        
        quickSort(arr, p, mid-1);
        
        
        quickSort(arr, mid+1, q);
    }
}

int main() {
    int arr[100];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int p = 0;
    int q = n-1;

    quickSort(arr, p, q);
    
    printf("Sorted array after applying the quickSort is: ");
    for (int i = 0; i <= q; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\nNumber of comparisons: %d\n", comparisons);
return 0;
}
