#include<bits/stdc++.h>
int help(int i,int j,string s, string t,vector<vector<int>> &dp)
{
	if(i>=s.size() || j>=t.size())
	{
		return 0;
	}
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	if(s[i]==t[j])
	{
		return 1+help(i+1,j+1,s,t,dp);
	}
	int a=help(i+1,j,s,t,dp);
	int b=help(i,j+1,s,t,dp);
	return dp[i][j]=max(a,b);
}
int lcs(string s, string t)
{
	int n=s.size(),m=t.size();
	vector<vector<int>> dp(n,vector<int>(m,-1));
	return help(0,0,s,t,dp);
	//Write your code here
}
