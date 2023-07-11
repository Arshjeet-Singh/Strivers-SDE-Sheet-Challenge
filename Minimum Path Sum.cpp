#include <bits/stdc++.h>
int help(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp)
{
    if(i>=grid.size() || j>=grid[0].size())
    {
        return 0;
    }
    if(i==grid.size()-1 && j==grid[0].size()-1)
    {
        return grid[i][j];
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(i!=grid.size()-1 && j!=grid[0].size()-1)
    {
        int a=grid[i][j]+help(i+1,j,grid,dp);
        int b=grid[i][j]+help(i,j+1,grid,dp);
        return dp[i][j]=min(a,b);
    }
    if(i!=grid.size()-1 && j==grid[0].size()-1)
    {
        return dp[i][j]= grid[i][j]+help(i+1,j,grid,dp);
    }
    if(i==grid.size()-1 && j!=grid[0].size()-1)
    {
        return dp[i][j]=grid[i][j]+help(i,j+1,grid,dp);
    }
} 
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return help(0,0,grid,dp);
    // Write your code here.
}
