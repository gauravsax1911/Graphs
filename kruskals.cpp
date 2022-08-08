#include<bits/stdc++.h>

using namespaces std;

int findpar(vector<int> &par , int u)
{
    return par[u] == u ? u : (par[u] = findpar(par,par[u]));
}


int unionFind(vector<vector<int>> &edges , int n)
{
    vector<int> par(n);
    for(int i = 0 ; i < n ; i++)
    {
        par[i] = i;
    }
     
    int totalCost = 0;

    for(vector<int> vec : edges)
    {
        int u = vec[0];
        int v = vec[1];
        int cost = vec[2];

        // 
        int par1 = findpar(par,u);
        int par2 = findpar(par,v);

        if(par1 != par2)
        {
            par[par1] = par2;
            totalCost += cost;
            edges++;
        }

        if(edges > n - 1)
        {
            break;
        }
    }

    return edges == n - 1 ? totalCost : -1;
}




int kruskalsAlgorith(vector<vector<int>> &edges, int n)
{
    // edges like [1,2,3]  [2,3,7]
     // edge from 1 to 2 with cost 3 
     // edge from 2 to 3 with cost 7

     // Use kruskal's algorithm when edges given like this

    sort(edges.begin(),edges.end(),[](vector<int> &a , vector<int> &b){
              return a[2] < b[2];
    });
    
    return unionFind(edges,n);

}