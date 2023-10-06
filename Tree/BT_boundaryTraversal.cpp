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

bool isLeaf(node* root){
    if(root->left ==NULL && root->right ==NULL)return true;
    else return false;
}
void addLeftBoundary(node* root, vector<int> &ans){
    node* cur= root->left;
    while(cur){
        if(!isLeaf(cur))ans.push_back(cur->data);
        if(cur->left)cur=cur->left;
        else cur=cur->right;
    }
}
void addLeaf(node *root, vector<int> &ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left) addLeaf(root->left, ans);
    if(root->right) addLeaf(root->right, ans);
}
void addRightBoundary(node *root, vector<int> &ans){
    node *cur= root->right;
    vector<int> temp;
    while(cur){
        if (!isLeaf(cur))temp.push_back(cur->data);
        if(cur->right)cur=cur->right;
        else cur=cur->left;
    }
    for(int i=temp.size()-1;i>=0;i--){
        ans.push_back(temp[i]);
    }
}

int main() {
    node *root=NULL;
    vector<int> ans;
    root = buildTree(root);
    cout<<"boundaryTraversal is:"<<endl;
    if(root==NULL)return -1;
    if(!isLeaf(root))ans.push_back(root->data);
    addLeftBoundary(root,ans );
    addLeaf(root, ans);
    addRightBoundary(root, ans);
    cout<<endl;
    for(int an : ans)cout<<an;
    return 0;
}

