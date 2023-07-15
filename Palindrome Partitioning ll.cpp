#include <bits/stdc++.h>
bool ispali(int i,int j,string s)
{
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            return false;
        }
        i++; j--;
    }
    return true;
}
int help(int i,string s,vector<int> &dp)
{
    if(i==s.size())
    {
        return 0;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    int mini=INT_MAX;
    for(int j=i;j<s.size();j++)
    {
        if(ispali(i,j,s))
        {
            int cost=1+help(j+1,s,dp);
            mini=min(mini,cost);
        }
    }
    return dp[i]=mini;
} 
int palindromePartitioning(string s) {
    int n=s.size();
    vector<int> dp(s.size()+1,0);
    for(int i=n-1;i>=0;i--)
    {
        int mini=INT_MAX;
        for(int j=i;j<s.size();j++)
        {
            if(ispali(i,j,s))
            {
                int cost=1+dp[j+1];
                mini=min(mini,cost);
            }
        }
        dp[i]=mini;
    }
    return dp[0]-1;
    // vector<int> dp(str.size(),-1);
    // return help(0,str,dp)-1;
    // Write your code here
}
