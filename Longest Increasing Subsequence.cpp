#include<bits/stdc++.h>
int help(int arr[], int n,int curr,int prev,vector<vector<int>> &dp)
{
    if(curr==n)
    {
        return 0;
    }
    if(dp[curr][prev+1]!=-1)
    {
        return dp[curr][prev+1];
    }
    int ex=help(arr,n,curr+1,prev,dp);
    int in=0;
    if(prev==-1 || arr[curr]>arr[prev])
    {
        in=1+help(arr,n,curr+1,curr,dp);
    }
    return dp[curr][prev+1]=max(in,ex);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    // return help(arr,n,0,-1,dp);
    // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    // for(int curr=n-1;curr>=0;curr--)
    // {
    //     for(int prev=curr-1;prev>=-1;prev--)
    //     {
    //         int ex=dp[curr+1][prev+1];
    //         int in=0;
    //         if(prev==-1 || arr[curr]>arr[prev])
    //         {
    //             in=1+dp[curr+1][curr+1];
    //         }
    //         dp[curr][prev+1]=max(in,ex);
    //      }
    // }
    // return dp[0][0];
    //TLE below
    // vector<int> dp(n,1);
    // int ans=1;
    // for(int i=1;i<n;i++)
    // {
    //     for(int j=0;j<i;j++)
    //     {
    //         if(arr[i]>arr[j])
    //         {
    //             dp[i]=max(dp[i],dp[j]+1);
    //         }
    //     }
    //     ans=max(ans,dp[i]);
    // }
    // return ans;
    vector<int> dp;
    int ans=1;
    dp.push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        if(arr[i]>dp.back())
        {
            dp.push_back(arr[i]);
        }
        else
        {
            int ind=lower_bound(dp.begin(),dp.end(),arr[i])-dp.begin();
        dp[ind]=arr[i];
        }
        
    }
    return dp.size();
    // Write Your Code here
}
