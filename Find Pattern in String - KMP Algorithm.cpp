#include <bits/stdc++.h> 
bool findPattern(string p, string s)
{
    int m=p.size();
    vector<int> pre(m,0);
    int i=1,len=0;
    while(i<m)
    {
        if(p[len]==p[i])
        {
            len++;
            pre[i]=len;
            i++;
        }
        else
        {
            if(len==0)
            {
                pre[i]=0;
                i++;
            }
            else
            {
                len=pre[len-1];   
            }
        }
    }
    int n=s.size();
    i=0;
    int j=0;
    while(i<n)
    {
        if(s[i]==p[j])
        {
            i++; j++;
            if(j==m)
            {
                return true;
                
            }
        }
        else if(i<n && s[i]!=p[j])
        {
            if(j==0)
            {
                i++;
            }
            else
            {
                j=pre[j-1];
            }   
        }
    }
    return false;
    // long long int n=p.size();
    // vector<long long int> pre(n,0);
    // long long int j,i,len;
    // for(i=1;i<n;i++)
    // {
    //     j=pre[i-1];
    //     while(j>0 && s[i]!=s[j])
    //     {
    //         j=pre[j-1];
    //     }
    //     if(s[i]==s[j])
    //     {
    //         j++;
    //     }
    //     pre[i]=j;
    // }   
    // int pos=-1;
    // i=0;
    // j=0;
    // while(i<s.size())
    // {
    //     if(s[i]==p[j])
    //     {
    //         i++; j++;
    //     }
    //     else
    //     {
    //         if(j>0)
    //         {
    //             j=pre[j-1];
    //         }
    //         else
    //         {
    //             i++;
    //         }
    //     }
    //     if(j==p.size())
    //     {
    //         return true;
    //     }
    // }
    // return false;
    // Write your code here.
}
