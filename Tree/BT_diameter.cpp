//
// Created by Aditya Chauhan on 15/08/23.
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
//*****************bruteForce O(n2)*****************
//int height(node* root){
//    if(root==NULL)return 0;
//    int h1= height(root->left);
//    int h2= height(root->right);
//    return 1+ max(h1, h2);
//}

//int diameter(node *root){
//    if(root==NULL)return 0;
//    int op1= diameter(root->left);
//    int op2= diameter(root->right);
//    int op3= height(root->left)+ height(root->right)+1;
//    return max(op1, max(op2,op3));
//}

//*****************optimised approach*******************
pair<int, int>diameterFast(node* root){
    if (root==NULL){
        //{diameter, height}
        pair<int , int >p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left= diameterFast(root->left);
    pair<int, int> right= diameterFast(root->right);

    int op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second+1;
    pair<int , int>ans;
    ans.first=max(op1, max(op2, op3));
    ans.second=max(left.second, right.second)+1;
    return ans;
}
int main() {
    node *root=NULL;
    root = buildTree(root);
//    cout<<diameter(root);
    cout<<diameterFast(root).first;
    return 0;
}
