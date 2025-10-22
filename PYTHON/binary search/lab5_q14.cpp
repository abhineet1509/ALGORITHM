#include <bits/stdc++.h>
using namespace std;

// Define the grammar
// E → E+T
// T → T*F | F
// F → (E) | char

struct Rule {
    string lhs;
    string rhs;
};

vector<Rule> grammar = {
    {"E", "E+T"},
    {"E", "T"},
    {"T", "T*F"},
    {"T", "F"},
    {"F", "(E)"},
    {"F", "char"}
};

bool isTerminal(char c) {
    return !(c >= 'A' && c <= 'Z');
}

// Simplified action/goto table (for demonstration)
map<pair<int, char>, string> action = {
    {{0, 'c'}, "s5"}, {{0, '('}, "s4"},
    {{1, '+'}, "s6"}, {{1, '$'}, "acc"},
    {{2, '+'}, "r2"}, {{2, '*'}, "s7"}, {{2, ')'}, "r2"}, {{2, '$'}, "r2"},
    {{3, '+'}, "r4"}, {{3, '*'}, "r4"}, {{3, ')'}, "r4"}, {{3, '$'}, "r4"},
    {{4, 'c'}, "s5"}, {{4, '('}, "s4"},
    {{5, '+'}, "r6"}, {{5, '*'}, "r6"}, {{5, ')'}, "r6"}, {{5, '$'}, "r6"},
    {{6, 'c'}, "s5"}, {{6, '('}, "s4"},
    {{7, 'c'}, "s5"}, {{7, '('}, "s4"},
    {{8, '+'}, "s6"}, {{8, ')'}, "s11"},
    {{9, '+'}, "r1"}, {{9, '*'}, "s7"}, {{9, ')'}, "r1"}, {{9, '$'}, "r1"},
    {{10, '+'}, "r3"}, {{10, '*'}, "r3"}, {{10, ')'}, "r3"}, {{10, '$'}, "r3"},
    {{11, '+'}, "r5"}, {{11, '*'}, "r5"}, {{11, ')'}, "r5"}, {{11, '$'}, "r5"}
};

map<pair<int, char>, int> goTo = {
    {{0, 'E'}, 1}, {{0, 'T'}, 2}, {{0, 'F'}, 3},
    {{4, 'E'}, 8}, {{4, 'T'}, 2}, {{4, 'F'}, 3},
    {{6, 'T'}, 9}, {{6, 'F'}, 3},
    {{7, 'F'}, 10}
};

int main() {
    string input;
    cout << "Enter the input string (use 'c' for char): ";
    cin >> input;
    input += "$";

    stack<int> stateStack;
    stack<char> symbolStack;
    stateStack.push(0);

    int i = 0;

    cout << "\nStack\t\tInput\t\tAction\n";
    cout << "----------------------------------------------\n";

    while (true) {
        int state = stateStack.top();
        char curr = input[i];
        cout << state << "\t\t" << input.substr(i) << "\t\t";

        string act = action[{state, curr}];

        if (act == "") {
            cout << "Error\n";
            break;
        }

        if (act == "acc") {
            cout << "Accept\n";
            break;
        }

        if (act[0] == 's') { // Shift
            int nextState = stoi(act.substr(1));
            symbolStack.push(curr);
            stateStack.push(nextState);
            i++;
            cout << "Shift " << nextState << "\n";
        } else if (act[0] == 'r') { // Reduce
            int ruleNo = stoi(act.substr(1));
            Rule rule = grammar[ruleNo - 1];
            int popCount = rule.rhs.size();

            for (int j = 0; j < popCount; j++) {
                stateStack.pop();
                symbolStack.pop();
            }

            symbolStack.push(rule.lhs[0]);

            int newState = goTo[{stateStack.top(), rule.lhs[0]}];
            stateStack.push(newState);

            cout << "Reduce by " << rule.lhs << " -> " << rule.rhs << "\n";
        }
    }

    return 0;
}
