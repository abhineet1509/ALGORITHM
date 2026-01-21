#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val) : data(val) {}
};

// Sum of k smallest
void sumKSmallest(Node* root, int k, int &count, int &sum) {
    if (!root || count >= k) return;
    sumKSmallest(root->left, k, count, sum);      // go left first
    if (count < k) {
        sum += root->data;
        count++;
    }
    sumKSmallest(root->right, k, count, sum);
}

// Sum of k largest
void sumKLargest(Node* root, int k, int &count, int &sum) {
    if (!root || count >= k) return;
    sumKLargest(root->right, k, count, sum);     // go right first
    if (count < k) {
        sum += root->data;
        count++;
    }
    sumKLargest(root->left, k, count, sum);
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    int k = 3;

    int count = 0, sumSmall = 0;
    sumKSmallest(root, k, count, sumSmall);
    cout << "Sum of " << k << " smallest: " << sumSmall << endl;

    count = 0; int sumLarge = 0;
    sumKLargest(root, k, count, sumLarge);
    cout << "Sum of " << k << " largest: " << sumLarge << endl;
}
