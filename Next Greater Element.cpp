#include <bits/stdc++.h> 
vector<int> nextGreater(vector<int> &arr, int n) 
{
    vector<int> ans;
    stack<int> s;
    s.push(INT_MAX);
    for(int i=n-1;i>=0;i--)
    {
        if(s.top()>arr[i])
        {
            if(s.top()==INT_MAX)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(s.top());
            }
            s.push(arr[i]);
        }
        else
        {
            while(s.top()<=arr[i])
            {
                s.pop();
            }
            if(s.top()==INT_MAX)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(s.top());
            }
            s.push(arr[i]);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
    // Write your code here

}
