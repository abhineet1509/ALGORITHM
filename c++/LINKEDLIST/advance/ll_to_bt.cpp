#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Convert linked list to complete binary tree
    TreeNode* listToCompleteBinaryTree(ListNode* head) {
        if (!head) return nullptr;

        TreeNode* root = new TreeNode(head->val);
        head = head->next;

        queue<TreeNode*> q;
        q.push(root);

        while (head) {
            TreeNode* parent = q.front();
            q.pop();

            // Left child
            TreeNode* left = new TreeNode(head->val);
            parent->left = left;
            q.push(left);
            head = head->next;
            if (!head) break;

            // Right child
            TreeNode* right = new TreeNode(head->val);
            parent->right = right;
            q.push(right);
            head = head->next;
        }

        return root;
    }
};

// Helper: create linked list from vector
ListNode* createList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* temp = head;
    for (int i = 1; i < vals.size(); i++) {
        temp->next = new ListNode(vals[i]);
        temp = temp->next;
    }
    return head;
}

// Helper: print level order of binary tree
void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            TreeNode* node = q.front(); q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << "\n";
    }
}

// Main function to test
int main() {
    vector<int> vals = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode* head = createList(vals);

    Solution s;
    TreeNode* root = s.listToCompleteBinaryTree(head);

    cout << "Level order of the Complete Binary Tree:\n";
    printLevelOrder(root);

    return 0;
}
