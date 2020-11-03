#include "../include/Graph.h"

// simple constructor
Graph::Graph(std::vector<std::vector<int>> matrix):edges(matrix),infectedNodes(){
    // initialize
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

// this function infects a node
void Graph::infectNode(int nodeInd) {
    if (!isInfected(nodeInd)){
        infectedNodes.at(nodeInd)=true;
    }
}

// this function checks if the given node is infected
bool Graph::isInfected(int nodeInd) {
    return infectedNodes.at(nodeInd);
}