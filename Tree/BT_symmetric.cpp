//
// Created by Aditya Chauhan on 07/11/23.
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

bool isSymmetric(node*root){
    return Equivalent(root->left, root->right);
}
bool Equivalent(node*left, node*right){
    if(!left || !right)return left=right;
    else if(left->data != right->data)return false;
    else return Equivalent(left->left, right->right) && Equivalent(left->right,right->left);
}
int main() {
    node *root=NULL;
//    node* prev=NULL;
    root = buildTree(root);
    flatten(root);
    return 0;
}