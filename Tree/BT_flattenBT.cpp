//
// Created by Aditya Chauhan on 28/08/23.
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

//***********OPTIMISED***********
void flatten(node* root){
node* cur=root;
while(cur!=NULL){
if(cur->left!=NULL){
node* prev=cur->left;
while(prev->right){
prev=prev->right;
}
prev->right=cur->right;
cur->right=cur->left;
cur->left=NULL;
}
cur=cur->right;
}
}
//***********BRUTE FORCE************
//    void flatten(node* root, node* &prev) {
//        if(root==NULL)return;
//        flatten(root->right, prev);
//        flatten(root->left, prev);
//        root->right=prev;
//        root->left=NULL;
//        prev=root;
//    }

int main() {
    node *root=NULL;
//    node* prev=NULL;
    root = buildTree(root);
    flatten(root);
    return 0;
}
