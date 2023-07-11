void dfs(int i,int j,int** arr, int n, int m,vector<vector<bool>> &vis)
{
   if(i>=0 && j>=0 && i<n && j<m && !vis[i][j] && arr[i][j]==1)
   {
      vis[i][j]=1;
      dfs(i+1,j,arr,n,m,vis);
      dfs(i-1,j,arr,n,m,vis);
      dfs(i,j+1,arr,n,m,vis);
      dfs(i,j-1,arr,n,m,vis);
      dfs(i+1,j+1,arr,n,m,vis);
      dfs(i+1,j-1,arr,n,m,vis);
      dfs(i-1,j+1,arr,n,m,vis);
      dfs(i-1,j-1,arr,n,m,vis);
   }
   else
   {
      return;
   }
}
int getTotalIslands(int** arr, int n, int m)
{
   vector<vector<bool>> vis(n,vector<bool>(m,0));
   int cnt=0;
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;j++)
      {
         if(arr[i][j]==1 && !vis[i][j])
         {
            cnt++;
            dfs(i,j,arr,n,m,vis);
         }
      }
   }
   return cnt;
   // Write your code here.
}
