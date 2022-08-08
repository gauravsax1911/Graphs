

#include<bits/stdc++.h>

using namespace std;

struct comp{
    bool operator()(pair_  a , pair_ b)
    {
        return a.wt > b.wt;
    }
};

void prims(vector<vector<edges>> &graph , int n)
{
    priority_queue<pair_ , vector<pair_> , comp>> pq;

    pq.push(pair_(src,-1,0,0));

    while(pq.size() != 0)
    {
        pair_  p = pq.top();
        pq.pop();

        if(vis[p.u])
        {continue;}

        vis[p.u] = true;

        for(edge e : graph[p.u])
        {
            if(!vis[e.v])
            {
                pq.push(pair_(p.u,e.v,e.wt+p.wsf+e.wt));
            }
        }
    }

    return;
}