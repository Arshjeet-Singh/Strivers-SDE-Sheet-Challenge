#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {
  int n=arr.size();
  int s=0,maxi=0;
  unordered_map<int,int> mp;
  for(int i=0;i<n;i++)
  {
    s+=arr[i];
    if(s==0)
    {
      maxi=i+1;
    }
    else if(mp.find(s)!=mp.end())
    {
        maxi=max(maxi,i-mp[s]);
    }
    else
    {
      mp[s]=i;
    }
  }
  return maxi;
  // Write your code here

}
