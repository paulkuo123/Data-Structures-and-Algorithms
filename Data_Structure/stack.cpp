#include <iostream>

using namespace std;

class Stack;

class Node{
    private:
        int value;
        Node *next;

    public:
        Node() : value(0), next(nullptr){};
        Node(int a) : value(a), next(nullptr){};

        friend class Stack;
};

class Stack{
    private:
        int length;
        Node* head;

    public:
        Stack(): head(nullptr), length(0){};
        void printAll();
        void pushBack(int x);
        void pop();
};

void Stack::printAll(){
    if (head == nullptr){
        cout << "Stack is empty." << endl;
    }
    else{
        Node* currentNode = head;
        while (currentNode != nullptr)
        {
            cout << currentNode->value << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }
}

void Stack::pushBack(int x){

    Node* newNode = new Node(x);

    if (head == nullptr){
        head = newNode;
    }
    else{
        Node* currentNode = head;
        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
    length++;
}

void Stack::pop(){
    if (length == 0){
        return;
    }
    else if (length == 1){
        head = nullptr;
        length = 0;
    }
    else{
        Node* currentNode = head;
        for(int i = 0; i < length-2; i++){
            currentNode = currentNode->next;
        }
        currentNode->next = nullptr;
        length--;
    }
}

int main()
{
    Stack myStack;
    myStack.pushBack(1);
    myStack.pushBack(0);
    myStack.pushBack(2);
    myStack.pushBack(5);
    myStack.pop();
    myStack.printAll();
    return 0;
}
