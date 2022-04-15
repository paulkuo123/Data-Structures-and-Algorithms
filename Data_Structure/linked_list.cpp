#include <iostream>

using namespace std;

class LinkedList;

class Node{
    private:
        int value;
        Node *next;

    public:
        Node() : value(0), next(nullptr){};
        Node(int a) : value(a), next(nullptr){};

        friend class LinkedList;
};

class LinkedList{
    private:
        int length;
        Node* head;

    public:
        LinkedList(): head(nullptr), length(0){};
        void printList();
        void pushBack(int x);
        void pop();
        void shift();
        void unshift(int x);
        void insertAt(int index, int value);
        void removeAt(int index);
        int get(int index);
};

void LinkedList::printList(){
    if (head == nullptr){
        cout << "List is empty." << endl;
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

void LinkedList::pushBack(int x){

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

void LinkedList::pop(){
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

void LinkedList::shift(){
    if (length == 0){
        return;
    }
    else if (length == 1){
        head = nullptr;
        length = 0;
    }
    else{
        head = head->next;
        length--;
    }
}

void LinkedList::unshift(int x){
    if (length == 0){
        head = new Node(x);
    }
    else{
        Node* temp = head; 
        Node* newNode = new Node(x);
        head = newNode;
        head->next = temp;
    }
    length++;
}

void LinkedList::insertAt(int index, int value){
    if (index > length - 1 || index < 0){
        return;
    }
    else if (index == 0){
        LinkedList::unshift(value);
    }
    else if (index == length - 1)
    {
        LinkedList::pushBack(value);
    }
    else{
        Node* currentNode = head;
        Node* newNode = new Node(value);
        for (int i = 1; i <= index - 1; i++){
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
        length++;
    }
}

void LinkedList::removeAt(int index){
    if (index > length -1 || index < 0){
        return;
    }
    else if (index == 0){
        LinkedList::shift();
    }
    else if (index == length - 1)
    {
        LinkedList::pop();
    }
    else{
        Node* currentNode = head;
        for (int i = 1; i <= index-1; i++){
            currentNode = currentNode->next;
        }
        currentNode->next = currentNode->next->next;
    }
    length--;
}

int LinkedList::get(int index){
    if (index > length -1 || index < 0){
        return -1;
    }
    Node* currentNode = head;
    for (int i = 0; i < index; i++){
        currentNode = currentNode->next;
    }
    return currentNode->value;
}

main()
{
    int a = -1;
    LinkedList list;
    list.pushBack(1);
    list.pushBack(0);
    list.pushBack(2);
    list.pushBack(5);
    list.printList();
    return 0;
}
