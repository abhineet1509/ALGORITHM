#include <bits/stdc++.h>
using namespace std;

/* ---------- PRIME FACTORIZATION ---------- */
void primeFactorization(int n) {
    cout << "Prime Factors: ";

    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    if (n > 1) {
        cout << n;
    }
    cout << endl;
}

 int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i < n; i++) {
            if (!isPrime[i]) continue;
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
        
        int count = 0;
        for (int i = 2; i < n; i++)
            if (isPrime[i]) count++;
        return count;
    }
    
/* ---------- UGLY NUMBER CHECK ---------- */
bool isUgly(int n) {
    if (n <= 0) return false;

    while (n % 2 == 0) n /= 2;
    while (n % 3 == 0) n /= 3;
    while (n % 5 == 0) n /= 5;

    return n == 1;
}

/* ---------- MAIN ---------- */
int main() {
    int n;
    cin >> n;

    primeFactorization(n);

    if (isUgly(n))
        cout << "Ugly Number: Yes";
    else
        cout << "Ugly Number: No";

    return 0;
}
