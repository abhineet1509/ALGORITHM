#include <bits/stdc++.h>
using namespace std;

class BinaryTreeArray {
    vector<int> tree;
public:
    BinaryTreeArray(int size) {
        tree.resize(size, -1); // initialize with -1 for empty nodes
    }

    void insert(int value, int index) {
        if (index >= tree.size()) {
            cout << "Index out of bounds!\n";
            return;
        }
        tree[index] = value;
    }

    void display() {
        for (int i = 0; i < tree.size(); i++) {
            if(tree[i] != -1)
                cout << tree[i] << " ";
        }
        cout << endl;
    }

    void preorder(int index = 0) {
        if (index >= tree.size() || tree[index] == -1) return;
        cout << tree[index] << " ";
        preorder(2*index + 1);
        preorder(2*index + 2);
    }
};

int main() {
    BinaryTreeArray bt(10);

    bt.insert(1, 0); // root
    bt.insert(2, 1); // left of root
    bt.insert(3, 2); // right of root
    bt.insert(4, 3); // left of 2
    bt.insert(5, 4); // right of 2

    cout << "Tree nodes: ";
    bt.display();

    cout << "Preorder traversal: ";
    bt.preorder();
    cout << endl;

    return 0;
}
