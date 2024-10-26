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
void size(Node*root,int &count){
if(root==NULL){
    return;
}
count++;
size(root->left,count);
size(root->right,count);
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
    int count=0;
    size(root,count);
    cout<<count;
   }