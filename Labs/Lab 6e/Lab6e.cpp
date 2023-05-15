//Andrew Card

#include <iostream>

using namespace std;

//Templated binary tree node
template <class T>
class Node{
    private:
        T data;

    public:
    
        Node<T>* left;
        Node<T>* right;

        Node(T _data){
            data = _data;
            left = nullptr;
            right = nullptr;
        }

        T getData(){
            return data;
        }

        Node<T>* getLeft(){
            return left;
        }

        Node<T>* getRight(){
            return right;
        }

        void setData(T _data){
            data = _data;
        }

        void setLeft(Node<T>* _left){
            left = _left;
        }

        void setRight(Node<T>* _right){
            right = _right;
        }
};

//Get successor
template <class T>
Node<T>* successor(Node<T>* node){
    Node<T>* current = node;
    while(current->getLeft() != nullptr){
        current = current->getLeft();
    }
    return current;
}

//Get predecessor
template <class T>
Node<T>* predecessor(Node<T>* node){
    Node<T>* current = node;
    while(current->getRight() != nullptr){
        current = current->getRight();
    }
    return current;
}

//Templated binary tree
template <class T>
class BinaryTree{
    private:
        Node<T>* root;
    public:
        BinaryTree(){
            root = nullptr;
        }

        void insert(T data){
            if(root == nullptr){
                root = new Node<T>(data);
            }else{
                insert(data, root);
            }
        }

        void insert(T data, Node<T>* node){
            if(data < node->getData()){
                if(node->getLeft() == nullptr){
                    node->setLeft(new Node<T>(data));
                }else{
                    insert(data, node->getLeft());
                }
            }else{
                if(node->getRight() == nullptr){
                    node->setRight(new Node<T>(data));
                }else{
                    insert(data, node->getRight());
                }
            }
        }

        void print(){
            print(root);
        }

        Node<T>* getRoot(){
            return root;
        }

        //Delete a node without breaking the tree
        Node<T>* deleteNode(Node<T>* root, T key) {
            if (root == NULL) return NULL;
            if (key > root -> getData()) root -> right = deleteNode(root -> right, key);
            else if (key < root -> getData()) root.left = deleteNode(root -> left, key);
            else {
                if (root -> left == NULL && root -> right == NULL) root = NULL;
                else if (root -> right != NULL) {
                root -> getData() = successor(root);
                root.right = deleteNode(root -> right, root -> getData());
                } else {
                root -> getData() = predecessor(root);
                root -> left = deleteNode(root -> left, root -> getData());
                }
            }
            return root;
        }

        Node<T>* find(T data){
            //Loop through the tree until we find the node
            Node<T>* current = root;

            while(current != nullptr){
                if(current->getData() == data){
                    return current;
                }else if(data < current->getData()){
                    current = current->getLeft();
                }else{
                    current = current->getRight();
                }
            }

            return current;

        }

        void print(Node<T>* node){
            if(node != nullptr){
                print(node->getLeft());
                cout << node->getData() << endl;
                print(node->getRight());
            }
        }
};

int main(){

    //system("CLS");

    BinaryTree<string> tree;

    tree.insert("Andrew");
    tree.insert("Bob");
    tree.insert("Ethan");
    tree.insert("Frank");
    tree.insert("Charlie");
    tree.insert("David");

    tree.print();

    tree.deleteNode(tree.find("Frank"), "Frank");

    cout << endl;
    cout << endl;

    tree.print();

    return 0;
}