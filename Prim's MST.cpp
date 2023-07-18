#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>>> adj;
	for(int i=0;i<m;i++)
	{
		int u=g[i].first.first;
		int v=g[i].first.second;
		int w=g[i].second;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	vector<int> p(n+1,-1);
	vector<bool> vis(n+1,0);
	vector<int> key(n+1,INT_MAX);
	key[1]=0;
	for(int i=1;i<n;i++)
	{
		int mini=INT_MAX;
		int u;
		for(int v=1;v<=n;v++)
		{
			if(!vis[v] &&  key[v]<mini)
			{
				u=v;
				mini=key[v];
			}
		}
		vis[u]=1;
		for(auto it:adj[u])
		{
			int v=it.first;
			int w=it.second;
			if(!vis[v] && w<key[v])
			{
				p[v]=u;
				key[v]=w;
			}
		}
	}
	vector<pair<pair<int, int>, int>> ans;
	for(int i=2;i<=n;i++)
	{
		ans.push_back({{p[i],i},key[i]});
	}
	return ans;
    // Write your code here.
}
