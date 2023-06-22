#include <bits/stdc++.h> 
void help(int ind,string &s,string &h,vector<string> &ans)
{
    if(ind>=s.size())
    {
        ans.push_back(s);
        return;
    }
    for(int i=ind;i<s.size();i++)
    {
        // h+=s[ind];
        swap(s[ind],s[i]);
        help(ind+1,s,h,ans);
        swap(s[ind],s[i]);
    }

}
vector<string> findPermutations(string &s) {
    vector<string> ans;
    string h="";
    help(0,s,h,ans);
    return ans;
        // Write your code here.
}
