#include <stdio.h>

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
    
    int index = -1;
    for (int i = 0; i < num; i++) {
        if (elements[i] == target) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Target element is not found in the array\n");
    }
    else {
        printf("Target element is found at index: %d\n", index);
    }
    
    return 0;
}
