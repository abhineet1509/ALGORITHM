#include <bits/stdc++.h>
using namespace std;

// Method 1: Two Pointer Method
void moveZeroEndTwoPointer(vector<int>& v){
    int i = 0;
    for(int j = 0; j < v.size(); j++){
        if(v[j] != 0) v[i++] = v[j];
    }
    while(i < v.size()) v[i++] = 0;
}

// Method 2: Swap Method
void moveZeroEndSwap(vector<int>& v){
    int last = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] != 0) swap(v[i], v[last++]);
    }
}

int main(){
    vector<int> v1 = {1,0,2,0,3,0,4,5};
    vector<int> v2 = v1; // copy for second method

    moveZeroEndTwoPointer(v1);
    cout << "Two Pointer: ";
    for(int x : v1) cout << x << " ";
    cout << endl;

    moveZeroEndSwap(v2);
    cout << "Swap Method: ";
    for(int x : v2) cout << x << " ";
}
