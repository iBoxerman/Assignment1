#include "../include/Graph.h"

// simple constructor
Graph::Graph(std::vector<std::vector<int>> matrix):edges(matrix),infectedNodes(){
    // using copy constructor to make edges (not move)
    // initialize the infected nodes vector
    int vSize = edges.size();
    for(int i=0; i<vSize;i++){
        infectedNodes.at(i)=false;
    }
}

// destructor

// copy constructor

// copy assignment operator

// move constructor

// move assignment operator

const int Graph::getSize() const {
    return edges.size();
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