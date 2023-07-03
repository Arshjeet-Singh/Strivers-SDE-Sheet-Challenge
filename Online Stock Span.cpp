#include <bits/stdc++.h> 
vector<int> pg(vector<int> &price)
{   
    // vector<int> ans;
    // stack<pair<int,int>> s;
    // s.push({INT_MAX,-1});
    // int n=ans.size();
    // for(int i=0;i<n;i++)
    // {
    //     if(s.top().first>price[i])
    //     {
    //         ans.push_back(s.top().second);
    //         s.push({price[i],i});
    //     }
    //     else
    //     {
    //         while(s.top().first<=price[i])
    //         {
    //             s.pop();
    //         }
            // ans.push_back(s.top().second);
            // if(s.top()==INT_MAX)
            // {
            //     ans.push_back(-1);
            // } else {
            //   ans.push_back(s.top());
            // }
    //         s.push({price[i],i});
    //     }
    // }
    // return ans;
    stack<int> s;
    vector<int> ans;
    s.push(INT_MAX);
        int n=price.size();
    for(int i=0;i<n;i++)
    {
            while(s.top()!=INT_MAX && price[i]>=price[s.top()])
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
        s.push(i);
    }
    return ans;
}
vector<int> findSpans(vector<int> &price) {
    vector<int> prev=pg(price);
    vector<int> ans;
    int n=price.size();
    for(int i=0;i<n;i++)
    {
        if(prev[i]==-1)
        {
            ans.push_back(i+1);
        }
        else
        {
            ans.push_back(i-prev[i]);
        }
    }
    return ans;
    // Write your code here.
}
