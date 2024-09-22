#include<iostream>
#include <algorithm>  // for std::find
#include <iterator>   // for std::distance
#include"adjacency_matrix.h"

GraphAdjMat::GraphAdjMat(const std::vector<int> &vertices, const std::vector<std::vector<int>>&edges)
{
    //添加顶点，将用户传入的顶点表数据传入
    for(int val:vertices)
    {
        addVertex(val);
    }
    /*edges元素中索引为元素在图中的编号，其储存的值为节点的值
    接下来添加节点间关系*/
    //原本的直接添加节点值一直报错，唉，蠢逼一个
    // for(const std::vector<int>&edge:edges)
    // {
    //     addEdge(edge[0],edge[1]);
    // }
    for (const std::vector<int>& edge : edges)
    {
        // 确保边的两个顶点都在vertices中
        int firstVertexIndex = std::distance(vertices.begin(), std::find(vertices.begin(), vertices.end(), edge[0]));
        int secondVertexIndex = std::distance(vertices.begin(), std::find(vertices.begin(), vertices.end(), edge[1]));

        if (firstVertexIndex < vertices.size() && secondVertexIndex < vertices.size())
        {
            addEdge(firstVertexIndex, secondVertexIndex);
        }
        else
        {
            throw std::out_of_range("One of the vertices for the edge does not exist.");
        }
    }
}

//通过顶点数组获取数组大小
int GraphAdjMat::size()const
{
    return vertices.size();
}

//添加顶点
void GraphAdjMat::addVertex(int val)
{
    int n=size();
    //往节点数组中压入新节点值
    vertices.push_back(val);
    //为矩阵压入一行新的，此时列在逻辑上会缺一列
    //可以使用push_back方法往每一行中压入一个节点，以此来实现逻辑的补全
    adjMat.emplace_back(std::vector<int>(n,0));
    for(std::vector<int>&row:adjMat)
        row.push_back(0);

}

void GraphAdjMat::removeVertex(int index)
{
    if(index>=size())
    throw std::out_of_range("顶点不存在");
    //在顶点列表中删除索引index的顶点
    //顶点列表中的索引即为顶点在图中的逻辑位置
    vertices.erase(vertices.begin()+index);
    //在邻接矩阵中删除索引为index的行与列
    //行的话可以直接erase删除,列的话需要每行逐行删除
    adjMat.erase(adjMat.begin() + index);
    for(std::vector<int>&row:adjMat)
    {
        row.erase(row.begin()+index);
    }
}

void GraphAdjMat::addEdge(int i,int j)
{
    if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
            throw std::out_of_range("Vertex does not exist1");
        }
    //在无向图中，邻接矩阵关于主对角线对称
    adjMat[i][j]=1;
    adjMat[j][i]=1;
}

void GraphAdjMat::removeEdge(int i,int j)
{
     if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
            throw std::out_of_range("Vertex does not exist2");
        }
    //在无向图中，邻接矩阵关于主对角线对称
    adjMat[i][j]=0;
    adjMat[j][i]=0;
}

void GraphAdjMat::print()
{
    std::cout<<"Vertex list：\t"<<std::endl;
    for(int num:vertices)
    std::cout<<num<<"\t";
    std::cout<<std::endl;
    std::cout<<"Adjacency matrix：\t"<<std::endl;
    for(std::vector<int>&row:adjMat)
    {
        for(int num:row)
        {
            std::cout<<num<<"\t";
        }
        std::cout<<std::endl;
    }
}

GraphAdjMat::~GraphAdjMat()
{

}