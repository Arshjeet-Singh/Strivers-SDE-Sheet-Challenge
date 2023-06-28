#include<stack>
#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans;
    for(int i=n-1;i>=0;i--)
    {
        int ele=s.top();
        if(ele<arr[i])
        {
            ans.push_back(ele);
            s.push(arr[i]);
        }
        else
        {
          while (s.top() >= arr[i]) 
          {
              s.pop();
          }
          ans.push_back(s.top());
          s.push(arr[i]);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
    // Write your code here.
}
