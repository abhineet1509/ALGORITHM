#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

struct Info {
    bool isBST;
    int size;
    int minVal;
    int maxVal;
};

Info largestBST(Node* root, int &ans) {
    if (!root)
        return {true, 0, INT_MAX, INT_MIN};

    Info left = largestBST(root->left, ans);
    Info right = largestBST(root->right, ans);

    Info curr;

    if (left.isBST && right.isBST &&
        left.maxVal < root->data &&
        root->data < right.minVal) {

        curr.isBST = true;
        curr.size = left.size + right.size + 1;
        curr.minVal = min(root->data, left.minVal);
        curr.maxVal = max(root->data, right.maxVal);

        ans = max(ans, curr.size);
    } 
    else {
        curr.isBST = false;
        curr.size = max(left.size, right.size);
        curr.minVal = INT_MIN;
        curr.maxVal = INT_MAX;
    }

    return curr;
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(60);
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    int ans = 0;
    largestBST(root, ans);

    cout << ans << endl;
    return 0;
}
