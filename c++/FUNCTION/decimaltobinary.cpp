#include <iostream>
using namespace std;

int main() {
  int num, bin = 0, rem, i = 1;

  cout << "Enter a decimal number: ";
  cin >> num;

  while (num > 0) {
    rem = num % 2;
    bin += rem * i;
    i *= 10;
    num /= 2;
  }
  cout << "The binary equivalent of"<<"is" << bin << endl;
  return 0;
}