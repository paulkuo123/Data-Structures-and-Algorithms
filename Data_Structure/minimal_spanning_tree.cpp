#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
//TODO:

vector<Edge*> bucket;
class Node{
    public:
        string value;
        bool visited;
        vector<Edge*> edges;
        Node(string value):value(value), visited(false){};
        void addNeighbor(Edge* edge);
};

class Edge{
    private:
        Node* node1;
        Node* node2;
        int weight;
    public:
        Edge(Node* node1, Node* node2, int weight):node1(node1), node2(node2), weight(weight){};
};

void Node::addNeighbor(Edge* edge){
    edges.push_back(edge);
}

void mstPrim(Node* startNode){
    vector<Edge*> mstEdges;
    for (int i = 0; i < startNode->edges.size(); i++){
        bucket.push_back(startNode->edges[i]);
    }
    getBestEdge();
}


void getBestEdge(){
    Edge* bestEdge = nullptr;
    while (bestEdge == nullptr && bucket.size() != 0)
    {
        bestEdge = bucket[0];
        int index = 0;
        
    }
    
}

int main(){
    Node* A = new Node("A");
    Node* B = new Node("B");
    Node* C = new Node("C");
    Node* D = new Node("D");
    Node* E = new Node("E");
    Node* F = new Node("F");
    Node* allNodes[6] = {A, B, C, D, E, F};

    Edge* e1 = new Edge(A, B, 10);
    A->addNeighbor(e1);
    B->addNeighbor(e1);
    Edge* e2 = new Edge(A, C, 8);
    A->addNeighbor(e2);
    C->addNeighbor(e2);
    Edge* e3 = new Edge(B, D, 6);
    B->addNeighbor(e3);
    D->addNeighbor(e3);
    Edge* e4 = new Edge(C, D, 5);
    C->addNeighbor(e4);
    D->addNeighbor(e4);
    Edge* e5 = new Edge(B, E, 7);
    B->addNeighbor(e5);
    E->addNeighbor(e5);
    Edge* e6 = new Edge(D, E, 4);
    D->addNeighbor(e6);
    E->addNeighbor(e6);
    Edge* e7 = new Edge(D, F, 3);
    D->addNeighbor(e7);
    F->addNeighbor(e7);
    Edge* e8 = new Edge(E, F, 1);
    E->addNeighbor(e8);
    F->addNeighbor(e8);
    Edge* e9 = new Edge(C, F, 8);
    C->addNeighbor(e9);
    F->addNeighbor(e9);

    return 0;
}