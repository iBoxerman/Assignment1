#include "../include/Session.h"

// empty test constructor
Session::Session() : g({{0,1,1,0,1},
                        {1,0,0,1,0},
                        {1,0,0,0,1},
                        {0,1,0,0,0},
                        {1,0,1,0,0}}), treeType(MaxRank), agents(){
    addAgent({"V",0}); // what is an agent?
    addAgent({"C",-1});
}

// simple constructor
Session::Session(const std::string &path) {

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

void Session::enqueueInfected(int) {

}

int Session::dequeueInfected() {
    return 0;
}

// returns the TreeType Cycle/MaxRank/Root
TreeType Session::getTreeType() {
    return treeType;
}







