#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int n = 45;
    stringstream ss;
    ss << n;

    string str = ss.str();  // convert to string
    cout << str + " is now a string";
}
