#include <bits/stdc++.h>
bool cmp(vector<int> &a,vector<int> &b)
{
	return a[2]<b[2];	
}
int findparent (vector<int> &p,int node)
{
	if(p[node]==node)
	{
		return node;
	}
	return p[node]=findparent(p,p[node]);
} 
int findunion(int u,int v,vector<int> &rank,vector<int> &p)
{
	u=findparent(p,u);
	v=findparent(p,v);
	if(rank[u]<rank[v])
	{
		p[u]=v;
	}
	else if(rank[v]<rank[u])
	{
		p[v]=u;
	}
	else
	{
		p[v]=u;
		rank[u]++;
	}
}
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	sort(graph.begin(),graph.end(),cmp);
	vector<int> rank(n+1,0);
	vector<int> p(n+1);
	for(int i=0;i<n+1;i++)
	{
		p[i]=i;
	}
	int miniw;
	for(int i=0;i<m;i++)
	{
		int u=graph[i][0];
		int v=graph[i][1];
		int w=graph[i][2];
		u=findparent(p,u);
		v=findparent(p,v);
		if(u!=v)
		{
			miniw+=w;
			findunion(u,v,rank,p);
		}
	}

	return miniw;
	// Write your code here.
}
