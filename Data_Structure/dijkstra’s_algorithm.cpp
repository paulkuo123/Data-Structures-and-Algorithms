#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

//TODO:
class Edge;

class Node{
    public:
        string value;
        bool visited;
        vector<const Edge*> edges;
        int distanceFromStartNode;
        Node* previous;
        Node(string value):value(value), visited(false), distanceFromStartNode(numeric_limits<int>::max()), previous(nullptr){};
        void addEdges(const Edge &edge);
};

void Node::addEdges(const Edge &edge){
    edges.push_back(&edge);
}

class Edge{
    public:
        Node* node;
        int weight;
        Edge(Node* node, int weight):node(node), weight(weight){};
};

class MinHeap{
    public:
        vector<Node*> values;
        MinHeap(){};
        void enqueue(Node* value);
        Node* dequeue();
        void maxHeapify(int index);
};

void MinHeap::enqueue(Node* newNode){
    if (values.size() == 0){
        values.push_back(newNode);
    }
    else{
        values.push_back(newNode);
        int newIndex = values.size() - 1;
        int parentIndex = floor((newIndex - 1) / 2);
        while (parentIndex >= 0 && values[newIndex]->distanceFromStartNode < values[parentIndex]->distanceFromStartNode)
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

Node* MinHeap::dequeue(){
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

void MinHeap::maxHeapify(int i){
    int largest;
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if (l <= values.size() -1 && values[l]->distanceFromStartNode < values[i]->distanceFromStartNode){
        largest = l;
    }
    else{
        largest = i;
    }

    if (r <= values.size() - 1 && values[r]->distanceFromStartNode < values[largest]->distanceFromStartNode){
        largest = r;
    }

    if (largest != i){
        Node* temp = values[i];
        values[i] = values[largest];
        values[largest] = temp;
        maxHeapify(largest);
    }
}

void Dijkstra(Node allNodes[], Node* node){
    node->distanceFromStartNode = 0;
    node->visited = true;
    MinHeap MH = MinHeap();
    for (int i = 0; i < 6; i++){
        MH.enqueue(&allNodes[i]);
    }
    Node* currentNode = MH.dequeue();

    while (MH.values.size() > 0)
    {
        for(int i = 0; i < currentNode->edges.size(); i++){
            Node* neighborNode = currentNode->edges[i]->node;
            if (!neighborNode->visited){
                int d1 = neighborNode->distanceFromStartNode;
                int d2 = currentNode->distanceFromStartNode;
                int d3 = currentNode->edges[i]->weight;
                if (d1 > d2 + d3){
                    neighborNode->distanceFromStartNode = d2 + d3;
                    neighborNode->previous = currentNode;
                }
            }
        }
        currentNode = MH.dequeue();
    }
}

int main(){
    Node A("A");
    Node B("B");
    Node C("C");
    Node D("D");
    Node E("E");
    Node F("F");
    A.addEdges(Edge(&B, 2));
    A.addEdges(Edge(&B, 2));
    A.addEdges(Edge(&C, 2));
    B.addEdges(Edge(&A, 2));
    B.addEdges(Edge(&D, 1));
    B.addEdges(Edge(&E, 4));
    C.addEdges(Edge(&A, 2));
    C.addEdges(Edge(&D, 1));
    C.addEdges(Edge(&F, 2));
    D.addEdges(Edge(&B, 1));
    D.addEdges(Edge(&C, 1));
    D.addEdges(Edge(&E, 2));
    D.addEdges(Edge(&F, 3));
    E.addEdges(Edge(&B, 4));
    E.addEdges(Edge(&D, 2));
    E.addEdges(Edge(&F, 1));
    F.addEdges(Edge(&C, 2));
    F.addEdges(Edge(&D, 3));
    F.addEdges(Edge(&E, 1));

    Node allNodes[6] = {A, B, C, D, E, F};

    Dijkstra(allNodes, &A);
    cout << A.distanceFromStartNode << endl;
    cout << A.previous << endl;
    cout << B.distanceFromStartNode << endl;
    cout << B.previous << endl;
    return 0;
}
