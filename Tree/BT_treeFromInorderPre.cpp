//
// Created by Aditya Chauhan on 26/08/23.
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
int findPosition(vector<int> inorder, int element, int n){
    for(int i=0;i<n;i++){
        if(inorder[i]==element)
            return i;
    }
    return -1;
}
node* solve( vector<int>inorder, vector<int> preorder, int &preIndex, int inorderStart, int inorderEnd, int n){

    if(preIndex>=n || inorderStart > inorderEnd){
        return NULL;
    }
    int element=preorder[preIndex];
    preIndex++;
    node* root=new node(element);
    int position=findPosition(inorder, element, n);

    root->left=solve(inorder, preorder, preIndex, inorderStart, position-1, n);
    root->right=solve(inorder, preorder, preIndex, position+1, inorderEnd, n);

    return root;

}
node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n=preorder.size();
    int preorderIndex=0;
    node *ans=solve( inorder,preorder, preorderIndex, 0, n-1, n);
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int>preorder;
    for(int i=0;i<n;i++){
        cin>>preorder[i];
    }
    vector<int>inorder;
    for(int i=0;i<n;i++){
        cin>>inorder[i];
    }
    buildTree(preorder, inorder);
    return 0;
}
