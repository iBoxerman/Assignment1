#include "../include/Agent.h"
#include "../include/Session.h"

// simple constructor
Agent::Agent(Session& _session):session(_session){}

// destructor

// copy constructor

// copy assignment operatorSS

// move constructor

// move assignment operator

// Virus simple constructor
Virus::Virus(int _nodeInd, Session& _session):nodeInd(_nodeInd),Agent(_session){}

// Virus act
void Virus::act() {

}


// ContactTracer constructor overwrite
ContactTracer::ContactTracer(Session &session) : Agent(session) {}

// ContactTracer act
void ContactTracer::act() {

}

