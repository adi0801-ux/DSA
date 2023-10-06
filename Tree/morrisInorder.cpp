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

vector<int>morrisInorder(node* root,vector<int>&inorder){

    node* cur=root;
    while(cur) {
        if (cur->left == NULL) {
            inorder.push_back(cur->data);
            cur = cur->right;
        }
        else{
            node* prev=cur;
            while(prev->right && prev->right!=cur){
                cur=cur->right;
            }
            if(prev->right==NULL){
                prev->right=cur;
                cur=cur->left;
            }else{
                prev->right=NULL;
                inorder.push_back(cur->data);
                cur=cur->left;
            }
        }
    }
    return inorder;
}
int main() {
    node *root=NULL;
    root = buildTree(root);
    vector<int>inorder;
    morrisInorder(root, inorder);
    for(int i=0;i<inorder.size();i++){
        cout<<inorder[i];
    }
    return 0;
}
