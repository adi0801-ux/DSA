//
// Created by Aditya Chauhan on 05/11/23.
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
int solve(node* root, int &maxi){
    if(root==NULL)return 0;
    int lsum=max(0,solve(root->left, maxi));
    int rsum=max(0, solve(root->right, maxi));
    maxi=max(maxi , root->data+lsum+rsum);
    return root->data+max(lsum , rsum);

}
int maxPathSum(node* root) {
    int maxi=0;
    solve(root, maxi);
    return maxi;
}

int main() {
    node *root=NULL;
//    node* prev=NULL;
    root = buildTree(root);
    maxPathSum(root);
    return 0;
}
