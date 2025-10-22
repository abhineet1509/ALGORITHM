#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterBrute(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1);
    
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[j] > arr[i]) {
                nge[i] = arr[j];
                break;
            }
        }
    }
    return nge;
}

vector<int> nextGreaterStart(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> s;
    
    for(int i = 0; i < n; i++) {
        while(!s.empty() && arr[i] > arr[s.top()]) {
            nge[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    return nge;
}

vector<int> nextGreaterEnd(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> s;
    
    for(int i = n-1; i >= 0; i--) {
        while(!s.empty() && s.top() <= arr[i]) s.pop();
        if(!s.empty()) nge[i] = s.top();
        s.push(arr[i]);
    }
    return nge;
}

void printVector(vector<int>& v) {
    for(int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};

    cout << "Original Array: ";
    printVector(arr);

    vector<int> resBrute = nextGreaterBrute(arr);
    cout << "Brute Force NGE: ";
    printVector(resBrute);

    vector<int> resStart = nextGreaterStart(arr);
    cout << "Start->End Stack NGE: ";
    printVector(resStart);

    vector<int> resEnd = nextGreaterEnd(arr);
    cout << "End->Start Stack NGE: ";
    printVector(resEnd);

    return 0;
}
