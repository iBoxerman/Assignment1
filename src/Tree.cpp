#include "../include/Tree.h"
#include "../include/Session.h"
#include "../include/Graph.h"
#include <iostream>
#include <vector>

// simple constructor
Tree::Tree(int rootLabel):node(rootLabel),children() {
}

// destructor

// copy constructor
Tree::Tree(const Tree &other):node(other.node),children(other.children) {

}

// copy assignment operator

// move constructor

// move assignment operator

// this function add a child to the tree - not used. using by pointer.
void Tree::addChild(const Tree &child) {
}

// using this method
void Tree::addChild(const Tree *child) {
    Tree* other = child->clone();
    children.push_back(other);
}


const Tree& Tree::getChild(int) const {

}

// used to make trees
Tree *Tree::createTree(const Session &session, int rootLabel) {
    Tree* tree;
    if (session.getTreeType()==Cycle){
        tree = new CycleTree(rootLabel,session.currCycle);
    }
    else if (session.getTreeType()==MaxRank){ // checks my which son has maximum size;
        tree = new MaxRankTree(rootLabel);
    }
    else{
        tree = new RootTree(rootLabel);
    }
    return tree;
}

// a getter for the first child (the left-most son!)
Tree *Tree::firstSon() {
    if(!children.empty())
        return children.front();
    else return nullptr;
}

void Tree::BFS(const Session& session,int myNode) {
    visited = new bool[session.getGraphSize()] ; // initializing
    for (int j = 0; j<session.getGraphSize(); j++){
        visited[j] = false;
    }
    std::vector<int> queue; // initializing a queue
    visited[myNode] = true; // visiting myself
    queue.push_back(myNode); // pushing myself into the queue
    Tree* currTree = createTree(session,myNode);

    while(!queue.empty()){
        int currInd = queue.front(); // pulling the first node on the queue
        queue.erase(queue.begin()); // deleting the first node
        for (int k : session.getGraph().allNeighbors(currInd)){ // for each neighbor of curr
            if (!visited[k])
                visited[k]=true;
                queue.push_back(k);
                Tree* newChild = createTree(session,k);
                currTree->addChild(*newChild);
                currTree=newChild;
            }
    }
}

// get the children vector size
const int Tree::childrenSize() {
    return children.size();
}

// getter for children vector
const std::vector<Tree *> Tree::getChildren() {
    return children;
}


// need correction!!!!!    wrong !!!
const int Tree::depth() {
    int maxRank=0;
    int x=0;
    for (Tree* child:children){
        x=0;
        if (child != nullptr)
            x=1+child->depth();
        else{
          if (x>maxRank){
              maxRank=x;
          }
        }
    }
    return maxRank;
}

// a getter for the root
const int Tree::getRoot() const {
    return node;
}

// CycleTree simple constructor
CycleTree::CycleTree(int _rootLabel, int _currCycle) : Tree(_rootLabel),currCycle(_currCycle){} // notice that session has (public) currCycle

// cloning the CycleTree
Tree *CycleTree::clone() const{
    Tree* cloned = new CycleTree(getRoot(),currCycle);
    return cloned;
}

// this used by the ContactTracer
int CycleTree::traceTree() {
    int counter = currCycle;
    Tree* currTree = this->firstSon();
    while (currTree != nullptr & counter>0){
        currTree = currTree->firstSon();
        counter--;
    }
    return currTree->getRoot();
}

// MaxRankTree simple constructor
MaxRankTree::MaxRankTree(int _rootLabel) : Tree(_rootLabel) {}

// cloning the MaxRankTree
Tree *MaxRankTree::clone() const {
    Tree* cloned = new MaxRankTree(getRoot());
    return cloned;
}

// this used by the ContactTracer
int MaxRankTree::traceTree() {
    Tree* maxTree;
    Tree* currTree = this;
    for (Tree* child: currTree->getChildren()){
        if (child->childrenSize()>maxTree->childrenSize()){ // if a child has more children than maxTree, he is the maxTree
            maxTree = child;
        }
        currTree = child;
    }
    return maxTree->getRoot(); // returns the root label so we know what node to remove
}

// RootTree simple constructor
RootTree::RootTree(int _rootLabel) : Tree(_rootLabel) {}

// cloning the RootTree
Tree *RootTree::clone() const {
    Tree* cloned = new RootTree(getRoot());
    return cloned;
}

// this used by the ContactTracer
int RootTree::traceTree() {
    return getRoot();
}

