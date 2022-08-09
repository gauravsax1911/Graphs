#include<bits/stdc++.h>

using namespace std;

class edge{
    public:
    int u,v;

};

int t;

vector<int> dis;
vector<int> low;
vector<int> articulationPoint;
vector<bool> AP;
vector<bool> vis;

void dfs(int src , int par , vector<vector<edge>> &graph)
{
    dis[src] = low[src] = t++;
    vis[src] = true;

    for(edge e : graph[src])
    {
        if(!vis[e.v])
        {
            dfs(src,par,graph);

            if(dis[src] <= low[e.v])
            {
                articulationPoint[src]++;
                AP[src] = true;
            }

            low[src] = min(low[src],low[e.v]);
        }else if(e.v != par)
        {
            low[src] = min(low[src],dis[e.v]);
        }
    }

    return;
}

void apCount(int n , vector<vector<edge>> &graph)
{
    dis.resize(n);
    t = 0;
    low.resize(n);
    articulationPoint.resize(n,0);
    AP.resize(n,false);
    vis.resize(n,false);


    for(int i = 0 ; i < n ; i++)
    {
           if(!vis[i])
           {
               dfs(i,-1,graph);
           }
    }
}