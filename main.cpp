#include <iostream>
#include "Graph.hpp"
#include "AtomicGraph.hpp"
#include "GraphMutex.hpp"
#include "GraphSharedMutex.hpp"
#include <thread>


void test1(GraphSharedMutex &graph) {

    //Increment
    for(int i = 0; i < 25000; i++)
        graph.increaseEdge(rand() % 200,rand() % 200);
    //Decrement
    for(int i = 0; i < 25000; i++)
        graph.decreaseEdge(rand() % 200,rand() % 200);
    //Delete
    for(int i = 0; i < 250; i++)
        graph.deleteEdge(rand() % 200, rand() % 200);
    //Insert Nodes
    for(int i = 0; i < 15; i++)
        graph.insertNode();
    //Insert Edges
    for(int i = 200; i < 215; i++) {
        for(int j = 200; j < 215; j++) {
            graph.insertEdge(i, j);
        }
    }

}
void test2(GraphSharedMutex &graph) {

    //Decrement
    for(int i = 0; i < 25000; i++)
        graph.decreaseEdge(rand() % 200,rand() % 200);
    //Increment
    for(int i = 0; i < 25000; i++)
        graph.increaseEdge(rand() % 200,rand() % 200);
    //Delete
    for(int i = 0; i < 250; i++)
        graph.deleteEdge(rand() % 200, rand() % 200);
    //Insert Nodes
    for(int i = 0; i < 15; i++)
        graph.insertNode();
    //Insert Edges
    for(int i = 200; i < 215; i++) {
        for(int j = 200; j < 215; j++) {
            graph.insertEdge(i, j);
        }
    }
}

void test3(GraphSharedMutex &graph) {

    //Delete
    for(int i = 0; i < 250; i++)
        graph.deleteEdge(rand() % 200, rand() % 200);
    //Decrement
    for(int i = 0; i < 25000; i++)
        graph.decreaseEdge(rand() % 200,rand() % 200);
    //Increment
    for(int i = 0; i < 25000; i++)
        graph.increaseEdge(rand() % 200,rand() % 200);
    //Insert Nodes
    for(int i = 0; i < 15; i++)
        graph.insertNode();
    //Insert Edges
    for(int i = 200; i < 215; i++) {
        for(int j = 200; j < 215; j++) {
            graph.insertEdge(i, j);
        }
    }
}

void test4(GraphSharedMutex &graph) {

    //Insert Nodes
    for(int i = 0; i < 15; i++)
        graph.insertNode();
    //Insert Edges
    for(int i = 200; i < 215; i++) {
        for(int j = 200; j < 215; j++) {
            graph.insertEdge(i, j);
        }
    }
    //Increment
    for(int i = 0; i < 25000; i++)
        graph.increaseEdge(rand() % 200,rand() % 200);
    //Delete
    for(int i = 0; i < 250; i++)
        graph.deleteEdge(rand() % 200, rand() % 200);
    //Decrement
    for(int i = 0; i < 25000; i++)
        graph.decreaseEdge(rand() % 200,rand() % 200);

}

int main(){

    GraphSharedMutex graph;

    //Insert Nodes
    for(int i = 0; i < 200; i++)
        graph.insertNode();

    //Insert Edges
    for(int i = 0; i < 200; i++) {
        for(int j = 0; j < 200; j++) {
            graph.insertEdge(i, j);
        }
    }

    //std::fflush(stdin);
    //graph.printEdges();

    auto t1 = std::thread(test1, std::ref(graph));
    auto t2 = std::thread(test2, std::ref(graph));
    auto t3 = std::thread(test3, std::ref(graph));
    auto t4 = std::thread(test4, std::ref(graph));
    auto t5 = std::thread(test1, std::ref(graph));
    auto t6 = std::thread(test2, std::ref(graph));
    auto t7 = std::thread(test3, std::ref(graph));
    auto t8 = std::thread(test4, std::ref(graph));
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();

    //std::fflush(stdin);
    //graph.printEdges();

    return 0;
}