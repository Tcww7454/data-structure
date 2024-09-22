#include<iostream>
#include <windows.h>
#include"adjacency_matrix.h"


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

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    //std::cout<<1<<std::endl;
    testadj_mat();
    return 0;
}
