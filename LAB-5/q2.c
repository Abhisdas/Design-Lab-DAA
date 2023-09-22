#include <stdio.h>

void merge(int arr[], int left, int middle, int right, long long *comparisons) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1) {
        arr[k++] = leftArr[i++];
    }

    while (j < n2) {
        arr[k++] = rightArr[j++];
    }
}

void mergeSort(int arr[], int left, int right, long long *comparisons) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle, comparisons);
        mergeSort(arr, middle + 1, right, comparisons);

        merge(arr, left, middle, right, comparisons);
    }
}

int main() {
    int size;
    long long comparisons = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, size - 1, &comparisons);

    printf("Sorted array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n%lld comparisons\n", comparisons);

    return 0;
}
