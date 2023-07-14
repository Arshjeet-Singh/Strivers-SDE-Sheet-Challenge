int help(vector<int> &price, int n,vector<int> &dp)
{
	if(n==0)
	{
		return 0;
	}
	if(n<0)
	{
		return INT_MIN;
	}
	if(dp[n]!=-1)
	{
		return dp[n];
	}
	int maxi=INT_MIN;
	for(int i=0;i<n;i++)
	{
		int a=help(price, n-i-1,dp)+price[i];
		maxi=max(maxi,a);
	}
	return dp[n]=maxi;
}
int cutRod(vector<int> &price, int n)
{
	vector<int> dp(n+1,-1);
	return help(price,n,dp);
	// if(n==0)
	// {
	// 	return 0;
	// }
	// if(n<0)
	// {
	// 	return INT_MIN;
	// }
	// int maxi=INT_MIN;
	// for(int i=0;i<n;i++)
	// {
	// 	int a=cutRod(price, n-i-1)+price[i];
	// 	maxi=max(maxi,a);
	// }
	// return maxi;
	// Write your code here.
}
