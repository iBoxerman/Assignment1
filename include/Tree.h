#ifndef TREE_H_
#define TREE_H_
#include <iostream>
#include <vector>

class Session;

class Tree{
public:
    Tree(int rootLabel);
    Tree(const Tree &other);

    virtual Tree * clone()=0;
    virtual int traceTree()=0;
    void addChild(const Tree& child);
    const Tree& getChild(int) const;
    static Tree* createTree(const Session& session, int rootLabel);
    Tree * firstSon();
    static void BFS(const Session& session , int i); // maybe static?
    const int childrenSize();
    const std::vector<Tree*> getChildren();
    const int depth();
    const int getRoot() const;

private:
    int node;
    std::vector<Tree*> children;
    static bool* visited;
};

class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);

    virtual Tree * clone();
    virtual int traceTree();
private:
    int currCycle;
};

class MaxRankTree: public Tree{
public:
    MaxRankTree(int rootLabel);

    virtual Tree * clone();
    virtual int traceTree();
};

class RootTree: public Tree{
public:
    RootTree(int rootLabel);

    virtual Tree * clone();
    virtual int traceTree();
};

#endif