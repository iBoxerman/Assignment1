#include "../include/Tree.h"
#include "../include/Session.h"
#include "../include/Graph.h"
#include <iostream>
//#include <vector>

// simple constructor
Tree::Tree(int rootLabel):node(rootLabel),children(), visited() {
}

// destructor

// copy constructor
Tree::Tree(const Tree &other):node(other.node),children(other.children),visited(other.visited) {

}

// copy assignment operator

// move constructor

// move assignment operator

// this function add a child to the tree
void Tree::addChild(const Tree &child) {
    //Tree other = *new Tree(child);
    //children.push_back(&other);

}

const Tree& Tree::getChild(int) const {

}

// used to make trees
Tree *Tree::createTree(const Session &session, int rootLabel) {
 /*   _session = session;
    Tree curr_tree = new Tree(rootLabel);
    Graph graph = session; // copy assignment of graph


    if (session.getTreeType()==Cycle){

    }
    else if (session.getTreeType()==MaxRank){
        for (int i = 0; i<graph.getSize(); i++){
            if (graph.areNeighbors(rootLabel,i)){
                children.push_back(Tree(i))
            }
        }
        for (Tree* element:children){
            createTree(Session)
        }
    }
    else{

    }

    return nullptr;*/

}

void Tree::BFS( Session& session,int i) {
    visited = new bool[session.getGraphSize()] ; // initializing
    for (int j = 0; j<session.getGraphSize(); j++){
        visited[j] = false;
    }
    std::vector<int> queue; // initializing a queue
    visited[i] = true; // visiting myself
    queue.push_back(i); // pushing myself into the queue

    while(!queue.empty()){
        int currInd = queue.front(); // pulling the first node on the queue
        queue.erase(queue.begin()); // deleting the first node
        Tree currTree = Tree(currInd);
        for (int k : session.getGraph().allNeighbors(currInd)){ // for each neighbor of curr
            if (!visited[k])
                visited[k]=true;
                queue.push_back(k);
                currTree.addChild(Tree(k));

            }

    }

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


