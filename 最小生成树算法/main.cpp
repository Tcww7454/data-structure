#include"Graph.h"

int main(){
    Graph g1(9);
    g1.addEdge(0, 1, 3);  
    g1.addEdge(0, 2, 5);  
    g1.addEdge(1, 2, 2);  
    g1.addEdge(1, 3, 4); 
    g1.addEdge(2, 4, 3);  
    g1.addEdge(3, 4, 1);  
    g1.addEdge(3, 5, 2);  
    g1.addEdge(4, 5, 6);  
    g1.addEdge(4, 6, 3); 
    g1.addEdge(5, 6, 4); 
    g1.addEdge(5, 7, 2);  
    g1.addEdge(6, 8, 1);  
    g1.addEdge(7, 8, 3);  

    vector<Edge> mst = g1.primMST(0);

    int sum = 0;
    cout << "最小生成树的边如下：" << endl;
    for (const auto& edge : mst) {
        cout << "边: (" << edge.src << ", " << edge.dest << ") 权重: " << edge.weight << endl;
        sum += edge.weight;
    }
    cout << "总权重是" << sum << endl;

    return 0;
}

