#include "../include/Tree.h"
#include "../include/Session.h"
#include <vector>

/* notes for this class:
 * move endless loop
 * if sort then BFS
*/

// simple constructor
Tree::Tree(int rootLabel):node(rootLabel),children() {
}

// destructor
Tree::~Tree() {
    clear();
}

// copy constructor
Tree::Tree(const Tree &other):node(other.node),children(other.children) { // need to think if other.children.size() is needed
    for(Tree* child : other.children){ // deep copy because we want the children to be copied
        addChild(child); // addChild uses clone() which makes a copy of the child
    }
}

// move constructor
Tree::Tree(Tree &&other){ // not initializing fields here for convenient and clear method
    if(this!=&other){ // for the case x=x
        clear();
        node=other.node;
        visited = other.visited;
        children = other.children;
        const int size = other.childrenSize(); // just for const size because other.children is a vector
        for (int i =0 ; i<size; i++) {
            children.push_back(other.children.at(i)); // taking the pointer to my children
            other.children.at(i) = nullptr; // deleting the pointer from the other tree
        }
    }
}

// copy assignment operator
const Tree &Tree::operator=(const Tree &other) {
    if(this!=&other){ // for the case x=x
        clear(); // like delete
        node=other.node;
        for(Tree* child : other.children){
            addChild(child);
        }
    }
    return *this; // returning a ptr is the main concept of operator=
}

// move assignment operator
Tree &Tree::operator=(Tree &&other) {
    if(this!=&other){ // for the case x=x
        clear();
        node=other.node;
        children = other.children;
        int size = other.childrenSize();
        for(int i =0 ; i<size; i++){
            children.push_back(other.children.at(i));// taking the pointer to my children
            other.children.at(i) = nullptr; // deleting the pointer from the other tree
        }
    }
    return *this; // returning a ptr is the main concept of operator=return <#initializer#>;
}

// adds a child to the tree - not used, using by pointer.
void Tree::addChild(const Tree &child) {
}

// adds a child to the tree - used
void Tree::addChild(const Tree *child) {
    Tree* other = child->clone();
    children.push_back(other);
}

// returns the child with a specific node
const Tree& Tree::getChild(int i) const {
    for(Tree* child :children){
        if(child->getRoot()==i){
            return *child;
        }
    }
    return *(this->clone()); // Error!! just for exiting the function!
}

// returns a ptr to a new tree that was made according to session's tree type
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

// a getter for the first child (left-most son!)
Tree *Tree::firstSon() {
    if(!children.empty())
        return children.front();
    else return nullptr;
}

void Tree::BFS( Session& session,int myNode) {
    visited = new bool[session.getGraphSize()] ; // initializing
    for (int j = 0; j<session.getGraphSize(); j++){
        visited[j] = false;
    }
    std::vector<int> queue; // initializing a queue
    visited[myNode] = true; // visiting myself
    queue.push_back(myNode); // pushing myself into the queue
    Tree* currTree = createTree(session,myNode); // making a *new* tree!!

    while(!queue.empty()){
        int currInd = queue.front(); // pulling the first node on the queue
        queue.erase(queue.begin()); // deleting the first node
        for (int k : session.getGraph().allNeighbors(currInd)){ // for each neighbor of curr
            if (!visited[k])
                visited[k]=true;
                queue.push_back(k);
                Tree* newChild = createTree(session,k); // making a *new* tree!!
                currTree->addChild(*newChild);
                // need to sort !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
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

// clear and delete all fields
void Tree::clear() {
    for (auto child: children){
        if (child!= nullptr){
            delete [] child;
        }
    }
    delete [] visited;
    node = -1; // making sure that no one will do something to the node
}

// sorting the children !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! need to be done
void Tree::sort() {
    if (!children.empty()){
        int pos = 0;
        int size = childrenSize();
        for(int i=1; i<size; i++){
            if (children[pos]>children[i]){
                Tree* temp = children[i];
                children[i] = children[pos];
                children[pos] = temp;
                delete temp;

            }
        }
    }

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
int MaxRankTree::traceTree() {    // !!!!!!!!!!!!!!!!!!!!! not completed !!!!!!!!!!!!!!!!!
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






