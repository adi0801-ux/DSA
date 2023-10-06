//
// Created by Aditya Chauhan on 01/09/23.
//
//
// Created by Aditya Chauhan on 01/09/23.
//

#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node *left, *right;

    Node() {
        data = 0;
        left = nullptr;
        right = nullptr;
    }

    Node(int key) {
        data = key;
        left = nullptr;
        right = nullptr;
    }

    __attribute__((unused)) Node(int key, Node *left, Node *right) {
        data = key;
        this->left = left;
        this->right = right;
    }
};

Node *insertInBST(Node *head, int key) {
    if (head == nullptr) {
        return new Node(key);
    }

    if (key < head->data) {
        head->left = insertInBST(head->left, key);
    } else if (key > head->data) {
        head->right = insertInBST(head->right, key);
    }

    return head;
}

void inorder(Node *root, vector<int>&v){
    if(root==NULL){
        return;
    }
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right,v);
}






int main() {
    /* Let us create following BST
            50
         /      \
        30      70
     /    \    /   \
    20    40  60    80 */
    vector<int>v;
    Node *root = nullptr;
    root = insertInBST(root, 50);
    insertInBST(root, 30);
    insertInBST(root, 20);
    insertInBST(root, 40);
    insertInBST(root, 70);
    insertInBST(root, 60);
    insertInBST(root, 80);
    int k;
    cin>>k;

    inorder(root, v);
    cout<< v[k-1];
    return 0;
}