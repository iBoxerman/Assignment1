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
    Session(const std::string& path); // simple constructor
    virtual ~Session();// destructor
    Session(const Session &other); // copy constructor
    Session(Session &&other); // move constructor
    const Session& operator=(const Session &other);// copy assignment operator
    Session& operator=(Session &&other); // move assignment operator
    
    void simulate();
    void addAgent(const Agent& agent);
    void setGraph(const Graph& graph);
    Graph & getGraph() ;
    int getGraphSize() const;
    void enqueueInfected(int);
    int dequeueInfected();
    int qPop();
    TreeType getTreeType() const;
    int currCycle;
    void clear();

private:
    Graph g;
    TreeType treeType;
    std::vector<Agent*> agents;
    std::vector<int> queue;
};

#endif