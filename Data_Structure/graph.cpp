#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<string> result;

class Node{
    public:
        string value;
        vector<Node*> neighbors;
        bool visited;
        Node(string value):value(value), visited(false){};
        void addNeighbor(Node &neighbor);
};

void Node::addNeighbor(Node &neighbor){
    neighbors.push_back(&neighbor);
}

void DFT(Node* starter){
    starter->visited = true;
    result.push_back(starter->value);
    cout << starter->value << " ";
    for (int i = 0; i < starter->neighbors.size(); i++){
        if (!starter->neighbors[i]->visited){
            DFT(starter->neighbors[i]);
        }
    }
}

void BFT(Node &starter){
    queue<Node*> queue;
    queue.push(&starter);
    while (!queue.empty())
    {
        Node* firstNode = queue.front();
        queue.pop();
        if (!firstNode->visited){
            firstNode->visited = true;
            result.push_back(firstNode->value);
            cout << firstNode->value << " ";
            for(int i = 0; i < firstNode->neighbors.size(); i++){
                if (!firstNode->neighbors[i]->visited){
                    queue.push(firstNode->neighbors[i]);
                }
            }
        }
    }
}

int main()
{
    Node A("A");
    Node B("B");
    Node C("C");
    Node D("D");
    Node E("E");
    Node F("F");
    Node G("G");
    Node H("H");
    Node I("I");
    Node J("J");
    Node K("K");
    Node L("L");
    Node M("M");
    A.addNeighbor(E);
    A.addNeighbor(F);
    B.addNeighbor(D);
    C.addNeighbor(D);
    D.addNeighbor(B);
    D.addNeighbor(C);
    D.addNeighbor(E);
    D.addNeighbor(I);
    E.addNeighbor(A);
    E.addNeighbor(D);
    E.addNeighbor(F);
    E.addNeighbor(I);
    F.addNeighbor(A);
    F.addNeighbor(E);
    F.addNeighbor(I);
    G.addNeighbor(H);
    G.addNeighbor(I);
    H.addNeighbor(G);
    H.addNeighbor(I);
    H.addNeighbor(L);
    I.addNeighbor(D);
    I.addNeighbor(E);
    I.addNeighbor(F);
    I.addNeighbor(G);
    I.addNeighbor(H);
    I.addNeighbor(J);
    I.addNeighbor(K);
    I.addNeighbor(M);
    J.addNeighbor(I);
    J.addNeighbor(M);
    K.addNeighbor(I);
    K.addNeighbor(L);
    K.addNeighbor(M);
    L.addNeighbor(H);
    L.addNeighbor(K);
    M.addNeighbor(I);
    M.addNeighbor(J);
    M.addNeighbor(K);

    BFT(A);
    return 0;
}
