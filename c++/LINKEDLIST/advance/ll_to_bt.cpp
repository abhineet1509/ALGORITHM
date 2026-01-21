#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int x) {
        data = x;
        next = NULL;
    }
};


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        data = x;
        left = right = NULL;
    }
};

/* ---------- Convert Linked List to Binary Tree ---------- */
TreeNode* LLtoBT(ListNode* head) {
    if (!head) return NULL;

    TreeNode* root = new TreeNode(head->data);
    queue<TreeNode*> q;
    q.push(root);

    head = head->next;

    while (head) {
        TreeNode* parent = q.front();
        q.pop();

        // Left child
        TreeNode* leftChild = new TreeNode(head->data);
        parent->left = leftChild;
        q.push(leftChild);
        head = head->next;

        // Right child
        if (head) {
            TreeNode* rightChild = new TreeNode(head->data);
            parent->right = rightChild;
            q.push(rightChild);
            head = head->next;
        }
    }

    return root;
}


void levelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main() {
    // Create Linked List: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    // Convert LL to Binary Tree
    TreeNode* root = LLtoBT(head);

    // Print Level Order of Tree
    cout << "Level Order Traversal of Binary Tree:\n";
    levelOrder(root);

    return 0;
}
