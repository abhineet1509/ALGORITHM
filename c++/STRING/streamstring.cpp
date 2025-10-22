#include <iostream>
#include<vector>
#include <sstream>
using namespace std;

int main() {
    // 1️⃣ Extract words from a string
    string text = "C++ is powerful";
    stringstream ss1(text);
    string word;
    cout << "Words from string:\n";
    while (ss1 >> word) {
        cout << word << endl;
    }

    // 2️⃣ Convert string to integer
    string s = "123";
    int num;
    stringstream ss2(s);
    ss2 >> num;
    cout << "\nString to integer: " << num + 10 << endl;

    // 3️⃣ Convert int to string
    int n = 45;
    stringstream ss3;
    ss3 << n;             // insert int into stream
    string str = ss3.str(); // extract as string
    cout << "\nInteger to string: " << str + " is now a string" << endl;

    // 4️⃣ Parse mixed data
     string input = "25 John 89.5 34 pink 56.4 3 blue 45.9";
    stringstream ss(input);

    vector<int> integers;
    vector<float> floats;
    vector<string> strings;

    string token;
    while (ss >> token) {
        // try to detect type
        stringstream temp(token);
        int i;
        float f;
        char c;

        // Check if integer
        if (temp >> i && !(temp >> c)) {
            integers.push_back(i);
        }
        else {
            temp.clear();
            temp.str(token);
            if (temp >> f && !(temp >> c)) {
                floats.push_back(f);
            } else {
                strings.push_back(token);
            }
        }
    }

    cout << "Integers: ";
    for (int x : integers) cout << x << " ";
    cout << "\nStrings: ";
    for (string s : strings) cout << s << " ";
    cout << "\nFloats: ";
    for (float y : floats) cout << y << " ";

    return 0;
}
