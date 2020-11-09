#include "../include/Graph.h"
#include <vector>

// simple constructor
Graph::Graph(std::vector< std::vector<int> > matrix):edges(matrix),infectedNodes(){
    // using copy constructor to make edges (not move)
    // initialize the infected nodes vector
    int vSize = edges.size();
    for(int i=0; i<vSize;i++){
        infectedNodes.at(i)=false;
    }
}

// destructor
Graph::~Graph() {
    if (edges & infectedNodes){
        delete [edges];
        delete [infectedNodes];
    }
}

// copy constructor
Graph::Graph(const Graph &other){
    edges = other.edges;
    infectedNodes = other.infectedNodes;
}

// copy assignment operator

// move constructor

// move assignment operator

// return the nodes number by checking the vector size
const int Graph::getSize() const {
    return edges.size();
}

bool Graph::areNeighbors(int i, int j) {
    return (edges.at(i).at(j)==1);
}

std::vector<int> Graph::allNeighbors(int i) {
    std::vector<int> myNeighbors;
    for (int j=0; j<getSize(); j++){
        if (areNeighbors(i,j)){
            myNeighbors.push_back(j);
        }
    }
    return myNeighbors;
}

// this function infects a node
void Graph::infectNode(int nodeInd) {
    if (!isInfected(nodeInd)){
        infectedNodes.at(nodeInd)=true;
    }
    // push at session?
}

// this function checks if the given node is infected
bool Graph::isInfected(int nodeInd) {
    return infectedNodes.at(nodeInd);
}
