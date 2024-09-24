// #include<iostream>
// #include"adjacency_list.h"
// adj_list::adj_list(const std::vector<int> &vertices, const std::vector<std::vector<int>>&edges)
// {
//     int x=vertices.size();
//     this->vertices=x;
//     adjlist.resize(x);
//     // 创建值到索引的映射
//     for (int i = 0; i < this->vertices; ++i) {
//         vertexIndex[vertices[i]] = i; // 将顶点值映射到索引，从0开始
//         adjlist.emplace_back();
//     }
//     for(const std::vector<int>& edge:edges)
//     {
//         addedge(edge[0],edge[1]);
//     }
// }

// void adj_list::addedge(int src,int dest)//添加从src到dest的边
// {
//     //不存在该src，添加
//     if(vertexIndex.find(src)==vertexIndex.end())
//     {
//          int newIndex = vertexIndex.size();
//         vertexIndex[src] = newIndex;
//         adjlist.emplace_back(); // 为新顶点添加邻接表
//     }
//     //同理添加
//     if(vertexIndex.find(dest)==vertexIndex.end())
//     {
//         int newIndex = vertexIndex.size();
//         vertexIndex[dest] = newIndex;
//         adjlist.emplace_back(); // 为新顶点添加邻接表
//     }


//    // 根据顶点值获取对应的索引
//     int srcIndex = vertexIndex[src];
//     int destIndex = vertexIndex[dest];

//     // 将目标顶点添加到源顶点的邻接表中
//     adjlist[srcIndex].push_back(dest);
//     // 无向图，添加反向边
//     adjlist[destIndex].push_back(src);
// }

// // void adj_list::print()
// // {
// //     // for(int i=0;i<vertices;i++)
// //     // {
// //     //     std::cout<<"Vertes:"<<i<<":";
// //     //     for (auto it = adjlist[i].begin(); it != adjlist[i].end(); ++it) {
// //     //         std::cout << *it; // 打印当前元素
// //     //         // 如果不是最后一个元素，输出 "->"
// //     //         if (std::next(it) != adjlist[i].end()) {
// //     //             std::cout << " -> ";
// //     //         }
// //     //     }
// //     //     std::cout<<std::endl;
// //     // }   
// //     for (const auto& pair : vertexIndex) {
// //         int vertexValue = pair.first; // 顶点值
// //         int index = pair.second; // 顶点索引
// //         std::cout << "Vertex " << index << " (" << vertexValue << "): ";
// //         for (auto it = adjlist[index].begin(); it != adjlist[index].end(); ++it) {
// //             std::cout << *it; // 打印当前元素
// //             // 如果不是最后一个元素，输出 "->"
// //             if (std::next(it) != adjlist[index].end()) {
// //                 std::cout << " -> ";
// //             }
// //         }
// //         std::cout << std::endl;
// //     }
// // }

// void adj_list::print() {
//     // 遍历所有的顶点
//     for (const auto& pair : vertexIndex) {
//         int vertexValue = pair.first; // 当前顶点的值
//         int index = pair.second; // 当前顶点的索引

//         std::cout << "Vertex " << index << " (" << vertexValue << "): ";

//         // 遍历当前顶点的邻接表
//         for (auto adjIt = adjlist[index].begin(); adjIt != adjlist[index].end(); ++adjIt) {
//             std::cout << *adjIt; // 打印邻接顶点的值
//             // 如果不是最后一个元素，输出 "->"
//             if (std::next(adjIt) != adjlist[index].end()) {
//                 std::cout << " -> ";
//             }
//         }
//         std::cout << std::endl;
//     }
// }
#include<iostream>
#include<queue>
#include<stack>
#include"adjacency_list.h"

AdjListGraph::AdjListGraph(int vertices)
{
	numVertices = vertices;
	adjacencyCount = 0;
	adjList.resize(vertices);
}

void AdjListGraph::addEdge(int v, int w)
{
	if (v<0 || v>numVertices || w<0 || w>numVertices) {
		throw std::out_of_range("Index out of range");
	}

	for (int val : adjList[v]) {
		if (val == w)
			return;
	}

	adjList[v].push_back(w);
	adjList[w].push_back(v);
	adjacencyCount++;
}

std::vector<int> AdjListGraph::getAdjacent(int v) const
{
	std::vector<int> res;
	for (int val : adjList[v])
		res.push_back(val);
	return res;
}

int AdjListGraph::getEdgesCount() const
{
	return adjacencyCount;
}

int AdjListGraph::getVerticesCount() const
{
	return numVertices;
}

// Éî¶ÈÓÅÏÈ±éÀú
void AdjListGraph::DFS(int start)
{
	if (start < 0 || start >= numVertices)
		throw std::out_of_range("Index out of range");
	std::vector<char> visited(numVertices, 0);
	std::stack<int> stk;
	stk.push(start);
	visited[start] = true;

	while (!stk.empty()) {
		int top = stk.top();
		stk.pop();
		std::cout << top << " ";

		for (int val : adjList[top]) {
			if (!visited[val]) {
				stk.push(val);
				visited[val] = 1;
			}
		}
	}
}

// ¹ã¶ÈÓÅÏÈ±éÀú
void AdjListGraph::BFS(int start)
{
	if (start < 0 || start >= numVertices)
		throw std::out_of_range("Index out of range");
	std::vector<char> visited(numVertices, 0);
	std::queue<int> que;
	que.push(start);
	visited[start] = true;

	while (!que.empty()) {
		int top = que.front();
		que.pop();
		std::cout << top << " ";

		for (int val : adjList[top]) {
			if (!visited[val]) {
				que.push(val);
				visited[val] = 1;
			}
		}
	}
}