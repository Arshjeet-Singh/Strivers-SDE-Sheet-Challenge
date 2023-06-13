#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
    }
    int cnt=0,longest=1;
    for(auto it:s)
    {
        if(s.find(it-1)==s.end())
        {
            int ele=it;
            int cnt=1;
            while(s.find(ele+1)!=s.end())
            {
                cnt++;
                ele++;
            }
            longest=max(longest,cnt);
        }
    }
    return longest;
    // Write your code here.
}
