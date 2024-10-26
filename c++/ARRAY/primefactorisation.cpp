#include <iostream>
using namespace std;

void primeFactorization(int n) {
    // Handle the factor of 2
    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }
    // Handle odd factors
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    // If n is a prime number greater than 2
    if (n > 2)
        cout << n;
    cout << endl;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    primeFactorization(n);
    return 0;
}
