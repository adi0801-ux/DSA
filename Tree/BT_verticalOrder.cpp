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
vector<vector<int>>verticalOrder(node *root)
{
    //Your code here
   map<int,map<int, multiset<int>>>nodes;
            //{verticalDist,{level, node}}
   queue<pair<node*, pair<int, int>>>q;
   q.push({root,{0,0}});
   while(!q.empty()){
       auto p=q.front();
       q.pop();
       node* Node=p.first;
       int x=p.second.first;
       int y=p.second.second;
       nodes[x][y].insert(Node->data);
       if(Node->left)q.push({Node->left,{x-1, y+1}});
       if(Node->right)q.push({Node->right,{x+1, y+1}});
   }
   vector<vector<int>>ans;
   for(auto it:nodes){
       vector<int>temp;
       for(auto i:it.second){
           temp.insert(temp.end(), i.second.begin(), i.second.end());
       }
       ans.push_back(temp);
   }
   return ans;
}

int main() {
    node *root=NULL;
    root = buildTree(root);
    vector<vector<int>>res=verticalOrder(root);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout<<res[i][j]<<" ";
        }
    }
    return 0;
}

