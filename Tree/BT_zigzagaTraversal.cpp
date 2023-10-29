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

vector<int> zigzag(node* root){
    vector<int> ans;
    vector<int>res;
    queue<node*> q;
    q.push(root);
    bool leftToRight=true;
            while(!q.empty()){
                int size=q.size();
                for(int i=1;i<size;i++){
                auto frontNode = q.front();
                int index;
                if(leftToRight) {
                    index = i;
                }
                else{
                    index=size-i-1;
                }
                ans[index]=frontNode->data;
                if(frontNode->left)q.push(frontNode->left);
                if(frontNode->right)q.push(frontNode->right);
                leftToRight=!leftToRight;
                }
                for(auto it:ans){
                    res.push_back(it);
                }
            }
            for(int re : res)
                cout<<re;
            return res;
}
//vector <int> zigZagTraversal(Node* root){
//    vector<int> res;
//    bool leftToRight=true;
//    queue<Node*> q;
//    if(root==NULL)return res;
//    q.push(root);
//    while(!q.empty()){
//        int size= q.size();
//        vector<int> ans(size);
//        for(int i=0;i<size;i++){
//            int index;
//
//            Node* frontNode = q.front();
//            q.pop();
//            if(leftToRight==true) index=i;
//            else if(leftToRight==false)index = size-i-1;
//            ans[index]=frontNode->data;
//            if(frontNode->left)q.push(frontNode->left);
//            if(frontNode->right)q.push(frontNode->right);
//
//        }
//        //change direction
//        leftToRight =!leftToRight;
//        for(int i=0;i<ans.size();i++){
//            res.push_back(ans[i]);
//        }
//    }
//    return res;
//    // Code here
//}
int main() {
    node *root=NULL;
    root = buildTree(root);
    zigzag(root);
    return 0;
}
