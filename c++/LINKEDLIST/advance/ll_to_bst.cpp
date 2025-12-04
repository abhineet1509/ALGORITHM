#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    ListNode* headPtr;

    TreeNode* buildBST(int n) {
        if (n <= 0) return nullptr;
        TreeNode* left = buildBST(n / 2);
        TreeNode* root = new TreeNode(headPtr->val);
        root->left = left;
        headPtr = headPtr->next;
        root->right = buildBST(n - n / 2 - 1);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        headPtr = head;
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }
        return buildBST(n);
    }

    void preorder(TreeNode* root) {
        if (!root) return;
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void levelOrder(TreeNode* root) {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << "\n";
    }
};

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

int main() {
    vector<int> vals = {1, 2, 3, 4, 5, 6, 7};
    ListNode* head = createList(vals);

    Solution s;
    TreeNode* root = s.sortedListToBST(head);

    cout << "Preorder DFS: ";
    s.preorder(root);
    cout << "\n";

    cout << "Level Order BFS: ";
    s.levelOrder(root);

    return 0;
}
