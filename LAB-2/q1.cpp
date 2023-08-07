/* Write a function generatePrimes(n) that returns an array of prime
numbers less than or equal to n. If your program contains one or more loops, count and print the
number of times each loop is executed.

Check if the values of estimated parameters c1 and c2 are stable or slowly increasing according
to the problem size. Explain your observation. 

Input: Enter n - 10
Output: Prime numbers - 2 3 5 7
*/

#include <iostream>

using namespace std;


bool isPrime(int num) {
    if (num <= 1)
        return false;

    int loopCount = 0; 
    for (int i = 2; i * i <= num; ++i) {
        ++loopCount; 
        if (num % i == 0)
            return false;
    }
    cout << "Loop count for isPrime function: " << loopCount << endl;
    return true;
}


int generatePrimes(int n, int primes[]) {
    int count = 0;
    for (int i = 2; i <= n; ++i) {
        if (isPrime(i)) {
            primes[count++] = i;
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int primes[n]; 
    int count = generatePrimes(n, primes);

    cout << "Prime numbers: ";
    for (int i = 0; i < count; ++i) {
        cout << primes[i] << " ";
    }
    cout << endl;

    return 0;
}
