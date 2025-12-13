#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[2] = {nullptr, nullptr};
};

void insert(TrieNode* root, int num) {
    TrieNode* node = root;
    for (int i = 31; i >= 0; i--) {
        int b = (num >> i) & 1;
        if (!node->child[b]) node->child[b] = new TrieNode();
        node = node->child[b];
    }
}

int query(TrieNode* root, int num) {
    TrieNode* node = root;
    int ans = 0;
    for (int i = 31; i >= 0; i--) {
        int b = (num >> i) & 1;
        if (node->child[1-b]) {
            ans |= (1 << i);
            node = node->child[1-b];
        } else {
            node = node->child[b];
        }
    }
    return ans;
}

int maxXORSubarray(vector<int>& arr) {
    TrieNode* root = new TrieNode();
    insert(root, 0); // prefix xor 0
    int result = 0, prefix = 0;
    for (int x : arr) {
        prefix ^= x;
        result = max(result, query(root, prefix));
        insert(root, prefix);
    }
    return result;
}

int main() {
    vector<int> arr = {8, 1, 2, 12};
    cout << "Maximum XOR Subarray: " << maxXORSubarray(arr) << endl;
}
