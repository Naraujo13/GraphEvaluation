//
// Created by naraujo on 20/08/17.
//

#ifndef GRAPHEVALUATION_GRAPHMUTEX_HPP
#define GRAPHEVALUATION_GRAPHMUTEX_HPP

#include "Graph.hpp"
#include <thread>
#include <mutex>

class GraphMutex : public Graph{
private:

    //Normal
    std::vector<std::mutex> nodesMutex;

    //Insertion
    std::mutex structureMutex;

public:
    //Constutor
    GraphMutex();

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

};

#endif //GRAPHEVALUATION_GRAPHMUTEX_HPP
