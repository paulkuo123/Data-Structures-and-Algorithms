#include <iostream>

using namespace std;

class LinkedList;

class Node
{
private:
    int value;
    Node *next;

public:
    Node() : value(0), next(0){};
    Node(int a) : value(a), next(0){};

    friend class LinkedList;
};

class LiskedList
{
private:
    int size;
    Node* head;

public:
    LiskedList(): head(0){};
};

main()
{
    LiskedList list;
    return 0;
}
