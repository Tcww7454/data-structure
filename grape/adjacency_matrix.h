#include<vector>
#include<unordered_set>

#ifndef AdjMat
#define AdjMat

class GraphAdjMat{
    protected:
        std::vector<int> vertices;//储存节点值
        std::vector<std::vector<int>>adjMat;//储存点间关系

    public:
        GraphAdjMat(const std::vector<int> &vertices, const std::vector<std::vector<int>>&edges);
        int size()const;
        //添加顶点
        void addVertex(int val);
        //删除顶点
        void removeVertex(int index);
        //添加边
        virtual void addEdge(int i,int j);
        //删除边
        void removeEdge(int i,int j);
        //打印
        void print();
        ~GraphAdjMat();
};  

#endif