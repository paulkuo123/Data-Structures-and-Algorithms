#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Node{
    private:
        string value;
        int priority;
    public:
        Node():value(""), priority(0){};
        Node(string value, int priority):value(value), priority(priority){};

        friend class PriorityQueue;
};

class PriorityQueue{
    private:
        void maxHeapify(int index);
    public:
        vector<Node*> values;
        PriorityQueue():values(0){};
        void enqueue(string value, int priority);
        Node* dequeue();
        void printAll();
};

void PriorityQueue::enqueue(string value, int priority){
    Node* newNode = new Node(value, priority);
    if (values.size() == 0){
        values.push_back(newNode);
    }
    else{
        values.push_back(newNode);
        int newIndex = values.size() - 1;
        int parentIndex = floor((newIndex - 1) / 2);
        while (parentIndex >= 0 && values[newIndex]->priority > values[parentIndex]->priority)
        {
            //swap
            Node* temp = values[parentIndex];
            values[parentIndex] = values[newIndex];
            values[newIndex] = temp;

            newIndex = parentIndex;
            parentIndex = floor((newIndex - 1) / 2);
        }
    }
}

Node* PriorityQueue::dequeue(){
    if (values.size() == 0){
        return nullptr;
    }
    else if (values.size() == 1){
        Node* removeNode = values[0];
        values.pop_back();
        return removeNode;
    }
    else{
        //swap two nodes
        Node* temp = values.back();
        values.pop_back();
        values.push_back(values[0]);
        values[0] = temp;
        Node* removeNode = values.back();
        values.pop_back();

        maxHeapify(0);
        return removeNode;
    }
}

void PriorityQueue::maxHeapify(int i){
    int largest;
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if (l <= values.size() -1 && values[l]->priority > values[i]->priority){
        largest = l;
    }
    else{
        largest = i;
    }

    if (r <= values.size() - 1 && values[r]->priority > values[largest]->priority){
        largest = r;
    }

    if (largest != i){
        Node* temp = values[i];
        values[i] = values[largest];
        values[largest] = temp;
        maxHeapify(largest);
    }
}

void PriorityQueue::printAll(){
    while (!this->values.empty())
    {
        Node* result = dequeue();
        cout << result->value << endl;
    }
}

int main(){
    PriorityQueue pq = PriorityQueue();
    pq.enqueue("123", 1);
    pq.enqueue("321", 3);
    pq.enqueue("456", 102);
    pq.enqueue("100", 1003);
    Node* result = pq.dequeue();
    pq.printAll();
    return 0;
}
