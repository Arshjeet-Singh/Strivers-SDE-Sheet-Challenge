#include <bits/stdc++.h> 
void help(int i,string &s,string s1, set<string> st,vector<string> &ans)
{
    if(i==s.size())
    {
        ans.push_back(s1);
        return;
    }
    s1+=" ";
    for(int j=i;j<s.size();j++)
    {
        // temp+=s[j];
        if(st.find(s.substr(i,j+1-i))!=st.end())
        {
            // ans.push_back(temp);
            help(j+1,s,s1+s.substr(i,j+1-i),st,ans);

        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    set<string> st;
    for(auto a:dictionary)
    {
        st.insert(a);
    }
    vector<string> ans;
    for(int i=0;i<s.size();i++)
    {
      if (st.find(s.substr(0, i + 1))!=st.end()) {
          help(i+1,s,s.substr(0,i+1),st,ans);
      }
    }
    return ans;
    // Write your code here

}
