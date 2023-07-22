#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<vec.size();i++)
    {
        int u=vec[i][0],v=vec[i][1],w=vec[i][2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    set<pair<int,int>> s;
    s.insert({0,source});
    vector<int> dis(vertices,INT_MAX);
    dis[source]=0;
    while(!s.empty())
    {
        auto top=*(s.begin());
        s.erase(s.begin());
        int ndis=top.first;
        int node=top.second;
        for(auto i:adj[node])
        {
            if(ndis+i.second<dis[i.first])
            {
                if(s.find({dis[i.first],i.first})!=s.end())
                {
                    s.erase({dis[i.first],i.first});
                }
                s.insert({ndis+i.second,i.first});
                dis[i.first]=ndis+i.second;
            }
        }
    }
    return dis;
    // Write your code here.
}
