#include <iostream>
#include "Graph.hpp"

int main() {
    Graph graph;

    /* --- Insertion Test -- */
    //Insert Nodes
    graph.insertNode();
    graph.insertNode();
    graph.insertNode();
    graph.insertNode();
    graph.insertNode();

    //Insert Edges
    graph.insertEdge(0, 1);
    graph.insertEdge(1, 2);
    graph.insertEdge(2, 3);
    graph.insertEdge(3, 4);

    //Print
    std::cout << std::endl <<  "Initial costs:" << std::endl;
    graph.printEdges();
    /* --------- End -------- */


    //* --- Increase Test -- */
    //Normal Increase
    graph.increaseEdge(0, 1);
    graph.increaseEdge(0, 1);
    graph.increaseEdge(1, 2);
    graph.increaseEdge(2, 3);
    graph.increaseEdge(3, 4);
    graph.increaseEdge(3, 4);
    graph.increaseEdge(3, 4);

    //Tries to increase edge that doesnt exist
    graph.increaseEdge(0, 4);
    graph.increaseEdge(4, 3);

    //Tries index out of bounds
    graph.increaseEdge(1, 10);
    graph.increaseEdge(13, 2);
    graph.increaseEdge(10, 10);
    graph.increaseEdge(-1, 2);
    graph.increaseEdge(1, -3);
    graph.increaseEdge(-1, -4);

    //Print
    std::cout << std::endl << "After increase costs:" << std::endl;
    graph.printEdges();
    /* --------- End -------- */


    //* --- Decrease Test -- */
    //Normal
    graph.decreaseEdge(0, 1);
    graph.decreaseEdge(1, 2);
    graph.decreaseEdge(3, 4);
    graph.decreaseEdge(3, 4);
    graph.decreaseEdge(3, 4);

    //Tries to decrease edge at minimum value or that doesnt exist
    graph.decreaseEdge(1, 2);
    graph.decreaseEdge(3, 4);
    graph.decreaseEdge(0, 4);

    //Tries index out of bounds
    graph.decreaseEdge(1, 10);
    graph.decreaseEdge(13, 2);
    graph.decreaseEdge(10, 10);
    graph.decreaseEdge(-1, 2);
    graph.decreaseEdge(1, -3);
    graph.decreaseEdge(-1, -4);

    //Get Edges Cost
    std::cout << std::endl <<  "After decrease costs:" << std::endl;
    graph.printEdges();
    /* --------- End -------- */

//    if (!)
//        std::cout << "AE" << std::endl;
//


    return 0;
}