//
// Created by naraujo on 20/08/17.
//

#ifndef GRAPHEVALUATION_GRAPH_HPP
#define GRAPHEVALUATION_GRAPH_HPP

#include <vector>
#include <iostream>
#include <atomic>
#include <mutex>



template <typename T>
struct atomwrapper
{
    std::atomic<T> _a;

    atomwrapper()
            :_a()
    {}

    atomwrapper(const std::atomic<T> &a)
            :_a(a.load())
    {}

    atomwrapper(const atomwrapper &other)
            :_a(other._a.load())
    {}

    atomwrapper &operator=(const atomwrapper &other)
    {
        _a.store(other._a.load());
    }
};

class AtomicGraph{
private:
    std::vector<int> nodes;
    std::vector< std::vector<atomwrapper<int>> > edges;

public:
    //Constutor
    AtomicGraph();

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
    void printEdges(){
        std::cout << "Printing Edges..." << std::endl;
        std::cout << "-------------- START --------------" << std::endl;
        for (int i = 0; i < edges.size(); i++){
            std::cout << "| ";
            for (int j = 0; j < edges[i].size(); j++)
                std::cout << "(" << edges[i][j]._a << ") | ";
            std::cout << std::endl;
        }
        std::cout << "--------------- END ---------------" << std::endl;
    }

};

#endif //GRAPHEVALUATION_GRAPH_HPP
