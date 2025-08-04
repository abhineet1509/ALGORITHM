#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Serialize tree to string using BFS
    string serialize(TreeNode* root) {
        if (!root) return "";

        string result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "null,";
            }
        }

        return result;
    }

    // Deserialize string to tree using BFS
    TreeNode* deserialize(const string& data) {
        if (data.empty()) return nullptr;

        vector<string> nodes = split(data, ',');
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < nodes.size()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            if (nodes[i] != "null") {
                node->left = new TreeNode(stoi(nodes[i]));
                q.push(node->left);
            }
            i++;

            // Right child
            if (i < nodes.size() && nodes[i] != "null") {
                node->right = new TreeNode(stoi(nodes[i]));
                q.push(node->right);
            }
            i++;
        }

        return root;
    }

private:
    vector<string> split(const string& s, char delimiter) {
        vector<string> result;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delimiter)) {
            result.push_back(item);
        }
        return result;
    }
};
int main() {
    Codec codec;

    // Build sample tree:
    //      1
    //     / \
    //    2   3
    //       / \
    //      4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string serialized = codec.serialize(root);
    cout << "Serialized Tree: " << serialized << endl;

    TreeNode* deserialized = codec.deserialize(serialized);
    cout << "Deserialized Tree Root: " << deserialized->val << endl;

    return 0;
}
