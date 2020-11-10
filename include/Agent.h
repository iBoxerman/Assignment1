#ifndef AGENT_H_
#define AGENT_H_
#include <iostream>
#include <vector>
#include "Session.h"

class Agent{
public:
   /*
    Agent();
    virtual ~Agent();
    Agent(const Agent &other);
    const Agent& operator=(const Agent &other);
    */

    virtual Agent * clone() const =0;
    virtual void act(Session& session)=0;
};

class Virus: public Agent{
public:
    Virus(int nodeInd);

    virtual void act(Session& session);
    virtual Agent * clone() const;
private:
    const int nodeInd;
};

class ContactTracer: public Agent{
public:
    ContactTracer();

    virtual void act(Session& session);
    virtual Agent * clone() const;
};

#endif