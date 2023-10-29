//
// Created by Aditya Chauhan on 23/08/23.
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
node* lca(node* root ,int n1 ,int n2 )
{
    //Your code here
    if(root==NULL || root->data==n1 || root->data==n2){
        return root;
    }
    auto left = lca(root->left, n1, n2);
    auto right = lca(root->right, n1, n2);
    if(left==NULL)return right;
    if(right==NULL)return left;
    else return root;

}
int main() {
    node *root=NULL;
    root = buildTree(root);
    lca(root, 3,5);
    return 0;
}
