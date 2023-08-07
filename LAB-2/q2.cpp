/* Write a function sine(x, d) that returns the sine of input x accurately
up to d decimal places computed using Taylor’s series approximation of sine.
 sin(x) = x - x3/3! + x5/5! - x7/7! + ...

Count and print the number of times the main loop in your program executes.

Check if the value of estimated parameter c1 is stable or changing according to the problem size. Explain your observation. Input: Enter x - 25.56
Enter decimal places - 3
Output: 0.431
*/

#include <iostream>
#include <cmath>

using namespace std;


double sine(double x, int d) {
    double result = 0.0;
    double term = x;
    int sign = 1;
    int n = 1;
    int loopCount = 0; 
    while (true) {
        loopCount++; 

        result += sign * term;

        sign *= -1;
        n += 2;

        term = pow(x, n) / tgamma(n + 1); 

        if (abs(term) < pow(0.1, d))
            break;
    }

    cout << "Loop count for main loop: " << loopCount << endl;
    return result;
}

int main() {
    double x;
    int d;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter decimal places: ";
    cin >> d;

    double result = sine(x, d);
    cout.precision(d);
    cout << "sine(" << x << ") = " << result << endl;

    return 0;
}
