#include <iostream>
using namespace std;

double power(double x, int n) {
    long long exp = n;
    if (exp < 0) {
        x = 1.0 / x;
        exp = -exp;
    }

    double result = 1.0;
    while (exp > 0) {
        if (exp % 2 == 1)
            result *= x;
        x *= x;
        exp /= 2;
    }

    return result;
}

int main() {
    double x;
    int n;

    cout << "Enter base (x): ";
    cin >> x;

    cout << "Enter exponent (n): ";
    cin >> n;

    double result = power(x, n);
    cout << x << "^" << n << " = " << result << endl;

    return 0;
}
