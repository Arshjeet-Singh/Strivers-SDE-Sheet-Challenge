#include <bits/stdc++.h> 
bool safe(int i,int j,vector<vector<int> > &maze,vector<vector<int>> &sol)
{
  int n=maze.size();
  if(i>=0 && j>=0 && i<n && j<n && maze[i][j]==1 && !sol[i][j])
  {
    return true;
  }
  return false;
}
void solve(int i,int j,vector<vector<int> > &maze, int n,vector<vector<int>> &ans,vector<vector<int>> sol)
{
  if(i==n-1 && j==n-1)
  {
    vector<int> v;
    sol[i][j]=1;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        v.push_back(sol[i][j]);
      }
    }
    ans.push_back(v);
    return;
  }
  sol[i][j]=1;
  if(safe(i+1,j,maze,sol))
  {
    // sol[i+1][j]=1;
    solve(i+1,j,maze,n,ans,sol);
    // sol[i+1][j]=0;
  }
  if(safe(i,j+1,maze,sol))
  {
    // sol[i][j+1]=1;
    solve(i,j+1,maze,n,ans,sol);
    // sol[i][j+1]=0;
  }
  if(safe(i,j-1,maze,sol))
  {
    // sol[i][j-1]=1;
    solve(i,j-1,maze,n,ans,sol);
    // sol[i][j-1]=0;
  }
  if(safe(i-1,j,maze,sol))
  {
    // sol[i-1][j]=1;
    solve(i-1,j,maze,n,ans,sol);
    // sol[i-1][j]=0;
  }
  sol[i][j]=0;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>> sol(n,vector<int>(n,0));
  vector<vector<int>> ans;
  if(maze[0][0]==0)
  {
    return ans;
  }
  // vector<vector<int>> sol
  solve(0,0,maze,n,ans,sol);
  return ans;
  // Write your code here.
}
