#include<bits/stdc++.h>
int help(int n,int k,vector<vector<int>> &dp)
{
    if(n<=0 || k<=0)
    {
        return 0;
    }
    if(k==1)
    {
        return n;
    }
    if(n==1)
    {
        return 1;
    }
    if(dp[n][k]!=-1)
    {
        return dp[n][k];
    }
    int low=1,high=n,ans=INT_MAX;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int broken=help(mid-1,k-1,dp);
        int nb=help(n-mid,k,dp);
        int res=max(nb,broken);
        ans=min(ans,res+1);
        if(broken<nb)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return dp[n][k]=ans;
}
int cutLogs(int k, int n)
{
    vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
    return help(n,k,dp);
    // vector<vector<int>> dp(k+1,vector<int>(n+1,0));
    // for(int i=0;i<=k;i++)
    // {
    //     for(int j=0;j<=n;j++)
    //     {
    //         dp[i][j]=j;
    //     }
    // } 
    // for(int i=2;i<=k;i++)
    // {
    //     for(int j=2;j<=n;j++)
    //     {

    //         for(int t=1;t<=j;t++)
    //         {
    //             int curr=max(dp[i-1][t-1],dp[i][j-t]);
    //             dp[i][j]=min(dp[i][j],curr);    
    //         }
    //         dp[i][j]++;
    //     }
    // }
    // return dp[k][n];
    // Write your code here.
}
