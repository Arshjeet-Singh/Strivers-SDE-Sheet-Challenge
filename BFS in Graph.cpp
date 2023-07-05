#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<vertex;i++)
    {
        sort(adj[i].begin(),adj[i].end());
    }
    vector<bool> vis(vertex,0);
        vector<int> ans;
    for(int i=0;i<vertex;i++)
    {
        queue<int> q;
        if (!vis[i]) {
            q.push(i);
            vis[i]=1;
        }
        while(!q.empty())
    {
        int a=q.front();
        q.pop();
        ans.push_back(a);
        vis[a]=1;
        for(auto i:adj[a])
        {
            if(!vis[i])
            {
                q.push(i);
                vis[i]=1;
            }
        }
    }    
    }
    
    return ans;
    // Write your code here
}
