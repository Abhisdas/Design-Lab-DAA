#include <stdio.h>

int findFirstOccurrence(int elements[], int size, int target) {
    int left = 0, right = size - 1;
    int index = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (elements[mid] == target) {
            index = mid;
            right = mid - 1;
        }
        else if (elements[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return index;
}

int main() {
    int num;
    printf("Enter the number of elements in an array: ");
    scanf("%d", &num);
    int elements[num];
    
    printf("Enter the array elements: ");
    for (int i = 0; i < num; i++) {
        scanf("%d", &elements[i]);
    }

    int target;
    printf("Enter the target element: ");
    scanf("%d", &target);

    int result = findFirstOccurrence(elements, num, target);
    if (result == -1) {
        printf("Target element is not present in the array\n");
    }
    else {
        printf("The first occurrence of the target element is at index: %d\n", result);
    }

    return 0;
}
