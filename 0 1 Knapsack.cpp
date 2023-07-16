int help(int i,vector<int> &values, vector<int> &weights, int n, int w,vector<vector<int>> &dp)
{
	if(i==n)
	{
		return 0;
	}
	if(dp[i][w]!=-1)
	{
		return dp[i][w];
	}
	int nt=help(i+1,values,weights,n,w,dp);
	int t=0;
	if(w>=weights[i])
	{
		t=values[i]+help(i+1,values,weights,n,w-weights[i],dp);
	}
	return dp[i][w]=max(nt,t);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n,vector<int>(w+1,-1));
	return help(0,values,weights,n,w,dp);
	// Write your code here
}
