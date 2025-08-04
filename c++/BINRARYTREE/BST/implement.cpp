#include<iostream>
#include<vector>
using namespace std;
 

 class Node {
    public:
        int data;
        Node* left;
        Node* right;
    
        Node(int val) {
            data = val;
            left = NULL;
            right = NULL;
        }
 };
 vector<int> inorder(Node * root) {
    vector<int> result;
    if (root == NULL) return result;

     inorder(root->left);

    result.push_back(root->data);

     inorder(root->right);

    return result;
 }
 Node * insert(Node* root,int val){
   if(!root) return;
    if(val < root->data) {
         root->left = insert(root->left, val);
    } else if(val > root->data) {
         root->right = insert(root->right, val);
    }
 }
 int main(){
    Node* root = nullptr;
    insert(root,1);
    insert(root,2);
    insert(root,3);
    insert(root,4);
    insert(root,5);
    insert(root,6);

    vector<int> i = inorder(root);
    for(int j = 0; j < i.size(); j++) {
        cout << i[j] << " ";
    }
 }
