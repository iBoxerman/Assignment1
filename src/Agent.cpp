#include "../include/Agent.h"
#include "../include/Session.h"

// simple constructor
Agent::Agent(Session& _session):session(_session){}

// destructor not maneging resources
virtual Agent::~Agent(){
    session = nullptr; // because we don't want the session to be deleted only the pointer
}

// copy constructor
const Agent::Agent(const Agent &other) {
    session = other.session; // it is not the exactly the definition of copy constructor but it will do the work
}

// copy assignment operatorSS
const Agent& Agent::operator=(const Agent &other) {
    session = other.session // is this currently?
    return *this;
}

// move constructor

// move assignment operator

// clone
virtual Agent* Agent::clone(){
    Agent cloned = this;
    return *cloned; // is this right?
}

// Virus simple constructor
Virus::Virus(int _nodeInd, Session& _session):nodeInd(_nodeInd),Agent(_session){}

// Virus act
void Virus::act() {
    bool infectedSomeone = false;
    int i =0; // need to start from 0 or nodeInd?
    for(i; !infectedSomeone && i<this->session.getGraph().getSize();i++){
        if ( (this->session.getGraph().areNeighbors(nodeInd, i)) && (!(this->session.getGraph().isInfected(i))) ){
                infectedSomeone = true; // exit the loop
        }
    }
    if (!infectedSomeone){
        this->session.getGraph().infectNode(i); // infects the node on the graph
        this->session.addAgent(Virus(i)); // adding the Virus for the
        // maintaining the queue
        this->session.enqueueInfected(i);
    }
        this->session.dequeueInfected(nodeInd);
}


// ContactTracer constructor overwrite
ContactTracer::ContactTracer(Session &session) : Agent(session) {}

// ContactTracer act
void ContactTracer::act() {
    // make a tree
    // remove edges according to tree type
}

