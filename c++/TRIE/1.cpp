#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, c;
        cin >> n >> c;
        string s;
        cin >> s;

        unordered_set<char> unique_languages(s.begin(), s.end());
        int unique_count = unique_languages.size();

        // Cost if Chef learns all unique languages
        int cost_learning = unique_count * c;

        // Cost if Chef uses only translators
        int cost_translating = 0;
        for (int i = 1; i <= unique_count; i++) {
            cost_translating += i;
        }

        // Minimum of both strategies
        cout << min(cost_learning, cost_translating) << endl;
    }

    return 0;
}

