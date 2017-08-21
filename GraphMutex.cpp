//
// Created by naraujo on 20/08/17.
//

#include "GraphMutex.hpp"

//Construtor
GraphMutex::GraphMutex() {

}

//Insert
bool GraphMutex::insertNode() {

    std::lock_guard<std::mutex>structureGuard(structureMutex);

    //Creates Edges for New Node
    std::vector<int> newNodeEdges;
    for (int i = 0; i < nodes.size(); i++){
        edges[i].push_back(0);
        newNodeEdges.push_back(0);
    }
    newNodeEdges.push_back(1);

    //Insert Node
    nodes.push_back(1);
    edges.push_back(newNodeEdges);

    return true;
}

bool GraphMutex::insertEdge(int n1, int n2) {

    structureMutex.lock();
    //Safety Checks
    if (n1 > edges.size() || n2 > edges[n1].size())
        return false;
    structureMutex.unlock();

    std::lock_guard<std::mutex>n1Guard(nodesMutex[n1]);
    std::lock_guard<std::mutex>n2Guard(nodesMutex[n2]);

    //Checks if already exists
    if (edges[n1][n2] > 0)
        return false;
    else {
        edges[n1][n2] = 1;
        return true;
    }
}

//Delete
bool GraphMutex::deleteNode(int n) {

    structureMutex.lock();
    if (n > nodes.size() || n < 0)
        return false;
    structureMutex.unlock();

    std::lock_guard<std::mutex>structureGuard(structureMutex);
    std::lock_guard<std::mutex>nodeGuard(nodesMutex[n]);

    //Delete Edges From Other Nodes
    for (int i = 0; i < edges.size(); i++){
        edges[i].erase(edges[i].begin() + n);
    }

    //Delete Whole Vector From Vector
    edges.erase(edges.begin() + n);

    //Delete Node
    nodes.erase(nodes.begin() + n);

    return true;
}

bool GraphMutex::deleteEdge(int n1, int n2) {
    //Safety Checks
    structureMutex.lock();
    if (n1 > edges.size() || n2 > edges[n1].size() || n1 < 0 || n2 < 0 || n1 == n2)
        return false;
    structureMutex.unlock();

    std::lock_guard<std::mutex>n1Guard(nodesMutex[n1]);
    std::lock_guard<std::mutex>n2Guard(nodesMutex[n2]);

    if (edges[n1][n2] < 1)
        return false;

    edges[n1][n2] = 0;

    return true;
}

//Costs
bool GraphMutex::increaseEdge(int n1, int n2) {
    //Safety Checks
    structureMutex.lock();
    if (n1 > edges.size() || n2 > edges[n1].size() || n1 < 0 || n2 < 0 || n1 == n2)
        return false;
    structureMutex.unlock();

    std::lock_guard<std::mutex>n1Guard(nodesMutex[n1]);
    std::lock_guard<std::mutex>n2Guard(nodesMutex[n2]);

    //Cant insert
    if (edges[n1][n2] < 1)
        return false;
    else
        edges[n1][n2]++;

    return true;
}

bool GraphMutex::decreaseEdge(int n1, int n2) {
    //Safety Checks
    structureMutex.lock();
    if (n1 > edges.size() || n2 > edges[n1].size() || n1 < 0 || n2 < 0 || n1 == n2)
        return false;
    structureMutex.unlock();

    std::lock_guard<std::mutex>n1Guard(nodesMutex[n1]);
    std::lock_guard<std::mutex>n2Guard(nodesMutex[n2]);

    //Cant delete
    if (edges[n1][n2] <= 1)
        return false;

    edges[n1][n2]--;

    return true;
}

//Getters
bool GraphMutex::getEdge(int n1, int n2, int& out){
    //Safety Checks
    structureMutex.lock();
    if (n1 > edges.size() || n2 > edges[n1].size() || n1 < 0 || n2 < 0)
        return false;
    structureMutex.unlock();

    std::lock_guard<std::mutex>n1Guard(nodesMutex[n1]);
    std::lock_guard<std::mutex>n2Guard(nodesMutex[n2]);

    out = edges[n1][n2];

    return true;
}


bool GraphMutex::getNode(int n, int& out){
    structureMutex.lock();
    if (n > nodes.size() || n < 0)
        return false;
    structureMutex.unlock();

    std::lock_guard<std::mutex>nodeGuard(nodesMutex[n]);

    out = nodes[n];

    return true;
}

