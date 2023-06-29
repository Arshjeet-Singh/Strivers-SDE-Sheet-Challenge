#include <bits/stdc++.h> 
int atoi(string str) {
    int ans=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]>=48 && str[i]<=57)
        {
            ans=ans*10+(str[i]-'0');
        }
    }
    if(str[0]==45)
    {
        ans=ans*-1;
    }
    return ans;
    // Write your code here.
}
