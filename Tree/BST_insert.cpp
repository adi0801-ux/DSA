//
// Created by Aditya Chauhan on 28/08/23.
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

Node* insert(Node* root, int key){
    Node* cur=root;
    if(cur==NULL)new Node(key);
    while(cur){
        if(cur->data<key){
            if(cur->right!=NULL){
                cur=cur->right;
            }
            else{
                cur->right=new Node(key);
                break;
            }
        }
        else{
            if(cur->left!=NULL){
                cur=cur->left;
            }
            else{
                cur->left=new Node(key);
                break;
            }
        }
    }
    return root;
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

    cout<<insert(root, 61)->data;

    return 0;
}