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
int ceil(node* root, int key){
    int ceil=-1;
    while(root){
        if(root->data==key){
            ceil=root->data;
            return ceil;
        }
        if(key>root->data)root=root->right;
        else{
            ceil=root->data;
            root=root->left;
        }
    }
    return ceil;
}
int main() {
    node *root=NULL;
    root = buildTree(root);
    int key;
    cin>>key;
    cout<<ceil(root, key);
    return 0;
}
