#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    int n=s.size();
    // unordered_map<char,int> mp;
    int len=0,left=0,right=0,ans=0;
    vector<int> mp(256,-1);
    while(right<n)
    {
        if(mp[s[right]]!=-1)
        {
            left=max(mp[s[right]]+1,left);
        }
        mp[s[right]]=right;
        len=max(len,right-left+1);
        right++;
        // else
        // {

        // }
    }
    // while(i<n)
    // {
    //     if(mp.find(input[i])!=mp.end())
    //     {
    //         int ind=mp[input[i]];
    //         // mp[input[i]]=i;
    //         i=ind+1;
    //         len=0;
    //         mp.clear();
    //     }
    //     else
    //     {
    //         len++;
            
    //         mp[input[i]]=i;
    //         ans=max(ans,len);
    //     }
    // }
    return len;
    //Write your code here
}
