#include<bits/stdc++.h>
using namespace std;
class DSU
{
private:
    int* parent;
    int* Rank;
public:
    DSU(int n)
    {
        parent = new int[n];
        Rank = new int[n];
        for(int i=0;i<n;i++)
        {
            parent[i]=-1;
            Rank[i]=1;
        }
    }
    int Find(int i)
    {
        if(parent[i]==-1)
        {
            return i;
        }
        return parent[i]=Find(parent[i]);
    }
    void unite(int x,int y)
    {
        int s1=Find(x);
        int s2=Find(y);
        if(s1!=s2)
        {
            if(Rank[s1]<Rank[s2])
            {
                parent[s1]=s2;
            }
            else if(Rank[s1]>Rank[s2])
            {
                parent[s2]=s1;
            }
            else
            {
                parent[s2]=s1;
                Rank[s1]+=1;
            }
        }
    }
};
class Graph
{
    vector<vector<int>>edgelist;
    int V;
public:
    Graph(int V)
    {
        this->V=V;
    }
    void addEdge(int x,int y,int w)
    {
        edgelist.push_back({w,x,y});
    }
    void kruskals_mst()
    {
        sort(edgelist.begin(),edgelist.end());
        DSU s(V);
        int ans=0;
         cout << "Following are the edges in the "
                "constructed MST"
             << endl;
        for(auto edge: edgelist)
        {
            int w=edge[0];
            int x=edge[1];
            int y=edge[2];

            if(s.Find(x)!=s.Find(y))
            {
               s.unite(x,y);
               ans+=w;
                 cout << x << " -- " << y << " == " << w
                     << endl;
            }
        }
         cout << "Minimum Cost Spanning Tree: " << ans;
    }
};
int main()
{
      Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);

    // Function call
    g.kruskals_mst();

    return 0;
}
