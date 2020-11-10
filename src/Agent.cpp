#include "../include/Agent.h"
#include "../include/Tree.h"

/*
// simple constructor
Agent::Agent(){}

// destructor not maneging resources
Agent::~Agent(){
    // because we don't want the session to be deleted only the pointer
}

// copy constructor
 Agent::Agent(const Agent &other) {
}

// copy assignment operator
const Agent& Agent::operator=(const Agent &other) {
    session = other.session; // is this currently?
    return *this;
}

// move constructor

// move assignment operator
*/

// Virus simple constructor
Virus::Virus(int _nodeInd):nodeInd(_nodeInd){}

// Virus act
void Virus::act( Session& session) {
    bool infectedSomeone = false;
    while (!infectedSomeone){
        for(int k : session.getGraph().allNeighbors(nodeInd)){
            if(!(session.getGraph().isInfected(k))){
                session.getGraph().infectNode(k); // infects the node on the graph
                session.addAgent(Virus(k)); // duplicating the Virus
                session.enqueueInfected(k); // maintaining the queue
                infectedSomeone = true; // exit the loop
            }
        }
    }
}

// Virus clone
Agent *Virus::clone() const{
    Virus* cloned = new Virus(*this); // can be auto (recommended by Clion)
    return cloned;
}

// ContactTracer constructor overwrite
ContactTracer::ContactTracer() {}

// ContactTracer act
void ContactTracer::act(Session& session) {
    Graph newGraph = session.getGraph();
    int node = session.dequeueInfected();
    if (node!= -1){
        Tree* tree = Tree::createTree(session,node);
        tree->BFS(session,node);
        int nodeToCut = tree->traceTree();
        newGraph.removeEdges(nodeToCut);
        session.setGraph(newGraph);
    }
}

// ContactTracer clone
Agent *ContactTracer::clone() const{
    ContactTracer* cloned = new ContactTracer(*this); // can be auto (recommended by Clion)
    return cloned;
}

