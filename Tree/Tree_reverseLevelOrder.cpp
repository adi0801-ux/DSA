//
// Created by Aditya Chauhan on 25/10/23.
//
//
// Created by Aditya Chauhan on 15/08/23.
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
node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}
vector<vector<int>> levelOrderBottom(node* root) {
    queue<node*> q;
    if(!root)return {{-1}};
    q.push(root);
    vector<vector<int>>v;
    while(!q.empty()) {
        int n=q.size();
        vector<int> v1(n);
        for(int i=0;i<n;i++){
            node* temp = q.front();
            q.pop();
            v1[i]=temp->data;
            if(temp ->left) {
                q.push(temp ->left);
            }
            if(temp ->right) {
                q.push(temp ->right);
            }
        }
        v.push_back(v1);
    }
    reverse(v.begin(), v.end());
    return v;
}

int main() {
    node *root=NULL;
    root = buildTree(root);
    vector<vector<int>>res = levelOrderBottom(root);
    for (const std::vector<int>& row : res) {
        // Iterate through the inner vector (row)
        for (int value : row) {
            std::cout << value << ' ';
        }
        std::cout << std::endl; // Start a new line for each row
    }

    return 0;
}
