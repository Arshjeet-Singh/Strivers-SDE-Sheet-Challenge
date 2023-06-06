#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> ans;
  vector<long long int> v1;
  v1.push_back(1);
  ans.push_back(v1);
  for(int i=1;i<n;i++)
  { 
    vector<long long int> v;
    int prev=ans.size()-1;
    v.push_back(ans[prev][0]);  
    if(i==1)
    {
      
    }
    for(int j=0;j<ans[prev].size()-1;j++)
    {
      v.push_back(ans[prev][j]+ans[prev][j+1]);
    } 
    v.push_back(ans[prev][ans[prev].size()-1]);   
    ans.push_back(v);
  }
  return ans;
  // Write your code here.
}
