#ifndef AGENT_H_
#define AGENT_H_
#include <iostream>
#include <vector>
#include "Session.h"

class Agent{
public:
    Agent(Session& session);
    virtual ~Agent();

    virtual Agent* clone()=0;
    virtual void act()=0;

protected:
    Session& session;
};

class ContactTracer: public Agent{
public:
    ContactTracer(Session& session);

    virtual void act();
};


class Virus: public Agent{
public:
    Virus(int nodeInd, Session& session);

    virtual void act();
private:
    const int nodeInd;
};

#endif