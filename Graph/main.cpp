#include"ArrayGraph.h"
#include"AdjListGraph.h"

int main() {
    Graph* ag = new AdjListGraph(10);

    ag->addEdge(1, 2);
    ag->addEdge(2, 3);
    ag->addEdge(1, 4);
    ag->addEdge(4, 5);
    ag->addEdge(2, 6);
    ag->addEdge(6, 7);
    ag->addEdge(3, 8);
    ag->addEdge(8, 9);

    ag->BFS(1);
    return 0;
}
