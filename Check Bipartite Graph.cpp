bool dfs(int node,vector<vector<int>> &edges,vector<int> &color,int col)
{
	color[node]=col;
	for(int i=0;i<edges[0].size();i++)
	{
		if(edges[node][i])
		{
			if(color[i]==-1)
			{
				bool ans=dfs(i,edges,color,!col);
				if(ans==false)
				{
					return false;
				}
			}
			else if(color[i]==col)
			{
				return false;
			}
		} 
	}
	return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n=edges.size();
	vector<int> color(n,-1);
	for(int i=0;i<n;i++)
	{
		if(color[i]==-1)
		{
			bool ans=dfs(i,edges,color,0);
			if(ans==false)
			{
				return false;
			}
		}
	} 
	return true;
	// Write your code here.
}
