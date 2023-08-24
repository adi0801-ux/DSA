//
// Created by Aditya Chauhan on 22/08/23.
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
void solve(node *root, int sum , int &maxSum, int len, int &maxLen){
    if(root==NULL){
        if(len>maxLen){
            maxLen=len;
            maxSum =sum;
        }
        else if(len==maxLen){
            maxSum =max(sum , maxSum);
        }
        return;
    }
    sum=sum+root->data;
    solve(root->left, sum, maxSum, len+1, maxLen);
    solve(root->right, sum, maxSum, len+1, maxLen);

}


int main() {
    node *root=NULL;
    root = buildTree(root);
    int sum=0;
    int maxSum=INT_MIN;
    int len=0;
    int maxLen=INT_MIN;
    solve(root, sum ,maxSum,len, maxLen);
    return 0;
}
