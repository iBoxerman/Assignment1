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

    /*
    for (int i = 0; i<graph.getSize(); i++){
        if graph.areNeighbors(rootLabel,i){

        }
    */
    if (session.getTreeType()==Cycle){

    }
    else if (session.getTreeType()==MaxRank){

    }
    else{

    }

    return nullptr;

}

void Tree::BFS() {
    Tree* curr_tree = createTree(session, node);
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
