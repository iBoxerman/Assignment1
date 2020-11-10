#ifndef GRAPH_H_
#define GRAPH_H_
#include <iostream>
#include <vector>
#include "Session.h"
//using namespace std;
class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);
    virtual ~Graph();
    Graph(const Graph &other);

    const int getSize() const;
    bool areNeighbors(int i, int j);
    std::vector<int> allNeighbors(int i);
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
    void removeEdges(int i);

private:
    std::vector< std::vector<int> > edges;
    std::vector<bool> infectedNodes;
};

#endif
