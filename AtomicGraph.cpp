//
// Created by naraujo on 20/08/17.
//

#include "AtomicGraph.hpp"

std::mutex deletionMutex;

AtomicGraph::AtomicGraph(){

}

//Insert
bool AtomicGraph::insertNode() {

    //Creates Edges for New Node
    std::vector<atomwrapper<int>> newNodeEdges;
    std::atomic<int> initialize;
    initialize = 0;
    std::atomic<int> one;
    one = 1;
    for (int i = 0; i < nodes.size(); i++){
        edges[i].push_back(initialize);
        newNodeEdges.push_back(initialize);
    }
    newNodeEdges.push_back(one);

    //Insert Node
    nodes.push_back(1);
    edges.push_back(newNodeEdges);

    return true;
}

bool AtomicGraph::insertEdge(int n1, int n2) {

    //Safety Checks
    if (n1 > edges.size() || n2 > edges[n1].size())
        return false;

    //Checks if already exists
    if (edges[n1][n2]._a > 0)
        return false;
    else {
        edges[n1][n2]._a = 1;
        return true;
    }
}

//Delete
bool AtomicGraph::deleteNode(int n) {

    if (n > nodes.size() || n < 0)
        return false;

    deletionMutex.lock();

    //Delete Edges From Other Nodes
    for (int i = 0; i < edges.size(); i++){
        edges[i].erase(edges[i].begin() + n);
    }

    //Delete Whole Vector From Vector
    edges.erase(edges.begin() + n);

    //Delete Node
    nodes.erase(nodes.begin() + n);

    deletionMutex.unlock();

    return true;
}

bool AtomicGraph::deleteEdge(int n1, int n2) {

    //Safety Checks
    if (n1 > edges.size() || n2 > edges[n1].size() || n1 < 0 || n2 < 0)
        return false;

    deletionMutex.lock();

    edges[n1][n2]._a = 0;

    deletionMutex.unlock();

    return true;
}

//Costs
bool AtomicGraph::increaseEdge(int n1, int n2) {

    //Safety Checks
    if (n1 > edges.size() || n2 > edges[n1].size() || n1 < 0 || n2 < 0)
        return false;

    //Cant insert
    if (edges[n1][n2]._a < 1)
        return false;
    else
        edges[n1][n2]._a.operator++();

    return true;
}

bool AtomicGraph::decreaseEdge(int n1, int n2) {
    //Safety Checks
    if (n1 > edges.size() || n2 > edges[n1].size() || n1 < 0 || n2 < 0)
        return false;

    //Cant delete
    if (edges[n1][n2]._a <= 1)
        return false;

    edges[n1][n2]._a.operator--();

    return true;
}

//Getters
bool AtomicGraph::getEdge(int n1, int n2, int& out){
    //Safety Checks
    if (n1 > edges.size() || n2 > edges[n1].size() || n1 < 0 || n2 < 0)
        return false;

    out = edges[n1][n2]._a;

    return true;
}


bool AtomicGraph::getNode(int n, int& out){
    if (n > nodes.size() || n < 0)
        return false;

    out = nodes[n];

    return true;
}