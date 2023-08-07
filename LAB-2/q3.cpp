/* Write a function gcd(k) which returns the GCD of kth and (k+1)th Fibonacci numbers for k>1. Use Euclid’s algorithm to calculate the GCD. Count the number of
times the GCD loop executes for different values of k and record your observations in the
following table.

Check if the value of estimated parameter c1 is stable or changing according to the input value. Justify your observation.
 Input: Enter k - 10
Output: 10th and 11th Fibonacci numbers - 34,55
GCD = 1
*/

#include <iostream>

using namespace std;

int fibonacci(int k) {
    if (k <= 0)
        return 0;
    else if (k == 1)
        return 1;

    int prev = 0, curr = 1;
    for (int i = 2; i <= k; ++i) {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}


int gcd(int a, int b) {
    int loopCount = 0; 
    while (b != 0) {
        loopCount++; 
        int temp = b;
        b = a % b;
        a = temp;
    }
    cout << "Loop count for GCD function: " << loopCount << endl;
    return a;
}

int main() {
    int k;
    cout << "Enter k: ";
    cin >> k;

    int fib_k = fibonacci(k);
    int fib_k_plus_1 = fibonacci(k + 1);

    cout << k << "th and " << k + 1 << "th Fibonacci numbers: " << fib_k << ", " << fib_k_plus_1 << endl;

    int result = gcd(fib_k, fib_k_plus_1);
    cout << "GCD = " << result << endl;

    return 0;
}
