#include <iostream>
#include <vector>
#include <string>
using namespace std;

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";

    int n = num1.size(), m = num2.size();
    vector<int> result(n + m, 0);

    // Multiply each digit
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j] += sum / 10;         // carry
            result[i + j + 1] = sum % 10;      // digit
        }
    }

    // Convert result to string
    string res = "";
    for (int num : result) {
        if (!(res.empty() && num == 0))  // Skip leading zeros
            res += to_string(num);
    }

    return res.empty() ? "0" : res;
}
int main() {
    string num1 = "123";
    string num2 = "45";
    cout << multiply(num1, num2) << endl; // Output: 5535
}
