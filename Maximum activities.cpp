#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n=start.size();
    // int ans=0;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        v.push_back({finish[i],i});
    }
    sort(v.begin(),v.end());
    int ans=1;
    int curr=0;
    for(int i=1;i<n;i++)
    {
        if(start[v[i].second]>=v[curr].first)
        {
            ans++;
            curr=i;
        }
    }
    return ans;
    // Write your code here.
}
