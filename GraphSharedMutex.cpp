//
// Created by naraujo on 20/08/17.
//

#include "GraphSharedMutex.hpp"

//Construtor
GraphSharedMutex::GraphSharedMutex() {

}

//Insert
bool GraphSharedMutex::insertNode() {

    structureMutex.lock();

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
    nodesMutex.push_back(shared_mutex_wrapper());

    structureMutex.unlock();


    return true;
}

bool GraphSharedMutex::insertEdge(int n1, int n2) {

    structureMutex.lock_shared();
    //Safety Checks
    if (n1 > edges.size() || n2 > edges[n1].size() || n1 < 0 || n2 < 0 || n1 == n2) {
        structureMutex.unlock_shared();
        return false;
    }
    structureMutex.unlock_shared();

    nodesMutex[n1].lock();
    nodesMutex[n2].lock();

    //Checks if already exists
    if (edges[n1][n2] > 0) {
        nodesMutex[n1].unlock();
        nodesMutex[n2].unlock();
        return false;
    }
    else {
        edges[n1][n2] = 1;
        nodesMutex[n1].unlock();
        nodesMutex[n2].unlock();
        return true;
    }
}

//Delete
bool GraphSharedMutex::deleteNode(int n) {

    structureMutex.lock_shared();
    if (n > nodes.size() || n < 0) {
        structureMutex.unlock_shared();
        return false;
    }
    structureMutex.unlock_shared();

    structureMutex.lock();
    nodesMutex[n].lock();

    //Delete Edges From Other Nodes
    for (int i = 0; i < edges.size(); i++){
        edges[i].erase(edges[i].begin() + n);
    }

    //Delete Whole Vector From Vector
    edges.erase(edges.begin() + n);

    //Delete Node
    nodes.erase(nodes.begin() + n);

    structureMutex.unlock();
    nodesMutex[n].unlock();

    nodesMutex.pop_back();

    return true;
}

bool GraphSharedMutex::deleteEdge(int n1, int n2) {
    //Safety Checks
    structureMutex.lock_shared();
    if (n1 > edges.size() || n2 > edges[n1].size() || n1 < 0 || n2 < 0 || n1 == n2) {
        structureMutex.unlock_shared();
        return false;
    }
    structureMutex.unlock_shared();

    nodesMutex[n1].lock();
    nodesMutex[n2].lock();

    if (edges[n1][n2] < 1) {
        nodesMutex[n1].unlock();
        nodesMutex[n2].unlock();
        return false;
    }

    edges[n1][n2] = 0;
    nodesMutex[n1].unlock();
    nodesMutex[n2].unlock();

    return true;
}

//Costs
bool GraphSharedMutex::increaseEdge(int n1, int n2) {
    //Safety Checks
    structureMutex.lock_shared();
    if (n1 > edges.size() || n2 > edges[n1].size() || n1 < 0 || n2 < 0 || n1 == n2) {
        structureMutex.unlock_shared();
        return false;
    }
    structureMutex.unlock_shared();

    nodesMutex[n1].lock();
    nodesMutex[n2].lock();

    //Cant insert
    if (edges[n1][n2] < 1) {
        nodesMutex[n1].unlock();
        nodesMutex[n2].unlock();
        return false;
    }
    else
        edges[n1][n2]++;

    nodesMutex[n1].unlock();
    nodesMutex[n2].unlock();
    return true;
}

bool GraphSharedMutex::decreaseEdge(int n1, int n2) {
    //Safety Checks
    structureMutex.lock_shared();
    if (n1 > edges.size() || n2 > edges[n1].size() || n1 < 0 || n2 < 0 || n1 == n2) {
        structureMutex.unlock_shared();
        return false;
    }
    structureMutex.unlock_shared();

    nodesMutex[n1].lock();
    nodesMutex[n2].lock();

    //Cant delete
    if (edges[n1][n2] <= 1) {
        nodesMutex[n1].unlock();
        nodesMutex[n2].unlock();
        return false;
    }

    edges[n1][n2]--;
    nodesMutex[n1].unlock();
    nodesMutex[n2].unlock();

    return true;
}

//Getters
bool GraphSharedMutex::getEdge(int n1, int n2, int& out){
    //Safety Checks
    structureMutex.lock_shared();
    if (n1 > edges.size() || n2 > edges[n1].size() || n1 < 0 || n2 < 0) {
        structureMutex.unlock_shared();
        return false;
    }
    structureMutex.unlock_shared();

    nodesMutex[n1].lock_shared();
    nodesMutex[n2].lock_shared();

    out = edges[n1][n2];

    nodesMutex[n1].unlock_shared();
    nodesMutex[n2].unlock_shared();

    return true;
}


bool GraphSharedMutex::getNode(int n, int& out){
    structureMutex.lock_shared();
    if (n > nodes.size() || n < 0) {
        structureMutex.unlock_shared();
        return false;
    }
    structureMutex.unlock_shared();

    nodesMutex[n].lock_shared();

    out = nodes[n];

    nodesMutex[n].unlock_shared();

    return true;
}


void GraphSharedMutex::printEdges() {

    structureMutex.lock_shared();

    std::cout << "Printing Edges..." << std::endl;
    std::cout << "-------------- START --------------" << std::endl;
    for (int i = 0; i < edges.size(); i++){
        nodesMutex[i].lock_shared();
        std::cout << "| ";
        for (int j = 0; j < edges[i].size(); j++) {
            if (i != j)
                nodesMutex[j].lock_shared();
            std::cout << "(" << edges[i][j] << ") | ";
            if (i != j)
                nodesMutex[j].unlock_shared();
        }
        std::cout << std::endl;
        nodesMutex[i].unlock_shared();
    }
    std::cout << "--------------- END ---------------" << std::endl;

    structureMutex.unlock_shared();
}

