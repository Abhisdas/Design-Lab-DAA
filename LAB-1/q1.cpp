/* Write a program in cpp to find out the second smallest and second largest element stored in an array of n integers. n is the user input. The array takes input through random
number generation within a given range. 
Input: Array of Size n. Generate the array element through a random generator. 
Output: second smallest, second large */

#include <iostream>
using namespace std;

void find(int *array, int n) {
  int smallest = array[0];
  int second_smallest = -1;
  int largest = array[0];
  int second_largest = -1;
  for (int i = 1; i < n; i++) {
    if (array[i] < smallest) {
      second_smallest = smallest;
      smallest = array[i];
    } 
    else if (array[i] < second_smallest || second_smallest == -1) {
      second_smallest = array[i];
    } 

    if (array[i] > largest) {
      second_largest = largest;
      largest = array[i];
    } 
    else if (array[i] > second_largest || second_largest == -1) {
      second_largest = array[i];
    }
  }
  cout << "second smallest: " << second_smallest << endl;
  cout << "second largest: " << second_largest << endl;
}

int main() {
  int n;
  cin >> n;
  int *array = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> array[i];
  }
  find(array, n);
  delete[] array;
  return 0;
}