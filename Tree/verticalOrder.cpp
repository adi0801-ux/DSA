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
void verticalOrder(node *root)
{
    //Your code here
    vector<int>ans;
    map<int, map<int, vector<int>>> mp;
    queue<pair<node*, pair<int, int>>> q;
    q.push(make_pair(root, make_pair(0,0)));
    while(!q.empty()){
        pair<node*, pair<int,int> > temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;
        mp[hd][lvl].push_back(frontNode->data);
        if(frontNode->left)q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
        if(frontNode->right)q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
    }
    for(auto i:mp){
        for(auto j:i.second ){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }
    for(auto it:ans)cout<<it;
}

int main() {
    node *root=NULL;
    root = buildTree(root);
    verticalOrder(root);
    return 0;
}

