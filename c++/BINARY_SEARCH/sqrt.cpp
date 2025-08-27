#include <iostream>
#include <iomanip>  // for setprecision
using namespace std;

int intSqrt(int x) {
    int low = 0, high = x, ans = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid * mid <= x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

double sqrtWithPrecision(double x, double precision = 1e-6) {
    double low = 0, high = x;
    if (x < 1) high = 1;

    double mid;
    while ((high - low) > precision) {
        mid = (low + high) / 2.0;
        if (mid * mid < x)
            low = mid;
        else
            high = mid;
    }

    return (low + high) / 2.0;
}

int main() {
    double num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Integer square root: " << intSqrt((int)num) << endl;

    double root = sqrtWithPrecision(num);
    cout << fixed << setprecision(6);
    cout << "Square root with precision: " << root << endl;

    return 0;
}
