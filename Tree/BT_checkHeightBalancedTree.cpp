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
////OPTIMISED APPROACH O(N)
int dfsHt(node *root){
    if(root==NULL)return 0;
    int lh= dfsHt(root->left);
    if (lh==-1)return -1;
    int rh= dfsHt(root->right);
    if(rh==-1)return -1;
    if(abs(lh-rh)>1)return -1;
    return max(lh, rh)+1;
}
bool checkHt(node *root){
    if(dfsHt(root)!=-1)return true;
    else return false;
}
///BRUTE FORCE TC-0(N2)
//int height(node* root){
//    if(root==NULL)return 0;
//    int lh = height(root->left);
//    int rh = height(root->right);
//    return max(lh, rh)+1;
//}
//bool checkHt(node* root){
//    if(root==NULL)return true;
//    bool left=checkHt(root->left);
//    bool right= checkHt(root->right);
//    bool diff=abs(height(root->left)-height(root->right))<=0;
//    if(left && right && diff)return true;
//    else return false;
//}
//3 9 -1 -1 20 15 -1 -1 7 -1 -1
int main() {
    node *root=NULL;
    root = buildTree(root);
    cout<<checkHt(root);
    return 0;
}
