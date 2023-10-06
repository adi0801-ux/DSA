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

Node* findRight(Node* root){
    if(root->right==NULL)return root;
    return findRight(root->right);
}
Node* helper(Node* root){
    if(root->left==NULL)return root->right;
    if(root->right==NULL)return root->left;
    Node* rightChild = root->right;
    Node* lastRight = findRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

Node* deleteNode(Node* root, int key) {
    if(root==NULL)return root;
    if(root->data==key){
        return helper(root);
    }
    Node* dummy=root;
    while(root!=NULL){
        if(root->data>key){
            if(root->left!=NULL && root->left->data==key){
                root->left=helper(root->left);
                break;
            }
            else{
                root=root->left;
            }
        }
        else{
            if(root->right!=NULL && root->right->data==key){
                root->right=helper(root->right);
                break;
            }
            else{
                root=root->right;
            }
        }
    }
    return dummy;
}


int main() {
    /* Let us create following BST
            50
         /      \
        30      70
     /    \    /   \
    20    40  60    80 */

    Node *root = nullptr;
    root = insertInBST(root, 50);
    insertInBST(root, 30);
    insertInBST(root, 20);
    insertInBST(root, 40);
    insertInBST(root, 70);
    insertInBST(root, 60);
    insertInBST(root, 80);

    cout<<deleteNode(root, 40);
    return 0;
}