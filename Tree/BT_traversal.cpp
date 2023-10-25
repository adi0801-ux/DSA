//
// Created by Aditya Chauhan on 15/08/23.
//
#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *left;
    node *right;
    node (int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node *buildTree(node *root){
    cout<<"Enter the data:"<<endl;
    int data;
    cin>> data;
    root=new node(data);
    if(data==-1)return NULL;
    cout<<"Enter the left node:"<<data<<endl;
    root->left= buildTree(root->left);
    cout<<"Enter the right node:"<<data<<endl;
    root->right= buildTree(root->right);
    return root;
}
//LNR
void inorderTraversal(node *root){
    if(root==NULL)return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
void preOrderTraversal(node *root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(node *root){
    if(root==NULL)return;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    cout<<root->data<<" ";

}
int main() {
    node *root=NULL;
    root = buildTree(root);
    cout<<"inorder traversal is:"<<endl;
    inorderTraversal(root);
    cout<<endl;

    cout<<"preOrderTraversal is:"<<endl;
    preOrderTraversal(root);
    cout<<endl;

    cout<<"postOrder Traversal is:"<<endl;
    postOrderTraversal(root);
    cout<<endl;

    return 0;
}
