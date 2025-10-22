#include <bits/stdc++.h>
using namespace std;

// Operator Precedence Table
map<char, map<char, char>> precedenceTable = {
    {'+', {{'+', '>'}, {'*', '<'}, {'(', '<'}, {')', '>'}, {'i', '<'}, {'$', '>'}}},
    {'*', {{'+', '>'}, {'*', '>'}, {'(', '<'}, {')', '>'}, {'i', '<'}, {'$', '>'}}},
    {'(', {{'+', '<'}, {'*', '<'}, {'(', '<'}, {')', '='}, {'i', '<'}, {'$', ' '}}},
    {')', {{'+', '>'}, {'*', '>'}, {')', '>'}, {'$', '>'}}},
    {'i', {{'+', '>'}, {'*', '>'}, {')', '>'}, {'$', '>'}}},
    {'$', {{'+', '<'}, {'*', '<'}, {'(', '<'}, {'i', '<'}, {'$', '='}}}
};

int main() {
    string input;
    cout << "Enter input string (use 'i' for id): ";
    cin >> input;
    input += "$";

    stack<char> st;
    st.push('$');

    int i = 0;
    cout << "\nStack\t\tInput\t\tAction\n";
    cout << "------------------------------------------\n";

    while (true) {
        char top = st.top();
        char curr = input[i];

        // Display stack and input
        cout << st.top() << "\t\t" << input.substr(i) << "\t\t";

        if (top == '$' && curr == '$') {
            cout << "Accept\n";
            break;
        }

        char relation = precedenceTable[top][curr];

        if (relation == '<' || relation == '=') {
            st.push(curr);
            i++;
            cout << "Shift\n";
        }
        else if (relation == '>') {
            st.pop();
            cout << "Reduce\n";
        }
        else {
            cout << "Error: Invalid relation!\n";
            break;
        }
    }

    return 0;
}
