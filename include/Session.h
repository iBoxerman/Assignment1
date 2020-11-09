#ifndef SESSION_H_
#define SESSION_H_

#include <iostream>
#include <string>
#include "Graph.h"

class Agent;

enum TreeType{
  Cycle,
  MaxRank,
  Root
};

class Session{
public:
    Session();
    Session(const std::string& path);
    
    void simulate();
    void addAgent(const Agent& agent);
    void setGraph(const Graph& graph);
    Graph & getGraph() const;
    int getGraphSize() const;
    void enqueueInfected(int);
    int dequeueInfected();
    int qPop();
    TreeType getTreeType() const;
    int currCycle;
    
private:
    Graph g;
    TreeType treeType;
    std::vector<Agent*> agents;
    std::vector<int> queue;
};

#endif