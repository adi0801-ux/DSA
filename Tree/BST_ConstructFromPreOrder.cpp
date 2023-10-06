//
// Created by Aditya Chauhan on 04/09/23.
//
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





Node* buildTree(int &i, vector<int>preOrder, int ub){
    if(i>=preOrder.size() || preOrder[i]>ub)return NULL;
    Node* root=new Node(preOrder[i]);
    i++;
    root->left= buildTree(i, preOrder, root->data);
    root->right= buildTree(i, preOrder, ub);
    return root;
}
Node* buildFromPreOrder(vector<int>preOrder){
    int i=0;
    return buildTree(i, preOrder, INT_MAX);
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
    v={8,5,1,7,10,12};
    cout<<buildFromPreOrder(v);
    return 0;
}