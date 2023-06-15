#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    int n=arr.size();
    int xr=0;
    unordered_map<int,int> mp;
    mp[xr]++;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        xr=xr^arr[i];
        int x1=xr^x;
        cnt+=mp[x1];
        mp[xr]++;
    }
    return cnt;
    //    Write your code here.
}
