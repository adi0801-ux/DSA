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

void kSumPath(node*root, int k, int &count, vector<int>v){
    if(root==NULL)return;
    v.push_back(root->data);
    kSumPath(root->left, k, count, v);
    kSumPath(root->right, k, count, v);
    int sum=0;
    for(int i=v.size()-1;i>=0;i--){
        sum+=v[i];
        if(sum==k)count++;
    }
    v.pop_back();
}
int main() {
    node *root=NULL;
    root = buildTree(root);
    int count=0;
    vector<int>v;
    kSumPath(root, 4,count,v);
    cout<<count;
    return 0;
}
