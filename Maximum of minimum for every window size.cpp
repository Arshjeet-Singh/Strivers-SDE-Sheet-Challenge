#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> ans(n+1,INT_MIN);
    vector<int> ns(n+1,n);
    vector<int> ps(n+1,-1);
    stack<int> s1,s2;
    for(int i=n-1;i>=0;i--)
    {
        while(!s1.empty() && a[i]<=a[s1.top()])
        {
            s1.pop();
        }
        if(!s1.empty())
        {
            ns[i]=s1.top();
        }
        s1.push(i);
    }
    for(int i=0;i<n;i++)
    {
        while(!s2.empty() && a[i]<=a[s2.top()])
        {
            s2.pop();
        }
        if(!s2.empty())
        {
            ps[i]=s2.top();
        }
        s2.push(i);
    }
    for(int i=0;i<n;i++)
    {
        int len=ns[i]-ps[i]-1;
        ans[len]=max(ans[len],a[i]);
    }
    for(int i=n-1;i>=1;i--)
    {
        ans[i]=max(ans[i],ans[i+1]);
    }
    vector<int> res(n);
    for(int i=1;i<=n;i++)
    {
        res[i-1]=ans[i];
    }
    return res;
    // Write your code here.
}
