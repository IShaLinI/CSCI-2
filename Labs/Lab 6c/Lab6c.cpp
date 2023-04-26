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

//Delete Node
void deleteNode(BSTNode* node){
    delete node;
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


//Search Tree For a Value and give the address
BSTNode* searchTree(BSTNode* root, int value){
    if(root == NULL){
        return NULL;
    }
    if(root->data == value){
        return root;
    }
    if(root->data > value){
        return searchTree(root->left, value);
    }
    else{
        return searchTree(root->right, value);
    }
}

int main(){

    system("CLS");

    //Create the root
    BSTNode* root = createNode(8);

    //Create the left subtree
    root->left = createNode(3);
    root->left->left = createNode(1);
    root->left->right = createNode(6);
    root->left->right->left = createNode(4);
    root->left->right->right = createNode(7);

    //Create the right subtree
    root->right = createNode(10);
    root->right->right = createNode(14);
    root->right->right->left = createNode(13);

    //Print the tree
    cout << "Table: ";
    printTreeIterative(root);

    //Search the tree for 7
    BSTNode* found = searchTree(root, 7);

    if(found == NULL){
        cout << "\nNot Found" << endl;
    }
    else{
        cout << "\nFound: " << found->data << " at: " << &found->data << endl;
    }

    //Delete the found node
    delete found;

    //Print the tree
    cout << "Table: ";
    printTreeIterative(root);

    return 0;
}