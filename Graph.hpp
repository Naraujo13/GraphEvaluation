//
// Created by naraujo on 20/08/17.
//

#ifndef GRAPHEVALUATION_GRAPH_HPP
#define GRAPHEVALUATION_GRAPH_HPP

#include <vector>
#include <iostream>

class Graph{
public:
    std::vector<int> nodes;
    std::vector< std::vector<int> > edges;

public:
    //Constutor
    Graph();

    //Insert Methods
    bool insertNode();
    bool insertEdge(int n1, int n2);

    //Delete Methods
    bool deleteNode(int n);
    bool deleteEdge(int n1, int n2);

    //Costs Methods
    bool increaseEdge(int n1, int n2);
    bool decreaseEdge(int n1, int n2);

    //Acess Methods
    bool getNode(int n, int& out);
    bool getEdge(int n1, int n2, int& out);

    //Print
    void printEdges();

};

#endif //GRAPHEVALUATION_GRAPH_HPP
