#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    vector<pair<int,int>> v;
    int N=start.size();
        for(int i=0;i<N;i++)
        {
            v.push_back({end[i],i});
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        ans.push_back(v[0].second+1);
        int curr=0;
        for(int i=1;i<N;i++)
        {
            if(start[v[i].second]>v[curr].first)
            {
                ans.push_back(v[i].second+1);
                curr=i;
            }
        }
        // sort(ans.begin(),ans.end());
        return ans;
   
    // Write your code here.
}
