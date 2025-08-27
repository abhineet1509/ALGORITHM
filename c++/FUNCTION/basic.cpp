#include <iostream>
using namespace std;

// Factorial
int factorial(int n) {
    return n == 0 ? 1 : n * factorial(n - 1);
}

// Fibonacci
int fibonacci(int n) {
    return n <= 1 ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

// Sum of first n numbers
int sumN(int n) {
    return n == 0 ? 0 : n + sumN(n - 1);
}

// Print 1 to n (increasing)
void printInc(int n) {
    if (n == 0) return;
    printInc(n - 1);
    cout << n << " ";
}

// Print n to 1 (decreasing)
void printDec(int n) {
    if (n == 0) return;
    cout << n << " ";
    printDec(n - 1);
}

int main() {
    int n;
    cin >> n;

    cout << "Factorial: " << factorial(n) << endl;
    cout << "Fibonacci: " << fibonacci(n) << endl;
    cout << "Sum: " << sumN(n) << endl;

    cout << "Increasing: ";
    printInc(n);
    cout << "\nDecreasing: ";
    printDec(n);
    cout << endl;
}
