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
    bool ended = false;
    while (!ended){
        // ended = has no one to infect / all infected
        // agents act by order
        break;
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

 Graph& Session::getGraph()  {
    return &g;
}

void Session::enqueueInfected(int) {

}

int Session::dequeueInfected() {
    return 0;
}

// returns the TreeType Cycle/MaxRank/Root
TreeType Session::getTreeType() {
    return treeType;
}







