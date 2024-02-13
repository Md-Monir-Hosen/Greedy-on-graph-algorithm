#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    vector<vector<int>>graph;
    int Find(vector<int>& parent,int i)
    {
        if(parent[i]==i)
        {
            return i;
        }
        return Find(parent,parent[i]);
    }
    void Unionset(vector<int>& parent,vector<int>& Rank,int x,int y)
    {
        int xroot=Find(parent,x);
        int yroot=Find(parent,y);
        if(Rank[xroot]<Rank[yroot])
        {
            parent[xroot]=yroot;
        }
        else if(Rank[xroot]>Rank[yroot])
        {
            parent[yroot]=xroot;
        }
        else
        {
            parent[yroot]=xroot;
            Rank[xroot]++;
        }
    }
public:
    Graph(int vertices)
    {
        int V=vertices;
        graph=vector<vector<int>>();
    }
    void addEdge(int x,int y,int w)
    {
        graph.push_back({x,y,w});
    }
    void boruvkaMST()
    {
        vector<int>parent(V);
        vector<int>Rank(V);
        vector<vector<int>>cheapest(V,vector<int>(3,-1));
        int numTrees=V;
        int MSTweight=0;
        for(int node=0;node<V;node++)
        {
            parent[node]=node;
            Rank[node] = 0;
        }
        while(numTrees>1)
        {
            for(int i=0;i<graph.size();i++)
            {
                int x=graph[i][0],y=graph[i][1],w=graph[i][2];
                int Set1=Find(parent,x),Set2=Find(parent,y);
                if(Set1 != Set2)
                {
                    if(cheapest[Set1][2]==-1 || cheapest[Set1][2]>w)
                    {
                       cheapest[Set1][2]={x,y,w};
                    }
                     if(cheapest[Set2][2]==-1 || cheapest[Set2][2]>w)
                    {
                       cheapest[Set2][2]={x,y,w};
                    }
                }
            }
            for(node=0;node<V;node++)
            {
                if(cheapest[node][2]==-1)
                {
                    int x=cheapest[node][0];
                    int y=cheapest[node][1];
                    int z=cheapest[node][2];
                    int Set1=Find(parent,u),
                        Set2=Find(parent,v);
                    if(Set1!=Set2)
                    {
                        MSTweight +=w;
                        Unionset(parent,Rank,Set1,Set2);
                        cout<<"Edge "<<u<<" - "<<v<<" with weighted "<<w<<"included in MST\n";
                        numTrees--;
                    }
                }
            }
            for(int node=0;node<V;node++)
            {
                cheapest[node][2]=-1;
            }
        }
        cout<<"Weight of MST is \n"D<<MSTweight;
    }
};
int main()
{
      Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.boruvkaMST();
}
