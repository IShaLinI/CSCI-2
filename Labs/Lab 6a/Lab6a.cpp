//Andrew Card

#include <iostream>

using namespace std;

//Binary Search Tree Node
struct BSTNode{
    int data;
    BSTNode* left;
    BSTNode* right;
};

//Create a node
BSTNode* createNode(int data){
    BSTNode* newNode = new BSTNode;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Print the tree
void printTree(BSTNode* root){
    if(root == NULL){
        return;
    }
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

int main(){

    //Hard Code a tree

    //Create the root
    BSTNode* root = createNode(8);

    //Create the left subtree
    root->left = createNode(3);
    root->left->left = createNode(1);
    root->left->right = createNode(6);

    //Create the right subtree
    root->right = createNode(10);
    root->right->right = createNode(14);
    root->right->right->left = createNode(13);

    //Print the tree`
    printTree(root);

    return 0;
}