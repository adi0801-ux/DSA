//
// Created by Aditya Chauhan on 25/10/23.
//
#include <bits/stdc++.h>
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

//1 5 -1 4 9 -1 -1  2 -1 -1 3 10 -1 -1 6 -1 -1
node* nodeParentMap(node *root, int target, map<node*, node*>&mp){
    queue<node*>q;
    node*res=NULL;
    q.push(root);
    mp[root]=NULL;
    while(!q.empty()){
        node* node=q.front();
        q.pop();
        if(node->data==target){
            res=node;
        }
        if(node->left){
            mp[node->left]=node;
            q.push(node->left);
        }
        if(node->right){
            mp[node->right]=node;
            q.push(node->right);
        }
    }
    return res;
}
int burnTime(node*root,  map<node*, node*>mp){
    map<node*,bool>vis;
    queue<node*>q;
    q.push(root);
    int ans=0;
    vis[root]=1;
    while(!q.empty()){
        bool flag=0;
        int size=q.size();
        for(int i =0;i<size;i++){
            auto front=q.front();
            q.pop();
            if(front->left && !vis[front->left]){
                flag=1;
                q.push(front->left);
                vis[front->left]=1;
            }
            if(front->right &&!vis[front->right]){
                flag=1;
                q.push(front->right);
                vis[front->right]=1;
            }
            if(mp[front] &&!vis[mp[front]]){
                flag=1;
                q.push(mp[front]);
                vis[mp[front]]=1;
            }
        }
        if(flag==1){
            ans++;
        }
    }
    return ans;
}
void minTime(node* root, int target){
    map< node*,  node*>mp;
    node*res=nodeParentMap(root, target, mp);
    int ans=burnTime(res, mp);
    cout<<ans;
}
int main(){
    node *root=NULL;
    root = buildTree(root);
    cout<<"Enter the target node:";
    int target;
    cin>>target;
    minTime(root, target);
    return 0;
}