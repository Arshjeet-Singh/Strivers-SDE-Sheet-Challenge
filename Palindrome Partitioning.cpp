#include <bits/stdc++.h> 
bool ispali(string &s,int st,int e)
{
    while(st<e)
    {
        if(s[st]!=s[e])
        {
            return false;
        }
        st++; e--;
    }
    return true;
}
void help(int ind,string &s,vector<string> v,vector<vector<string>> &ans)
{
    if(ind>=s.size())
    {
        ans.push_back(v);
        return;
    }
    for(int i=ind;i<s.size();i++)
    {
        if(ispali(s,ind,i))
        {
            v.push_back(s.substr(ind,i-ind+1));
            help(i+1,s,v,ans);
            v.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> ans;
    vector<string> v;
    help(0,s,v,ans);
    return ans;
    // Write your code here.
}
