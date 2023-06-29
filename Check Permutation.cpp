#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    unordered_map<char,int> mp,mp1;
    for(int i=0;i<str1.size();i++)
    {
        mp[str1[i]]++;
    }
    for(int i=0;i<str2.size();i++)
    {
        mp1[str2[i]]++;
    }
    if(mp==mp1)
    {
        return 1;
    }
    return 0;
    // Write your code here.
}
