#include"prim.h"

void PrimeGraph::addEdge(int u,int v,int weight)
{
    if (u < 0 || v < 0 || u >= size() || v >= size() || v == u) {
            throw std::out_of_range("Vertex does not exist1");
        }
    //在无向图中，邻接矩阵关于主对角线对称
    adjMat[u][v]=weight;
    adjMat[v][u]=weight;
}

//重写构造函数，转为五香有权图
PrimeGraph::PrimeGraph(const std::vector<int> &vertices, const std::vector<std::vector<int>>&edges):GraphAdjMat(vertices,edges)
{
    for (const std::vector<int>& edge : edges)
    {
        // 确保边的两个顶点都在vertices中
        int firstVertexIndex = std::distance(vertices.begin(), std::find(vertices.begin(), vertices.end(), edge[0]));
        int secondVertexIndex = std::distance(vertices.begin(), std::find(vertices.begin(), vertices.end(), edge[1]));

        if (firstVertexIndex < vertices.size() && secondVertexIndex < vertices.size())
        {
            addEdge(firstVertexIndex, secondVertexIndex,edge[2]);
        }
        else
        {
            throw std::out_of_range("One of the vertices for the edge does not exist.");
        }
    }
}

// void PrimeGraph::generateMST(int start)
// {
//    std::unordered_set<int>visited;
//    std::queue<int>tree;
//    tree.push(start);
//    visited.insert(start);
//    int count1=adjMat.size()-1;
//    int total_s=0;
//     while(count1>0)
//     {
//         int min_n=INT_MAX;
//         int new_start=-1;//使用这个来检测是否找到了节点
//         for(int i=0;i<adjMat.size();i++)
//         {
//             if(visited.find(i)==visited.end()&&min_n>adjMat[tree.back()][i])
//             { 
//                 min_n=adjMat[tree.back()][i];
//                 new_start=i;
//             }
//         }
//         if(new_start==-1)break;
//         total_s+=min_n;
//         min_n=INT_MAX;
//         visited.insert(new_start);
//         tree.push(new_start);
//         count1--;
//     }
//     std::cout<<"total_s:"<<total_s<<std::endl;
// }

void PrimeGraph::generateMST(int start)
{
    int n = adjMat.size();  // 顶点数
    if (start < 0 || start >= n) {
        std::cerr << "Invalid start node." << std::endl;
        return;
    }

    std::unordered_set<int> visited;  // 记录已访问节点
    using Edge = std::pair<int, int>; // first 是权值，second 是目标节点
    std::priority_queue<Edge, std::vector<Edge>, std::greater<>> pq;  // 最小优先队列
    std::vector<std::tuple<int, int, int>> mst_edges; // 用于存储生成树的边 (start, end, weight)
    std::vector<int> traversal_order; // 记录遍历顺序

    // 插入与起始节点相连的所有边
    visited.insert(start);
    traversal_order.push_back(start);
    for (int i = 0; i < n; ++i) {
        if (adjMat[start][i] > 0) {
            pq.push({adjMat[start][i], i});
        }
    }

    int total_weight = 0;  // 最小生成树的总权值
    int edge_count = 0;    // 已加入生成树的边数

    // Prim's algorithm 主循环
    while (!pq.empty() && edge_count < n - 1) {
        auto [weight, next_node] = pq.top();
        pq.pop();

        if (visited.find(next_node) != visited.end()) {
            continue;  // 已访问过，跳过
        }

        // 将新节点加入生成树
        visited.insert(next_node);
        traversal_order.push_back(next_node);
        total_weight += weight;
        edge_count++;

        // 将加入的边存储起来，用于后续按遍历顺序输出
        mst_edges.push_back({traversal_order[traversal_order.size() - 2], next_node, weight});

        // 插入与新节点相连的所有未访问节点的边
        for (int i = 0; i < n; ++i) {
            if (adjMat[next_node][i] > 0 && visited.find(i) == visited.end()) {
                pq.push({adjMat[next_node][i], i});
            }
        }
    }

    // 输出按遍历顺序生成的最小生成树的边
    for (auto [start, end, weight] : mst_edges) {
        std::cout << "Added edge: " << start << " - " << end << " with weight " << weight << std::endl;
    }

    // 判断图是否连通
    if (edge_count != n - 1) {
        std::cerr << "Graph is not connected. Only partial MST was generated." << std::endl;
    } else {
        std::cout << "Total weight of MST: " << total_weight << std::endl;
    }
}