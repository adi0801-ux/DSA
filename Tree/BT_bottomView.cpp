//
// Created by Aditya Chauhan on 18/08/23.
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

vector<int> bottomView(node *root, vector<int>&ans){
    if(root==NULL)return ans;
    map<int, int>mpp;
    queue<pair<node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        node* frontNode = it.first;
        int hd = it.second;
        mpp[hd]=frontNode->data;
        if(frontNode->left)q.push({frontNode->left, hd-1});
        if(frontNode->right)q.push({frontNode->right, hd+1});
    }
    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;
}
//1 3 -1 -1 5 -1 -1
int main() {
    node *root=NULL;
    vector<int>ans;
    root = buildTree(root);
    bottomView(root, ans);
    for(auto it:ans)cout<<it<<" ";
    return 0;
}
1 2 3 4 null,5,6,null,null,7