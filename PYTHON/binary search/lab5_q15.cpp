#include <bits/stdc++.h>
using namespace std;

/*
Grammar:
E  -> T E'
E' -> + T E' | ε
T  -> F T'
T' -> * F T' | ε
F  -> (E) | id
*/

string input;
int i = 0;

// Function declarations
bool E();
bool E_();
bool T();
bool T_();
bool F();

bool match(char c) {
    if (i < input.size() && input[i] == c) {
        i++;
        return true;
    }
    return false;
}

bool F() {
    if (match('(')) {
        if (E()) {
            if (match(')'))
                return true;
            else
                return false;
        }
        return false;
    }
    else if (input.substr(i, 2) == "id") { // match identifier
        i += 2;
        return true;
    }
    return false;
}

bool T_() {
    if (match('*')) {
        if (F()) {
            if (T_()) return true;
        }
        return false;
    }
    // ε-production
    return true;
}

bool T() {
    if (F()) {
        if (T_()) return true;
    }
    return false;
}

bool E_() {
    if (match('+')) {
        if (T()) {
            if (E_()) return true;
        }
        return false;
    }
    // ε-production
    return true;
}

bool E() {
    if (T()) {
        if (E_()) return true;
    }
    return false;
}

int main() {
    cout << "Enter input string (use 'id' for identifiers): ";
    cin >> input;
    input += "$"; // Sentinel symbol

    bool valid = E() && input[i] == '$';

    if (valid)
        cout << "\nString is accepted (valid expression)\n";
    else
        cout << "\nString is rejected (invalid expression)\n";

    return 0;
}
