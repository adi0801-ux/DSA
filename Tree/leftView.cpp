//
// Created by Aditya Chauhan on 18/08/23.
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
void leftView(node* root, vector<int>&ans, int level){
    if(root==NULL)return;
    if(level==ans.size())ans.push_back(root->data);
    if(root->left)leftView(root->left, ans, level+1);
    if(root->right)leftView(root->right, ans, level+1);
}

int main() {
    node *root=NULL;
    vector<int>ans;
    root = buildTree(root);
    leftView(root, ans, 0);
    for(auto it:ans)cout<<it;
    return 0;
}

