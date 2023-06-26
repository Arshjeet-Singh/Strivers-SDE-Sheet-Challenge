#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // priority_queue<pair<int,pair<int,int>>>,vector<pair<int,pair<int,int>>>>,greater<pair<int,pair<int,int>>>>> pq;
     priority_queue<pair<int,pair<int,int>>,

    vector<pair<int,pair<int,int>>>,

    greater<pair<int,pair<int,int>>>>pq;
    for(int i=0;i<k;i++)
    {
      pq.push({kArrays[i][0], {i,0}});
    }
    vector<int> ans;
    while(!pq.empty())
    {
        auto a=pq.top();
        pq.pop();
        int val=a.first;
        int num=a.second.first;
        int ind=a.second.second;
        ans.push_back(val);
        if(ind+1<kArrays[num].size())
        {
            pq.push({kArrays[num][ind+1],{num,ind+1}});
        }
    }
    return ans;
    // Write your code here. 
}
