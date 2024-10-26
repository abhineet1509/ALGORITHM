#include <iostream>
#include <queue>
using namespace std;
struct Node {
  int data;
  Node* left;
  Node* right;
};
Node* newNode(int data) {
  Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}
void createBinaryTree(Node* root) {
  queue<Node*> q;
  q.push(root);

  while (!q.empty()) {
    Node* temp = q.front();
    q.pop();

    cout << temp->data << " ";

    if (temp->left != NULL) {
      q.push(temp->left);
    }

    if (temp->right != NULL) {
      q.push(temp->right);
    }
  }
}

int main() {
  Node* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  createBinaryTree(root);

  return 0;
}                  //tree using linked list
/*#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};
              
Node* newNode(int data) {
  Node* node = new Node();
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void createBinaryTree(Node*& root, Node* head) {
  if (head == NULL) {
    root = NULL;
    return;
  }

  root = newNode(head->data);
  createBinaryTree(root->left, head->next);
  createBinaryTree(root->right, head->next->next);
}

/*void printBinaryTree(Node* root) {
  if (root == NULL) {
    return;
  }

  cout << root->data << " ";
  printBinaryTree(root->left);
  printBinaryTree(root->right);
}

int main() {
  Node* head = newNode(1);
  head->next = newNode(2);
  head->next->next = newNode(3);
  head->next->next->next = newNode(4);
  head->next->next->next->next = newNode(5);

  Node* root = NULL;
  createBinaryTree(root, head);

  printBinaryTree(root);

  return 0;
}  */