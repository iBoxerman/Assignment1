#ifndef TREE_H_
#define TREE_H_
#include <iostream>
#include <vector>

class Session;

class Tree{
public:
    Tree(int rootLabel);
    Tree(const Tree &other);

    void addChild(const Tree& child);
    const Tree& getChild(int) const;
    static Tree* createTree(const Session& session, int rootLabel);
   // virtual int traceTree()=0;
    void BFS( Session& session ,int i); // maybe static?

private:
    int node;
    std::vector<Tree*> children;
    bool* visited;
};

class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);

    virtual int traceTree();
private:
    int currCycle;
};

class MaxRankTree: public Tree{
public:
    MaxRankTree(int rootLabel);

    virtual int traceTree();
};

class RootTree: public Tree{
public:
    RootTree(int rootLabel);

    virtual int traceTree();
};

#endif