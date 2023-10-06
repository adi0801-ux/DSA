//
// Created by Aditya Chauhan on 25/08/23.
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
bool isSameTree(node* p, node* q) {
    if(p==NULL && q==NULL)return true;
    if(p!=NULL && q==NULL)return false;
    if(p==NULL && q!=NULL)return false;

    bool left=isSameTree(p->left,q->left);
    bool right=isSameTree(p->right,q->right);
    bool val;
    if(p->data==q->data)val=true;
    else val=false;
    if(left && right && val)return true;
    else return false;
}
int main() {
    node *root1=NULL;
    node* root2=NULL;
    root1 = buildTree(root1);
    root2 = buildTree(root2);
    cout<<isSameTree(root1,root2);
    return 0;
}
