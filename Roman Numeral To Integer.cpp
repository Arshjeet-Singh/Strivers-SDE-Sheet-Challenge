#include<bits/stdc++.h>
int romanToInt(string s) {
    int n=s.size();
    int num=0;
    unordered_map<char,int> mp;
    mp['I']=1;
    mp['V']=5;
    mp['X']=10;
    mp['L']=50;
    mp['C']=100;
    mp['D']=500;
    mp['M']=1000;
    num=mp[s[n-1]];
    for(int i=n-2;i>=0;i--)
    {
        if(mp[s[i]]>=mp[s[i+1]])
        {
            num+=mp[s[i]];
        }
        else
        {
            num-=mp[s[i]];
        }
    }
    return num;
    // Write your code here
}
