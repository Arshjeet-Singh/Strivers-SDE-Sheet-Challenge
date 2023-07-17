#include<bits/stdc++.h>
bool bfs(int node,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &vis)
{
    unordered_map<int,int> parent;
    vis[node]=1;
    parent[node]=-1;
     queue<int> q;
     q.push(node);
     while(!q.empty())
     {
         int a=q.front();
         q.pop();
         for(auto i:adj[a])
        {
            if(vis[i]==true && parent[a]!=i)
            {
                return true;
            }
            else if(!vis[i])
            {
                vis[i]=true;
            parent[i]=a;
            q.push(i);
            }
        }
     }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>> adj;
    for(int i=0;i<m;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // vector<bool> vis(n+1,0);
    unordered_map<int,bool> vis;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            bool ans=bfs(i,adj,vis);
            if(ans==1)
            {
                return "Yes";
            }
        }
    }
    return "No";
    // Write your code here.
}
