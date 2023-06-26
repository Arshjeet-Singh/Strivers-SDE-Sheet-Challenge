#include <bits/stdc++.h> 
void help(int ind,vector<int>v,vector<int>temp,vector<vector<int>> &ans)
{
    if(ind==v.size())
    {
        sort(temp.begin(),temp.end());
        ans.push_back(temp);
        return;
    }
    temp.push_back(v[ind]);
    help(ind+1,v,temp,ans);
    temp.pop_back();
    help(ind+1,v,temp,ans);
}
vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>> ans;
    vector<int> temp;
    help(0,v,temp,ans);
    return ans;
    //Write your code here
}
