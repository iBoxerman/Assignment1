#include <fstream>
#include <iostream>
#include <vector>
#include "../include/Session.h"
#include "../include/Agent.h"
#include "../include/Graph.h"

/* notes for this class:
 * simple CTR
 * currCycle - not updated in CTR
*/

// simple constructor
Session::Session(const std::string &path):g(std::vector<std::vector<int>>()),agents(),treeType(),queue() {
 //   std::ifstream reader(path);
 //   json jObject;
 //   reader>>jObject;
 //   g = jObject["Graph"];
 //  std::string sTreeType = jObject["tree"];
    // need to add agents!!
}

// destructor
Session::~Session() {
    clear();
}

// copy constructor
Session::Session(const Session &other):g(other.g),agents(other.agents),treeType(other.treeType),queue(other.queue) {
    for(Agent* agent: other.agents){
        agents.push_back(agent); // can use addAgent nut it by reference
    }
}

// move constructor
Session::Session(Session &&other):g(other.g){ // not initializing fields here for convenient and clear method
    if(this!=&other){ // for the case x=x
        clear();
        g = other.g;
        agents = other.agents;
        treeType=other.treeType;
        queue= other.queue;
        const int size = other.agents.size(); // just for const size because other.agents is a vector
        for (int i =0 ; i<size; i++) {
            agents.push_back(other.agents.at(i)); // taking the pointer to my agents
            other.agents.at(i) = nullptr; // deleting the pointer from the other session
        }
    }
}

// copy assignment operator
const Session &Session::operator=(const Session &other) {
    if(this!=&other){ // for the case x=x
        clear(); // like delete
        g = other.g;
        agents = other.agents;
        treeType=other.treeType;
        queue= other.queue;
        for(Agent* agent : other.agents){
            addAgent(*agent->clone()); // not sure about the memory leaks here
        }
    }
    return *this; // returning a ptr is the main concept of operator=
}

// move assignment operator
Session &Session::operator=(Session &&other) {
    if(this!=&other){ // for the case x=x
        clear();

    }
    return *this; // returning a ptr is the main concept of operator=return <#initializer#>;
}
// this function invoke the session
void Session::simulate() {
    bool ended = false;
    while (!ended){
        currCycle++;
        for(auto agent : agents){
            agent->act(*this);
        }
        if (queue.empty()){
            ended=true;
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

Graph & Session::getGraph(){
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


void Session::clear() {
    for (Agent* agent : agents){
        delete agent;
    }
    agents.clear();
    queue.clear();
    // graph is deleted by ~Graph()
}
