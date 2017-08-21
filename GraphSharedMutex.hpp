//
// Created by naraujo on 20/08/17.
//

#ifndef GRAPHEVALUATION_GRAPHSHAREDMUTEX_HPP
#define GRAPHEVALUATION_GRAPHSHAREDMUTEX_HPP

#include "Graph.hpp"
#include <thread>
#include <mutex>
#include <shared_mutex>

struct shared_mutex_wrapper : std::shared_timed_mutex
{
    shared_mutex_wrapper() = default;
    shared_mutex_wrapper(shared_mutex_wrapper const&) noexcept : std::shared_timed_mutex() {}
    bool operator==(shared_mutex_wrapper const&other) noexcept { return this==&other; }
};

class GraphSharedMutex : public Graph{
private:

    //Normal
    std::vector<shared_mutex_wrapper> nodesMutex;

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
