#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left,*right;
    Node(int value){
        data=value;
        left=right=NULL;
    }

};
void preorder(Node *root){
    if(root==NULL)  return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
Node * BinaryTree(){
    int x;
    cin>>x;
    if(x==-1)  return NULL;
    Node *temp = new Node(x);
    cout<<"enter the left child of"<<x<<endl;
    temp->left = BinaryTree();
    cout<<"enter the right child of"<<x<<endl;
    temp->right = BinaryTree();
    return temp;
}
int main(){
    cout<<"enter the root node:";
    Node *root;
    root = BinaryTree();
   cout<<"pre-order :";  // cout<<"in-order :";            //   cout<<" post order";
   preorder(root);       //inorder(root);                  //   postorder(root);

   }