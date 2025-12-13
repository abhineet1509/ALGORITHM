#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Serialize tree to string
    string serialize(TreeNode* root) {
        if (!root) return "null";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            if (cur) {
                s += to_string(cur->val) + ",";
                q.push(cur->left);
                q.push(cur->right);
            } else {
                s += "null,";
            }
        }

        return s;
    }

    // Deserialize string to tree
    TreeNode* deserialize(string data) {
        if (data == "null") return NULL;

        stringstream ss(data);
        string val;
        getline(ss, val, ',');

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            string leftVal, rightVal;
            if (!getline(ss, leftVal, ',')) break;
            if (!getline(ss, rightVal, ',')) break;

            if (leftVal != "null") {
                cur->left = new TreeNode(stoi(leftVal));
                q.push(cur->left);
            }

            if (rightVal != "null") {
                cur->right = new TreeNode(stoi(rightVal));
                q.push(cur->right);
            }
        }

        return root;
    }
};

int main() {
    Codec codec;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string s = codec.serialize(root);
    cout << "Serialized: " << s << endl;

    TreeNode* restored = codec.deserialize(s);
    cout << "Deserialized Root = " << restored->val << endl;

    return 0;
}
