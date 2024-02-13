#include <bits/stdc++.h>
using namespace std;
const int N=100000;
int degree[N];
bool found[N];
vector<int>curr_graph;
vector<int>adj_list[N];
void DFS(int v)
{
    found[v]=true;
    curr_graph.push_back(v);
    for(int it : adj_list[v])
    {
        if(!found[it])
        {
            DFS(it);
        }
    }
}
void addEdge(vector<int>adj_list[N],int src,int dest)
{
    src--;
    dest--;
    adj_list[src].push_back(dest);
    adj_list[dest].push_back(src);
    degree[src]++;
    degree[dest]++;
}
int countSingleCycles(int n,int m)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(!found[i])
        {
            curr_graph.clear();
            DFS(i);

            int flag=1;
            for(int v:curr_graph)
            {
                if(degree[v]==2)
                {
                    continue;
                }
                else
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
            {
                cnt++;
            }
        }
    }
    return cnt++;
}
int main()
{
     int n = 15, m = 14;
    addEdge(adj_list, 1, 10);
    addEdge(adj_list, 1, 5);
    addEdge(adj_list, 5, 10);
    addEdge(adj_list, 2, 9);
    addEdge(adj_list, 9, 15);
    addEdge(adj_list, 2, 15);
    addEdge(adj_list, 2, 12);
    addEdge(adj_list, 12, 15);
    addEdge(adj_list, 13, 8);
    addEdge(adj_list, 6, 14);
    addEdge(adj_list, 14, 3);
    addEdge(adj_list, 3, 7);
    addEdge(adj_list, 7, 11);
    addEdge(adj_list, 11, 6);

    cout << countSingleCycles(n, m);

    return 0;
}
