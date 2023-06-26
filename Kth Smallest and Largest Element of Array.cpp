#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{

	vector<int> v;
	sort(arr.begin(),arr.end());
	v.push_back(arr[k-1]);
	v.push_back(arr[n-k]);
	// priority_queue<int,vector<int>,greater<int>> pq;
	// priority_queue<int> pq1;
	// for(int i=0;i<n;i++)
	// {
	// 	pq.push(arr[i]);
	// 	if(pq.size()>k)
	// 	{
	// 		pq.pop();
	// 	}
	// 	pq1.push(arr[i]);
	// 	if(pq1.size()>k)
	// 	{
	// 		pq1.pop();
	// 	}
	// }
	// v.push_back(pq1.top());
	// v.push_back(pq.top());
	return v;
	// Write your code here.
}
