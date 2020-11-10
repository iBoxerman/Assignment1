#include "../include/Tree.h"
#include "../include/Session.h"
#include "../include/Graph.h"
#include <iostream>
#include <vector>

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
    Tree* other = new Tree(child.node);
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
    BFS(session,rootLabel);
    return tree;
}

Tree *Tree::firstSon() {
    if(!children.empty())
    return children.front();
}

void Tree::BFS(const Session& session,int i) {
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

// get the tree size, by recursive method
const int Tree::treeSize() {
    int x;
    for (auto child:children){
        if (child == nullptr)
            x=+1;
        else x=+child->treeSize();
    }
    return x;
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

// CycleTree simple constructor
CycleTree::CycleTree(int _rootLabel, int _currCycle) : Tree(_rootLabel),currCycle(_currCycle){

}

// this used by the ContactTracer
int CycleTree::traceTree() {
    return 0;
}

// MaxRankTree simple constructor
MaxRankTree::MaxRankTree(int _rootLabel) : Tree(_rootLabel) {
   /*
   int max=0;
    Tree* maxTree;
    for (Tree* child: children){
        if (child.treeSize()>max){
            maxTree = child;
            max= child.treeSize();
        } else if(child.treeSize()=max){
            if (child->depth()> maxTree->depth()){
                maxTree = child;
            }
        }
    }
    return maxTree;
    */

}

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


