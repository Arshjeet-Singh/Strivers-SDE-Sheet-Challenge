#include <bits/stdc++.h> 
static bool cmp(vector<int> a,vector<int> b)
{
    return a[1]>b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    int n=jobs.size();
    int maxidead=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(jobs[i][0]>maxidead)
        {
            maxidead=jobs[i][0];
        }
    }
    vector<int> dead(maxidead+1,-1);
    int ans=0;
    sort(jobs.begin(),jobs.end(),cmp);
    for(int i=0;i<n;i++)
    {
        int d=jobs[i][0];
        for(int j=d;j>0;j--)
        {
            if(dead[j]==-1)
            {
                dead[j]=i;
                ans+=jobs[i][1];
                break;
            }
        }
    }
    return ans;
    // Write your code here
}
