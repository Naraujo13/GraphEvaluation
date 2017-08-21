//
// Created by naraujo on 20/08/17.
//

#ifndef GRAPHEVALUATION_GRAPHMUTEX_HPP
#define GRAPHEVALUATION_GRAPHMUTEX_HPP

#include "Graph.hpp"
#include <thread>
#include <mutex>
#include <deque>

struct mutex_wrapper : std::mutex
{
    mutex_wrapper() = default;
    mutex_wrapper(mutex_wrapper const&) noexcept : std::mutex() {}
    bool operator==(mutex_wrapper const&other) noexcept { return this==&other; }
};

class GraphMutex : public Graph{
public:

    //Normal
    std::deque<mutex_wrapper> nodesMutex;

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

    void printEdges();

};

#endif //GRAPHEVALUATION_GRAPHMUTEX_HPP
