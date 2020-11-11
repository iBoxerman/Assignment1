#include "../include/Graph.h"
#include <vector>

// simple constructor
Graph::Graph(std::vector< std::vector<int> > matrix):edges(matrix),infectedNodes(std::vector<bool>()){
    // using copy constructor to make edges (not move)
    // initialize the infected nodes vector
    int vSize = edges.size();
    for(int i=0; i<vSize;i++){
        infectedNodes.push_back(false);
    }
}

// destructor
Graph::~Graph() {
    if (!edges.empty()){
        for(auto p : edges){
            p.clear();
        }
    }
    if(!infectedNodes.empty()){
        infectedNodes.clear();
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
    return (edges.at(i).at(j)==1 | edges.at(j).at(i)==1) ;
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
}

// this function checks if the given node is infected
bool Graph::isInfected(int nodeInd) {
    return infectedNodes.at(nodeInd);
}

void Graph::removeEdges(int i) {
    for (int j : allNeighbors(i)){
        edges.at(i).at(j) = 0;
        edges.at(j).at(i) = 0;
    }
}


