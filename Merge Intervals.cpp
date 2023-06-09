#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(),intervals.end());
    int n=intervals.size();
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    for(int i=1;i<n;i++)
    {
        vector<int> v;
        int ind=ans.size()-1;
        if(ans[ind][1]>=intervals[i][0])
        {
            int l=ans[ind][0],h=ans[ind][1];
            ans.pop_back();
            v.push_back(l);
            int ele=max(h,intervals[i][1]);
            v.push_back(ele);
            ans.push_back(v);
        }
        else
        {
            ans.push_back(intervals[i]);
        }
    }
    return ans;
    // Write your code here.
}
