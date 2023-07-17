#include <bits/stdc++.h> 
int help(int i, string & target,set<string> &s,vector<int> &dp)
{
    if(i==target.size())
    {
        return 1;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    string temp;
    for(int j=i;j<target.size();j++)
    {
        temp+=target[j];
        if(s.find(temp)!=s.end())
        {
            if(help(j+1,target,s,dp))
            {
                return dp[i]=1;
            }
        }
    }
    return dp[i]=0;
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    set<string> s;  
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
    }
    // vector<int> dp(n+1,-1);
    // return help(0,target,s,dp);
    int si=target.size();
    vector<int> dp(si+1,0);
    dp[si]=1;
    for(int i=si-1;i>=0;i--)
    {
        for(auto word:arr)
        {
            if(i+word.size()<=si && target.substr(i,word.size())==word)
            {
                dp[i]=dp[i+word.size()];
            }
        }
        //    string temp;
        //     for(int j=i;j<target.size();j++)
        //     {
        //         temp+=target[j];
        //         if(s.find(temp)!=s.end())
        //         {
        //                 dp[i]=dp[j+1];
        //         }
        //     }
        //     dp[i]=0;
    }
    return dp[0];
    // Write your code here.
}
