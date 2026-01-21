#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;

    for (int i = 0; i < asteroids.size(); i++) {
        int a = asteroids[i];
        bool destroyed = false;

        while (!st.empty() && a < 0 && st.top() > 0) {
            if (abs(st.top()) < abs(a)) {
                st.pop();
                continue;
            } else if (abs(st.top()) == abs(a)) {
                st.pop();
            }
            destroyed = true;
            break;
        }

        if (!destroyed)
            st.push(a);
    }

    vector<int> res(st.size());
    for (int i = st.size() - 1; i >= 0; i--) {
        res[i] = st.top();
        st.pop();
    }
    return res;
}

int main() {
    vector<int> asteroids = {5, 10, -5};

    vector<int> ans = asteroidCollision(asteroids);

    cout << "Result: ";
    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
