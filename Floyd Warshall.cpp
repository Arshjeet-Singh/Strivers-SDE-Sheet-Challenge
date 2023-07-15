int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<long long int>>adj(n,vector<long long int>(n,1e9));
    for(int i=0;i<n;i++)
    {
        adj[i][i]=0;
    }
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0]-1;
        int v=edges[i][1]-1;
        int w=edges[i][2];
        adj[u][v]=w;
    }
    for(int via=0;via<n;via++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(adj[i][via]!=1e9 && adj[via][j]!=1e9)
                {
                    adj[i][j]=min(adj[i][j],adj[i][via]+adj[via][j]);
                }
            }
        }
    }
    return adj[src-1][dest-1];
    // Write your code here.
}
