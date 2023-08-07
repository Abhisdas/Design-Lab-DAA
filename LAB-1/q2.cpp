/* Write a program to display an array of n integers (n>1), where every
index of the array should contain the product of all elements in the input array except the element
at the given index. Solve this problem by taking a single loop and without an additional array. 
Input Array: 3 4 5 1 2
Output Array: 40 30 24 120 6 */


#include <iostream>

int main() {
    int n;
    std::cout << "Enter the size of the array n > 1: ";
    std::cin >> n;

    if (n <= 1) {
        std::cout << "Please enter n > 1" << std::endl;
        return 1;
    }

    int* arr = new int[n];

    std::cout << "Enter " << n << " Integers separated by spaces: ";
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

    int product = 1;
    for (int i = 0; i < n; ++i)
        product *= arr[i];

    std::cout << "Output Array: ";
    for (int i = 0; i < n; ++i)
        std::cout << product / arr[i] << " ";

    std::cout << std::endl;

    delete[] arr;
    return 0;
}