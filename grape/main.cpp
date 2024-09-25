#include<iostream>
#include <windows.h>
#include"adjacency_matrix.h"
#include"adjacency_list.h"
#include"prim.h"

void testadj_mat()
{
    std::vector<int> vertices = {10, 20, 30, 40, 50}; // 顶点值
    std::vector<std::vector<int>> edges = {
        {10, 20}, // 10 和 20 之间有一条边
        {20, 30}, // 20 和 30 之间有一条边
        {30, 40}, // 30 和 40 之间有一条边
        {40, 50}  // 40 和 50 之间有一条边
    };
     GraphAdjMat Graph_first(vertices,edges);
     Graph_first.print();
     int size=Graph_first.size();
     std::cout<<size<<std::endl;
     std::cout<<std::endl;
     std::cout<<"First remove:"<<std::endl;
     Graph_first.removeVertex(2);
     Graph_first.print();
    std::cout<<std::endl;
     std::cout<<"First add:"<<std::endl;
     Graph_first.addVertex(4);
     Graph_first.print();
}

void testadj_list()
{
    //我直接cv
    AdjListGraph* ag = new AdjListGraph(10);

    ag->addEdge(1, 2);
    ag->addEdge(2, 3);
    ag->addEdge(1, 4);
    ag->addEdge(4, 5);
    ag->addEdge(2, 6);
    ag->addEdge(6, 7);
    ag->addEdge(3, 8);
    ag->addEdge(8, 9);
    ag->BFS(1);
}

void testprim()
{
    //测试成功
    std::vector<int> vertices = {10, 20, 30, 40, 50,60}; // 顶点值
    std::vector<std::vector<int>> edges = {
        {10,20,6},
        {10,60,1},
        {10,30,5},
        {30,60,5},
        {60,30,4},
        {20,40,3},
        {40,60,6},
        {40,50,6},
        {50,60,4},
        {30,50,2}
    };
     PrimeGraph Graph_sec(vertices,edges);
     Graph_sec.print();
     Graph_sec.generateMST(1);//16
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    //std::cout<<1<<std::endl;
    //testadj_mat();
    //testadj_list();
    testprim();
    return 0;
}


