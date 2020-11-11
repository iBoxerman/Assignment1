#ifndef TREE_H_
#define TREE_H_
#include <iostream>
#include <vector>

class Session;

class Tree{
public:
    Tree(int rootLabel); // simple constructor
    virtual ~Tree();// destructor
    Tree(const Tree &other); // copy constructor
    Tree(Tree &&other); // move constructor
    const Tree& operator=(const Tree &other);// copy assignment operator
    Tree& operator=(Tree &&other); // move assignment operator


    virtual Tree * clone() const = 0;
    virtual int traceTree()=0;
    void addChild(const Tree& child); // shit function
    void addChild(const Tree* child);
    const Tree& getChild(int) const;
    static Tree* createTree(const Session& session, int rootLabel);
    Tree * firstSon();
    static void BFS( Session& session , int i); // maybe static?
    const int childrenSize();
    const std::vector<Tree*> getChildren();
    const int depth();
    const int getRoot() const;
    void clear();
    void sort();

private:
    int node;
    std::vector<Tree*> children;
    static bool* visited;
};

class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);

    virtual Tree * clone() const;
    virtual int traceTree();
private:
    int currCycle;
};

class MaxRankTree: public Tree{
public:
    MaxRankTree(int rootLabel);

    virtual Tree * clone() const;
    virtual int traceTree();
};

class RootTree: public Tree{
public:
    RootTree(int rootLabel);

    virtual Tree * clone() const;
    virtual int traceTree();
};

#endif