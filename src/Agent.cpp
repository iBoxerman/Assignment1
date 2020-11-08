#include "../include/Agent.h"
#include "../include/Session.h"

// simple constructor
Agent::Agent(Session& _session):session(_session){}

// destructor not maneging resources
Agent::~Agent(){
    // because we don't want the session to be deleted only the pointer
}

// copy constructor
 Agent::Agent(const Agent &other):session(other.session) {
}

// copy assignment operator
const Agent& Agent::operator=(const Agent &other) {
    session = other.session; // is this currently?
    return *this;
}

// move constructor

// move assignment operator

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

// Virus clone
Agent *Virus::clone() {
    Virus* cloned = new Virus(*this); // can be auto (recommended by Clion)
    return cloned;
}

// ContactTracer constructor overwrite
ContactTracer::ContactTracer(Session &session) : Agent(session) {}

// ContactTracer act
void ContactTracer::act() {
    // make a tree
    // remove edges according to tree type
}

// ContactTracer clone
Agent *ContactTracer::clone() {
    ContactTracer* cloned = new ContactTracer(*this); // can be auto (recommended by Clion)
    return cloned;
}

