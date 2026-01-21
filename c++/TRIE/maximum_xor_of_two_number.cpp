#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[2] = {nullptr, nullptr};
};

void insert(TrieNode* root, int num) {
    TrieNode* node = root;
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!node->child[bit]) node->child[bit] = new TrieNode();
        node = node->child[bit];
    }
}

int findMaxXOR(TrieNode* root, int num) {
    TrieNode* node = root;
    int xorVal = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        int toggledBit = 1 - bit;
        if (node->child[toggledBit]) {
            xorVal |= (1 << i);
            node = node->child[toggledBit];
        } else {
            node = node->child[bit];
        }
    }
    return xorVal;
}

int findMaximumXOR(vector<int>& nums) {
    TrieNode* root = new TrieNode();
    for (int num : nums) insert(root, num);

    int maxXOR = 0;
    for (int num : nums) {
        maxXOR = max(maxXOR, findMaxXOR(root, num));
    }

    return maxXOR;
}

int main() {
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << "Maximum XOR: " << findMaximumXOR(nums) << endl; // Output: 28
    return 0;
}
