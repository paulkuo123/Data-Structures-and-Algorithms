#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
//TODO:
class Node{
    public:
        string value;
        bool visited;
        vector<Edge> edges;
        Node(string value):value(value), visited(false){};
        void addNeighbor(Edge edge);
};

class Edge{
    private:
        Node node1;
        Node node2;
        int weight;
    public:
        Edge(Node node1, Node node2, int weight):node1(node1), node2(node2), weight(weight){};
};

void Node::addNeighbor(Edge edge){
    edges.push_back(edge);
}


class minimalSpanningTree
{
public:
    vector<Edge> bucket;
    minimalSpanningTree();
    void mstPrim(Node startNode);
    void getBestEdge();
};

void minimalSpanningTree::mstPrim(Node startNode){
    vector<Edge> mstEdges;
    for (int i = 0; i < startNode.edges.size(); i++){
        bucket.push_back(startNode.edges[i]);
    }
    getBestEdge();
}


void minimalSpanningTree::getBestEdge(){
    
}

int main(){
    Node A("A");
    Node B("B");
    Node C("C");
    Node D("D");
    Node E("E");
    Node F("F");
    Node allNodes[6] = {A, B, C, D, E, F};

    Edge e1(A, B, 10);
    A.addNeighbor(e1);
    B.addNeighbor(e1);
    Edge e2(A, C, 8);
    A.addNeighbor(e2);
    C.addNeighbor(e2);
    Edge e3(B, D, 6);
    B.addNeighbor(e3);
    D.addNeighbor(e3);
    Edge e4(C, D, 5);
    C.addNeighbor(e4);
    D.addNeighbor(e4);
    Edge e5(B, E, 7);
    B.addNeighbor(e5);
    E.addNeighbor(e5);
    Edge e6(D, E, 4);
    D.addNeighbor(e6);
    E.addNeighbor(e6);
    Edge e7(D, F, 3);
    D.addNeighbor(e7);
    F.addNeighbor(e7);
    Edge e8(E, F, 1);
    E.addNeighbor(e8);
    F.addNeighbor(e8);
    Edge e9(C, F, 8);
    C.addNeighbor(e9);
    F.addNeighbor(e9);

    return 0;
}