#include<bits/stdc++.h>
void dfs(int node,unordered_map<int,list<int>> &adj,stack<int> &s,vector<bool> &vis)
{
    vis[node]=1;
    for(auto i:adj[node])
    {
        if(!vis[i])
        {
            dfs(i,adj,s,vis);
        }
    }
    s.push(node);
}
void revdfs(int node,unordered_map<int,list<int>> &adj,vector<bool> &vis,vector<int> &v)
{
    vis[node]=1;
    v.push_back(node);
    for(auto i:adj[node])
    {
        if(!vis[i])
        {
            revdfs(i,adj,vis,v);
        }
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    stack<int> s;
    vector<bool> vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i,adj,s,vis);
        }
    }
    unordered_map<int,list<int>> radj;
    for(int i=0;i<n;i++)
    {
        vis[i]=0;
        for(auto it:adj[i])
        {
            radj[it].push_back(i);
        }
    }
    vector<vector<int>> ans;
    while(!s.empty())
    {
        int a=s.top();
        s.pop();
        if(!vis[a])
        {
            vector<int> v;
            revdfs(a, radj, vis,v);
            ans.push_back(v);
        }
    }
    return ans;
    // Write your code here.

}
