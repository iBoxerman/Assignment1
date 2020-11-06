#include <fstream>
#include <iostream>
#include "../include/Session.h"

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

}

// this function adds an agent
void Session::addAgent(const Agent &agent) {

}

void Session::setGraph(const Graph &graph) {
    g = graph;
}

const Graph& Session::getGraph() const {
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







