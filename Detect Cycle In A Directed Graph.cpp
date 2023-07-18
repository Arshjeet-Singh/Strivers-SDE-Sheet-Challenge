#include<bits/stdc++.h>
bool dfs(int node,unordered_map<int,list<int>> &adj,vector<bool> vis,vector<bool> dfsvis)
{
  vis[node]=1;
  dfsvis[node]=1;
  for(auto it:adj[node])
  {
    if(vis[it] && dfsvis[it])
    {
      return true;
    }
    else if(!vis[it])
    {
        bool ans=dfs(it,adj,vis,dfsvis);
        if(ans)
        {
          return true;
        }
    }
  }
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,list<int>> adj;
  for(int i=0;i<edges.size();i++)
  {
    int u=edges[i].first-1;
    int v=edges[i].second-1;
    adj[u].push_back(v);
  }
  vector<bool> vis(n,0);
  vector<bool> dfsvis(n,0);
  for(int i=0;i<n;i++)
  {
    if(!vis[i])
    {
      bool ans=dfs(i,adj,vis,dfsvis);
      if(ans)
      {
        return true;
      }
    }
  }
  return false;
  // Write your code here.
}
