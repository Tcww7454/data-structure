#include"Dijkstra.h"
using namespace std;

void Dijstra::resetDist()
{
    std::fill(dist.begin(),dist.end(),INT_MAX);
}

void Dijstra::dijstra(int start)
{
    int n=vertices.size();
    resetDist();//每次进行生成前先重置距离数组
    std::vector<bool>visited(n,false);//标记访问节点

    //优先队列，储存pair<距离，节点>
    //使用小根堆，堆顶元素即为最小元素，对应最短路径
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>>pg;   

    dist[start]=0;
    pg.push({0,start});//将首节点压入

    while(!pg.empty())
    {
        int u=pg.top().second;//取出对应的节点
        pg.pop();
        //通过这个去处理压入的多个节点值，使其只保存每次的最小路径
        if(visited[u])continue;
        visited[u]=true;

        for(int v=0;v<n;v++)
        {
            int weight=adjMat[u][v];
            //注意，这里的u是现在出发的节点，v是要到达的节点
            //这里是判断从当前节点走的路到目标节点的路径长是否比已有的到该点的最短路径短

            /*
                每次到一个新节点后,遍历其所连接的所有节点，
                若到该节点的总路径值小于当前该节点到该点的路径值，
                就对其进行dist的更新并压入优先队列中，
                这其中可能压入多个数据，因为其为执行到它时的最小值
            */
            if(weight!=0&&!visited[v]&&dist[u]+weight<dist[v])
            {
                dist[v]=dist[u]+weight;
                pg.push({dist[v],v});
            }
        }
    }
}

//待修改，这里是从顶点出发的长度，好改就不改了，下一个溜溜球了
void Dijstra::print()
{
    std::cout << "Vertex\tDistance from Source" << std::endl;
        for (int i = 0; i < vertices.size(); ++i) {
            std::cout << vertices[0]<<"->"<<vertices[i]<<":" << "\t" << dist[i] << std::endl;
        }
}

int Dijstra::getDistanceTo(int vertex)const{
    return dist[vertex];
}