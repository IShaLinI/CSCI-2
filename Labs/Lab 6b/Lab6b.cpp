//Andrew Card

#include <iostream>
#include <stack>

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

//Print the tree recursively
void printTreeRecursive(BSTNode* root){
    if(root == NULL){
        return;
    }
    printTreeRecursive(root->left);
    cout << root->data << " ";
    printTreeRecursive(root->right);
}

//Print the tree iteratively
void printTreeIterative(BSTNode* root){
    stack<BSTNode*> s;
    BSTNode* current = root;
    while(current != NULL || !s.empty()){
        while(current != NULL){
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->data << " ";
        current = current->right;
    }
}

int main(){

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

    //Print the tree
    cout << "Recursive: ";
    printTreeRecursive(root);
    cout << endl;
    cout << "Iterative: ";
    printTreeIterative(root);

    return 0;
}