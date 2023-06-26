#include<bits/stdc++.h>
int signum(int a,int b)
{
    if(a==b)
    {
        return 0;
    }
    else if(a>b)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
void findMedian(int *arr, int n)
{
    priority_queue<int> maxi;
    priority_queue<int,vector<int>,greater<int>> mini;
    int a=maxi.size(),b=mini.size();
    int val=signum(a,b);
    int median=0;
    for(int i=0;i<n;i++)
    {
        a=maxi.size(),b=mini.size();
        val=signum(a,b);
        if(val==0)
        {
            if(arr[i]>median)
            {
                mini.push(arr[i]);
                median=mini.top();
            }
            else
            {
                maxi.push(arr[i]);
                median=maxi.top();
            }
        }
        else if(val==1)
        {
            if(arr[i]>median)
            {
                mini.push(arr[i]);
                median=(maxi.top()+mini.top())/2;
            }
            else
            {
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(arr[i]);
                median=(maxi.top()+mini.top())/2;
            }
        }
        else
        {
            if(arr[i]>median)
            {
                maxi.push(mini.top());
                mini.pop();
                mini.push(arr[i]);
                median=(maxi.top()+mini.top())/2;
            }
            else
            {
                maxi.push(arr[i]);
                median=(maxi.top()+mini.top())/2;
            }
        }
        cout<<median<<" ";
    }
    // Write your code here
}
