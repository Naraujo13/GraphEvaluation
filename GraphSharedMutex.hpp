//
// Created by naraujo on 20/08/17.
//

#ifndef GRAPHEVALUATION_GRAPHSHAREDMUTEX_HPP
#define GRAPHEVALUATION_GRAPHSHAREDMUTEX_HPP

#include "Graph.hpp"
#include <thread>
#include <mutex>
#include <shared_mutex>

class GraphSharedMutex : public Graph{
private:

    //Normal
    std::vector<std::shared_timed_mutex> nodesMutex;

    //Insertion
    std::shared_timed_mutex structureMutex;

public:
    //Constutor
    GraphSharedMutex();

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

    void printEdges();

};

#endif //GRAPHEVALUATION_GRAPHSHAREDMUTEX_HPP
