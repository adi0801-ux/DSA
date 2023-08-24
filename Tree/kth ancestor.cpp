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
node* kthAncestor(node *root, int &k , int node ){
    if(root == NULL)
        return NULL;
    if(root->data == node)
    {
        return root;
    }
    auto leftAns = kthAncestor(root->left, k, node);
    auto rightAns = kthAncestor(root->right, k, node);
    //wapas
    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k<=0)
        {//answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns == NULL && rightAns != NULL) {
        k--;
        if(k<=0)
        {//answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int main() {
    node *root=NULL;
    root = buildTree(root);
    kthAncestor(root, 3, 3);
    return 0;
}
