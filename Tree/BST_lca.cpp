//
// Created by Aditya Chauhan on 01/09/23.
//
//
// Created by Aditya
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



int lowestCommonAncestor(Node* root, int p, int q) {
    if(!root) return NULL;
    int curr = root->data;
    if(curr < p && curr < q) {
        return lowestCommonAncestor(root->right, p, q);
    }
    if(curr > p && curr > q) {
        return lowestCommonAncestor(root->left, p, q);
    }
    return root->data;
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
    cout<<lowestCommonAncestor(root,30, 50 );
    return 0;
}
