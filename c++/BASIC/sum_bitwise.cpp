#include <bits/stdc++.h>
using namespace std;

int add(int a, int b) {
    while (b != 0) {
        int carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}

int divide(int dividend, int divisor) {
    if (divisor == 0) {
        throw runtime_error("Divide by zero!");
    }
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    long long a = abs((long long)dividend);
    long long b = abs((long long)divisor);
    int ans = 0;

    while (a >= b) {
        long long temp = b, multiple = 1;
        while (a >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        a -= temp;
        ans += multiple;
    }

    return sign * ans;
}

int main() {
    int choice;
    cout << "Choose operation:\n1. Add\n2. Divide\nEnter choice: ";
    cin >> choice;

    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    try {
        if (choice == 1) {
            cout << "Sum: " << add(x, y) << endl;
        } else if (choice == 2) {
            cout << "Quotient: " << divide(x, y) << endl;
        } else {
            cout << "Invalid choice!" << endl;
        }
    } catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }
