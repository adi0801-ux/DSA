//
// Created by Aditya Chauhan on 24/08/23.
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
pair<int, int>solve(node* root){
    if(root==NULL){
        pair<int, int>p=make_pair(0,0);
        return p;
    }
    auto left=solve(root->left);
    auto right=solve(root->right);

    pair<int, int>res;
    res.first=root->data+left.second+right.second;
    res.second=max(left.first, left.second)+max(right.first, right.second);
    return res;

}
int getMaxSum(node *root)
{
    pair<int,int> ans = solve(root);
    return max(ans.first, ans.second);
}
int main() {
    node *root=NULL;
    root = buildTree(root);
    cout<<getMaxSum(root);
    return 0;
}
