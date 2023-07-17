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
vector<int> findMedian(vector<int> &arr, int n){
	priority_queue<int> maxi;
	priority_queue<int,vector<int>,greater<int>> mini;
	vector<int> ans;
	int median=0;
	for(int i=0;i<n;i++)
	{
		int a=maxi.size(),b=mini.size();
		int val=signum(a,b);
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
				int maxitop=maxi.top();
				maxi.pop();
				mini.push(maxitop);
				maxi.push(arr[i]);
				median=(maxi.top()+mini.top())/2;
			}
		}
		else
		{
			if(arr[i]>median)
			{
				int minit=mini.top();
				mini.pop();
				maxi.push(minit);
				mini.push(arr[i]);
				median=(maxi.top()+mini.top())/2;
			}
			else
			{
				maxi.push(arr[i]);
				median=(maxi.top()+mini.top())/2;
			}
		}
		ans.push_back(median);
	}
	return ans;
	// Write your code here 
}
