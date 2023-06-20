#include <bits/stdc++.h>
static bool cmp(pair<int, int> a,pair<int, int> b)
{
    return 1.0*a.second/a.first > 1.0*b.second/b.first;
} 
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    double ans=0;
    sort(items.begin(),items.end(),cmp);
    int k=w;
    for(int i=0;i<n;i++)
    {
        if(items[i].first<=k)
        {
            ans+=items[i].second;
            k-=items[i].first;
        }
        else
        {
            double part=(items[i].second*1.0/items[i].first)*k;
            ans+=part;
            break;
        }
    }
    return ans;
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
}
