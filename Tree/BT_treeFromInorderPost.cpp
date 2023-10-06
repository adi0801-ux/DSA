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
node* solve( vector<int>inorder, vector<int> postorder, int &postIndex, int inorderStart, int inorderEnd, int n){

    if(postIndex<0 || inorderStart > inorderEnd){
        return NULL;
    }
    int element=postorder[postIndex];
    postIndex--;
    node* root=new node(element);
    int position=findPosition(inorder, element, n);
    root->right=solve(inorder, postorder, postIndex, position+1, inorderEnd, n);
    root->left=solve(inorder, postorder, postIndex, inorderStart, position-1, n);


    return root;

}
node* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n=postorder.size();
    int postorderIndex=n-1;
    node *ans=solve( inorder,postorder, postorderIndex, 0, n-1, n);
    return ans;
}
int main() {
    int n;
    cin>>n;
    vector<int>postorder;
    for(int i=0;i<n;i++){
        cin>>postorder[i];
    }
    vector<int>inorder;
    for(int i=0;i<n;i++){
        cin>>inorder[i];
    }
    buildTree(postorder, inorder);
    return 0;
}
