#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s) {
  vector<vector<int>> ans;
  int n = arr.size();
  unordered_map<int,int> mp;
  for(int i=0;i<n;i++)
  {
     int b=s-arr[i];
     if(mp[b])
     {
        int val=mp[b];
        while(val>0)
        {
         vector<int>v;
         v.push_back(arr[i]);
         v.push_back(s-arr[i]);
         sort(v.begin(),v.end());
         ans.push_back(v);
         val--;
        }
     }
     mp[arr[i]]++;
  }
  sort(ans.begin(),ans.end());

   return ans;
   // Write your code here.
}
