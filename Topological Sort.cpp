#include <bits/stdc++.h> 
void dfs(int node,unordered_map<int,list<int>> &adj,vector<bool> &vis,stack<int> &s)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,adj,vis,s);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    vector<bool> vis(v,0);
    stack<int> s;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            dfs(i,adj,vis,s);
        }
    }
    vector<int> ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    // reverse(ans.begin(),ans.end());
    return ans;
    // Write your code here
}
