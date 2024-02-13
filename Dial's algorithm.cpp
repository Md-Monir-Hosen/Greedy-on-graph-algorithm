#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
class Graph
{
  int V;
  list<pair<int,int>>*adj;
  public:
      Graph(int V)
      {
          this->V=V;
          adj=new list<pair<int,int>>[V];
      }
      void addEdge(int x,int y,int w)
      {
          adj[x].push_back(make_pair(y,w));
          adj[y].push_back(make_pair(x,w));
      }
      void shortestPath(int src,int W)
      {
          vector<pair<int,list<int>::iterator>>dist(V);
          for(int i=0;i<V;i++)
          {
              dist[i].first=INF;

          }
           list<int>B[W*V+1];
          B[0].push_back(src);
          dist[src].first=0;
          int idx=0;
          while(1)
          {
           while(B[idx].size()==0 && idx<W*V)
           {
               idx++;
           }
           if(idx==W*V)
           {
               break;
           }
           int u = B[idx].front();
           B[idx].pop_front();
           for(auto i=adj[u].begin();i!=adj[u].end();++i)
           {
               int v=(*i).first;
               int weight=(*i).second;
               int du=dist[u].first;
               int dv=dist[v].second;
               if(dv>du+weight)
               {
                 if(dv != INF)
                 {
                   B[dv].erase(dist[v].second);
                 }
                 dist[v].first = du+weight;
                 dv=dist[v].first;
                 B[dv].push_front(v);
                 dist[v].second=B[dv].second;
               }
           }
          }
          cout<<"Vertex Distance from Source\n";
          for(int i=0;i<V;++i)
          {
              cout<<i<<"             "<<dist[i].first;
          }
      }
};
int main()
{
    int V = 9;
    Graph g(V);

    // making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    // maximum weighted edge - 14
    g.shortestPath(0, 14);

    return 0;
}
