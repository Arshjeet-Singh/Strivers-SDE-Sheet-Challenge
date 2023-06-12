#include <bits/stdc++.h> 
int help(int i,int j,int m,int n)
{
	if(i>=m || j>=n)
	{
		return 0;
	}
	if(i==m-1 && j==n-1)
	{
		return 1;
	}
	return help(i+1,j,m,n)+help(i,j+1,m,n);
}
int help1(int i,int j,int m,int n,vector<vector<int>> &dp)
{
	if(i>=m || j>=n)
	{
		return 0;
	}
	if(i==m-1 && j==n-1)
	{
		return 1;
	}
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	return dp[i][j]=help1(i+1,j,m,n,dp)+help1(i,j+1,m,n,dp);
}
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m,vector<int>(n,-1));
	return help1(0,0,m,n,dp);
	// Write your code here.
}
