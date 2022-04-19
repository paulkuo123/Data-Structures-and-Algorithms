#include <iostream>
#include <queue>

using namespace std;

class Node{
    private:
        int key;
        Node* left;
        Node* right;

    public:
    Node(int key):key(key), left(0), right(0){};
    friend class BinarySearchTree;
};

class BinarySearchTree{
    public:
        Node* root;
        BinarySearchTree():root(nullptr){};
        void treeInsert(int z);
        void preOrder(Node *n);
        void inOrder(Node *n);
        void postOrder(Node *n);
        void bftt(Node *n);
};

void BinarySearchTree::treeInsert(int z){
    Node* y = nullptr;
    Node* x = this->root;
    Node* newNode = new Node(z);
    while (x != NULL)
    {
        y = x;
        if (newNode->key < x->key){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }
    if (y == nullptr){
        this->root = newNode;
    }
    else if (newNode->key < y->key){
        y->left = newNode;
    }
    else{
        y->right = newNode;
    }
}

void BinarySearchTree::preOrder(Node* n){
    if (n){
        cout << n->key << " ";
        preOrder(n->left);
        preOrder(n->right);
    }
}

void BinarySearchTree::inOrder(Node* n){
    if (n){
        inOrder(n->left);
        cout << n->key << " ";
        inOrder(n->right);
    }
}

void BinarySearchTree::postOrder(Node* n){
    if (n){
        postOrder(n->left);
        postOrder(n->right);
        cout << n->key << " ";
    }
}

void BinarySearchTree::bftt(Node* n){
    if (n){
        queue<Node*> q;
        q.push(n);
        while (!q.empty())
        {       
            Node* currentNode = q.front();
            q.pop();
            cout << currentNode->key << " ";
            if (currentNode){
                if (currentNode->left){
                    q.push(currentNode->left);
                }
                if (currentNode->right){
                    q.push(currentNode->right);
                }
            }
        }
    }
}

int main(){
    BinarySearchTree bst;
    bst.treeInsert(15);
    bst.treeInsert(6);
    bst.treeInsert(5);
    bst.treeInsert(1);
    bst.treeInsert(13);
    bst.treeInsert(-7);
    bst.treeInsert(3);
    bst.bftt(bst.root);
    return 0;
}
