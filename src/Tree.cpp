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

// this function add a child to the tree
void Tree::addChild(const Tree &child) {
    Tree* other = child.clone();
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

Tree *Tree::firstSon() {
    if(!children.empty())
    return children.front();
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

// get the tree size, by recursive method // needed the biggest children size
const int Tree::childrenSize() {
    return children.size();
}

const std::vector<Tree *> Tree::getChildren() {
    return children;
}


// need correction!!!!!    wrong !!!
const int Tree::depth() {
    int maxRank;
    int x=0;
    for (auto child:children){
        x=0;
        if (child != nullptr)
            x=x+1;
        else{
          if (x>maxRank){
              maxRank=x;
          }
        }
    }
    return maxRank;
}

const int Tree::getRoot() const {
    return node;
}

// CycleTree simple constructor
CycleTree::CycleTree(int _rootLabel, int _currCycle) : Tree(_rootLabel),currCycle(_currCycle){

}

Tree *CycleTree::clone(){
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
MaxRankTree::MaxRankTree(int _rootLabel) : Tree(_rootLabel) {


}


Tree *MaxRankTree::clone() {
    Tree* cloned = new MaxRankTree(getRoot());
    return cloned;
}

// this used by the ContactTracer
int MaxRankTree::traceTree() {
    int max= childrenSize();
    Tree* maxTree;
    for (Tree* child: getChildren()){
        if (child->childrenSize()>max){
            max = child->childrenSize();

        }
    }

}

// RootTree simple constructor
RootTree::RootTree(int _rootLabel) : Tree(_rootLabel) {}

Tree *RootTree::clone() {
    Tree* cloned = new RootTree(getRoot());
    return cloned;
}

// this used by the ContactTracer
int RootTree::traceTree() {
    return 0;
}

