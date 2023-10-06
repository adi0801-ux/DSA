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
node* searchBST(node* root, int val) {
    while(root!=NULL && root->data!=val){
        root=val<root->data? root->left:root->right;
    }
    return root;
}
int main() {
    node *root=NULL;
    root = buildTree(root);
    int val;
    cin>>val;
    cout<<searchBST(root, 3);
    return 0;
}
