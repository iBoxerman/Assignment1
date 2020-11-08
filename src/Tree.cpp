#include "../include/Tree.h"
#include "../include/Session.h"
#include "../include/Graph.h"
#include <iostream>
//#include <vector>

// simple constructor
Tree::Tree(int rootLabel):node(rootLabel),children() {
}

// destructor

// copy constructor

// copy assignment operator

// move constructor

// move assignment operator

// this function add a child to the tree
void Tree::addChild(const Tree &child) {
    if (child!= nullptr){
    }
}

const Tree& Tree::getChild(int) const {

}

// used to make trees
Tree *Tree::createTree(const Session &session, int rootLabel) {
    Tree curr_tree = new Tree(rootLabel);
    Graph graph = session.getGraph(); // copy assignment of graph

    if (session.getTreeType()==Cycle){

    }
    else if (session.getTreeType()==MaxRank){
        for (int i = 0; i<graph.getSize(); i++){
            if graph.areNeighbors(rootLabel,i){
                children.push_back(Tree(i))
            }
        }
        for (Tree* element:children){
            createTree(Session)
        }
    }
    else{

    }

    return nullptr;

}

void Tree::BFS(const Session& session,int i) {
    visited = new bool[session.g.getSize()] ; // initializing
    for (bool element : visited){
        element = false;
    }
    std::vector<int> queue; // initializing a queue
    visited[i] = true;
    queue.push_back(i);
    vector<int>::iterator iter;
    while(!queue.empty()){

    }
    delete [visited];
}

// CycleTree simple constructor
CycleTree::CycleTree(int _rootLabel, int _currCycle) : Tree(_rootLabel),currCycle(_currCycle){}

// this used by the ContactTracer
int CycleTree::traceTree() {
    return 0;
}

// MaxRankTree simple constructor
MaxRankTree::MaxRankTree(int _rootLabel) : Tree(_rootLabel) {}

// this used by the ContactTracer
int MaxRankTree::traceTree() {
    return 0;
}

// RootTree simple constructor
RootTree::RootTree(int _rootLabel) : Tree(_rootLabel) {}

// this used by the ContactTracer
int RootTree::traceTree() {
    return 0;
}
