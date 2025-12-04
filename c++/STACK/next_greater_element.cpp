#include <bits/stdc++.h>
using namespace std;

// ------------------------ NEXT / PREVIOUS HELPERS ------------------------

vector<int> nextGreater(vector<int>& arr) {   // from start
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] > arr[s.top()]) {
            res[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    return res;
}

vector<int> prevGreater(vector<int>& arr) {   // from start
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] <= arr[i]) s.pop();
        if (!s.empty()) res[i] = arr[s.top()];
        s.push(i);
    }
    return res;
}

vector<int> nextGreaterEnd(vector<int>& arr) {  // from end
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] <= arr[i]) s.pop();
        if (!s.empty()) res[i] = arr[s.top()];
        s.push(i);
    }
    return res;
}

vector<int> prevGreaterEnd(vector<int>& arr) {  // from end
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[i] >= arr[s.top()]) {
            res[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    return res;
}

vector<int> nextSmaller(vector<int>& arr) {  // from start
    int n = arr.size();
    vector<int> res(n, n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] < arr[s.top()]) {
            res[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return res;
}

vector<int> prevSmaller(vector<int>& arr) {  // from start
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
        if (!s.empty()) res[i] = s.top();
        s.push(i);
    }
    return res;
}

vector<int> nextSmallerEnd(vector<int>& arr) {  // from end
    int n = arr.size();
    vector<int> res(n, n);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
        if (!s.empty()) res[i] = s.top();
        s.push(i);
    }
    return res;
}

vector<int> prevSmallerEnd(vector<int>& arr) {  // from end
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[i] <= arr[s.top()]) {
            res[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return res;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << "Next Greater: ";
    for (int x : nextGreater(heights)) cout << x << " ";
    cout << "\nPrev Greater: ";
    for (int x : prevGreater(heights)) cout << x << " ";
    cout << "\nNext Greater (End): ";
    for (int x : nextGreaterEnd(heights)) cout << x << " ";
    cout << "\nPrev Greater (End): ";
    for (int x : prevGreaterEnd(heights)) cout << x << " ";
    cout << "\nNext Smaller: ";
    for (int x : nextSmaller(heights)) cout << x << " ";
    cout << "\nPrev Smaller: ";
    for (int x : prevSmaller(heights)) cout << x << " ";
    cout << "\nNext Smaller (End): ";
    for (int x : nextSmallerEnd(heights)) cout << x << " ";
    cout << "\nPrev Smaller (End): ";
    for (int x : prevSmallerEnd(heights)) cout << x << " ";

}
