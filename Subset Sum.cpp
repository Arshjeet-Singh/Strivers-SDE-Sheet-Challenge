#include <bits/stdc++.h> 
void help(int ind,vector<int> &num,vector<int> &v,vector<int> &ans)
{
    if(ind>=num.size())
    {
        int s=0;
        for(int i=0;i<v.size();i++)
        {
            s+=v[i];
        }
        ans.push_back(s);
        return;
    }
    v.push_back(num[ind]);
    help(ind+1,num,v,ans);
    v.pop_back();
    help(ind+1,num,v,ans);
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> v;
    vector<int> ans;
    help(0,num,v,ans);
    sort(ans.begin(),ans.end());
    return ans;
    // Write your code here.
}
