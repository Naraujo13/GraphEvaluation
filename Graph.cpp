//
// Created by naraujo on 20/08/17.
//

#include "Graph.hpp"

Graph::Graph(){

}

//Insert
bool Graph::insertNode() {

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

bool Graph::insertEdge(int n1, int n2) {

    //Safety Checks
    if (n1 > edges.size() || n2 > edges[n1].size())
        return false;

    //Checks if already exists
    if (edges[n1][n2] > 0)
        return false;
    else {
        edges[n1][n2] = 1;
        return true;
    }
}

//Delete
bool Graph::deleteNode(int n) {

    if (n > nodes.size() || n < 0)
        return false;

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

bool Graph::deleteEdge(int n1, int n2) {
    //Safety Checks
    if (n1 > edges.size() || n2 > edges[n1].size() || n1 < 0 || n2 < 0)
        return false;

    edges[n1][n2] = 0;

    return true;
}

//Costs
bool Graph::increaseEdge(int n1, int n2) {
    //Safety Checks
    if (n1 > edges.size() || n2 > edges[n1].size() || n1 < 0 || n2 < 0)
        return false;

    //Cant insert
    if (edges[n1][n2] < 1)
        return false;
    else
        edges[n1][n2]++;

    return true;
}

bool Graph::decreaseEdge(int n1, int n2) {
    //Safety Checks
    if (n1 > edges.size() || n2 > edges[n1].size() || n1 < 0 || n2 < 0)
        return false;

    //Cant delete
    if (edges[n1][n2] <= 1)
        return false;

    edges[n1][n2]--;

    return true;
}

//Getters
bool Graph::getEdge(int n1, int n2, int& out){
    //Safety Checks
    if (n1 > edges.size() || n2 > edges[n1].size() || n1 < 0 || n2 < 0)
        return false;

    out = edges[n1][n2];

    return true;
}


bool Graph::getNode(int n, int& out){
    if (n > nodes.size() || n < 0)
        return false;

    out = nodes[n];

    return true;
}