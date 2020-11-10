#include <fstream>
#include <iostream>
#include <vector>
#include "../include/Session.h"
#include "../include/Agent.h"
#include "../include/Graph.h"

// empty test constructor
Session::Session() : g(), treeType(), agents(){
}

// simple constructor
Session::Session(const std::string &path) {
    std::ifstream reader(path);
    json jObject;
    reader>>jObject;
    g = jObject["Graph"];
    std::string sTreeType = jObject["tree"];
    // need to add agents!!
}

// destructor

// copy constructor

// copy assignment operator

// move constructor

// move assignment operator

// this function invoke the session
void Session::simulate() {
    while (true){
        currCycle++;
        int node = dequeueInfected();
        if (node==-1) // the queue is empty - "Game Over"
            break;
        else{
            // play
        }
    }
    // output to json
}

// this function adds an agent
void Session::addAgent(const Agent &agent) {
    Agent* cloned = agent.clone(); // making a copy of the agent
    agents.push_back(cloned); // inserting the agents to the 2d vector
    // possible to write addAgent(Virus(number))
}

void Session::setGraph(const Graph &graph) {
    g = graph;
}

Graph & Session::getGraph() const {
    return g ;
}


int Session::getGraphSize() const {
    return this->g.getSize();
}


void Session::enqueueInfected(int i) {
    queue.push_back(i);
}

int Session::dequeueInfected() {
    if (queue.empty()) {
        return -1;
    }
    else {
        return qPop();
    }
}
int Session::qPop() {
    int temp = queue.front();
    queue.erase(queue.begin());
    return temp;
}

// returns the TreeType Cycle/MaxRank/Root
TreeType Session::getTreeType() const {
    return treeType;
}



