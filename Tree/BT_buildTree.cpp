//
// Created by Aditya Chauhan on 25/10/23.
//
#include <iostream>
using namespace std;
class node{
public:
    int data;
    node*left;
    node *right;
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
node* buildTree(node *root){
    cout<<"Enter the data:";
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1)return NULL;
    cout<<"Enter the left data of:"<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the right data of:"<<data<<endl;
    root->right=buildTree(root->right);
    return root;

}
int main(){
    node *root=NULL;
    root = buildTree(root);
    return 0;
}