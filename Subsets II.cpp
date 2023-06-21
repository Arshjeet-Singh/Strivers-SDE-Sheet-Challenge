#include <bits/stdc++.h> 
void help(int ind,int n, vector<int> &arr,vector<int> v,set<vector<int>> &st)
{
    if(ind>=n)
    {
        sort(v.begin(),v.end());
        st.insert(v);
        return;
    }
    v.push_back(arr[ind]);
    help(ind+1,n,arr,v,st);
    v.pop_back();
    help(ind+1,n,arr,v,st);
}
void striver(int ind,int n, vector<int> &arr,vector<int> &v,vector<vector<int>> &ans)
{
    ans.push_back(v);
    for(int i=ind;i<n;i++)
    {
        if(i!=ind && arr[i]==arr[i-1])
        {
            continue;
        }
        v.push_back(arr[i]);
        striver(i+1,n,arr,v,ans);
        v.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // set<vector<int>> st;
    vector<int> v;
    // help(0,n,arr,v,st);
    // vector<vector<int>> ans(st.begin(),st.end());
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    striver(0,n,arr,v,ans);
    return ans;
    // Write your code here.
}
