#include <iostream>
#include "Graph.hpp"
#include "GraphMutex.hpp"
#include "GraphSharedMutex.hpp"

int main() {
    GraphMutex graph;

    /* --- Insertion Test -- */
    //Insert Nodes
    graph.insertNode();
    graph.insertNode();
    graph.insertNode();
    graph.insertNode();
    graph.insertNode();

    //Insert Edges
    graph.insertEdge(0, 1);
    graph.insertEdge(0, 2);
    graph.insertEdge(0, 4);
    graph.insertEdge(1, 2);
    graph.insertEdge(1, 4);
    graph.insertEdge(2, 0);
    graph.insertEdge(2, 1);
    graph.insertEdge(2, 3);
    graph.insertEdge(3, 0);
    graph.insertEdge(3, 4);
    graph.insertEdge(4, 1);
    graph.insertEdge(4, 3);
    graph.insertEdge(4, 4);
    //Tries out of bounds
    graph.insertEdge(1, 10);
    graph.insertEdge(10, 1);
    graph.insertEdge(10, 10);

    //Print
    std::cout << std::endl <<  "Initial costs:" << std::endl;
    graph.printEdges();
    /* --------- End -------- */


    //* --- Increase Test -- */
    //Normal Increase
    graph.increaseEdge(0, 1);
    graph.increaseEdge(0, 1);
    graph.increaseEdge(0, 2);
    graph.increaseEdge(0, 2);
    graph.increaseEdge(0, 4);
    graph.increaseEdge(1, 2);
    graph.increaseEdge(1, 4);
    graph.increaseEdge(2, 0);
    graph.increaseEdge(2, 1);
    graph.increaseEdge(2, 1);
    graph.increaseEdge(2, 1);
    graph.increaseEdge(2, 3);
    graph.increaseEdge(3, 0);
    graph.increaseEdge(3, 4);
    graph.increaseEdge(3, 4);
    graph.increaseEdge(3, 4);
    graph.increaseEdge(3, 4);
    graph.increaseEdge(3, 4);
    graph.increaseEdge(3, 4);
    graph.increaseEdge(3, 4);
    graph.increaseEdge(4, 1);
    graph.increaseEdge(4, 3);
    graph.increaseEdge(4, 3);
    graph.increaseEdge(4, 3);
    graph.increaseEdge(4, 3);
    graph.increaseEdge(4, 3);
    graph.increaseEdge(4, 4);

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
    graph.decreaseEdge(4, 3);
    graph.decreaseEdge(4, 3);

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

    //Print
    std::cout << std::endl <<  "After decrease costs:" << std::endl;
    graph.printEdges();
    /* --------- End -------- */


    //* --- Delete Edge Test -- */
    //Normal
    graph.deleteEdge(0,1);
    graph.deleteEdge(3,4);
    graph.deleteEdge(2,3);
    graph.deleteEdge(4,1);

    //Tries to delete edge that doesnt exists
    graph.deleteEdge(0,3);
    graph.deleteEdge(1,3);
    graph.deleteEdge(4,0);
    graph.deleteEdge(4,1);

    //Tries index out of bounds
    graph.deleteEdge(10,1);
    graph.deleteEdge(1,10);
    graph.deleteEdge(10,10);
    graph.deleteEdge(-1,1);
    graph.deleteEdge(1,-1);
    graph.deleteEdge(-1,-1);

    //Print
    std::cout << std::endl <<  "After delete edge costs:" << std::endl;
    graph.printEdges();
    /* --------- End -------- */

    /* --- Delete Node Test -- */
    //Normal
    graph.deleteNode(3);

    //Tries index out of bounds
    graph.deleteNode(10);
    graph.deleteNode(-1);

    //Print
    std::cout << std::endl <<  "After delete node costs:" << std::endl;
    graph.printEdges();
    /* --------- End -------- */

    /* --- Random Tests -- */
    graph.increaseEdge(2, 3);
    graph.increaseEdge(3, 3);
    graph.decreaseEdge(0, 3);
    graph.increaseEdge(1, 3);
    graph.insertNode();
    graph.insertNode();
    graph.increaseEdge(2, 0);
    graph.decreaseEdge(0, 1);
    graph.increaseEdge(0, 3);
    graph.increaseEdge(0, 4);
    graph.decreaseEdge(3, 2);
    graph.insertEdge(0, 5);
    graph.increaseEdge(0, 5);
    graph.increaseEdge(0, 5);
    graph.increaseEdge(0, 5);
    graph.increaseEdge(0, 5);
    graph.insertNode();
    graph.insertEdge(3, 4);
    graph.increaseEdge(3, 4);
    graph.increaseEdge(3, 4);
    graph.decreaseEdge(3, 1);
    graph.insertEdge(2, 0);
    graph.increaseEdge(2, 0);
    graph.insertEdge(4, 0);
    graph.increaseEdge(4, 0);
    graph.increaseEdge(4, 0);
    graph.increaseEdge(4, 0);
    graph.deleteNode(6);
    graph.decreaseEdge(0, 1);

    //Print
    std::cout << std::endl <<  "After random operations:" << std::endl;
    graph.printEdges();

    /* --------- End -------- */


//
//    if (!)
//        std::cout << "AE" << std::endl;


    return 0;
}