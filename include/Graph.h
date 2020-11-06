#ifndef GRAPH_H_
#define GRAPH_H_
#include <iostream>
#include <vector>
#include "Session.h"

class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);
    virtual ~Graph();

    const getSize() const;
    bool areNeighbors(int i, int j);
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
private:
    std::vector<std::vector<int>> edges;
    std::vector<bool> infectedNodes;
};

#endif
//test
