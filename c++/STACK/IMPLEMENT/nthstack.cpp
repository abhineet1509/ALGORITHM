#include <iostream>
#include <vector>
using namespace std;

class NStack {
    int *arr, *top, *next;   // *next next free slot after i 
    int n, s, freeSpot;

public:
    NStack(int N, int S) {
        n = N;
        s = S;
        arr = new int[S];
        top = new int[N];
        next = new int[S];

        for (int i = 0; i < N; i++) top[i] = -1;
        for (int i = 0; i < S - 1; i++) next[i] = i + 1;
        next[S - 1] = -1;

        freeSpot = 0;
    }

    bool push(int x, int m) {
        if (freeSpot == -1) return false; // Overflow

        int index = freeSpot;
        freeSpot = next[index];
        arr[index] = x;

        next[index] = top[m - 1];
        top[m - 1] = index;

        return true;
    }

    int pop(int m) {
        if (top[m - 1] == -1) return -1; // Underflow

        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};
int main() {
    NStack st(3, 10); // 3 stacks in array of size 10

    st.push(10, 1);
    st.push(20, 1);
    st.push(30, 2);

    cout << st.pop(1) << endl; // 20
    cout << st.pop(2) << endl; // 30
    cout << st.pop(3) << endl; // -1 (empty)
}
