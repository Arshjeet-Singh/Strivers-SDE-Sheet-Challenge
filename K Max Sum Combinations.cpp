#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	vector<int> ans;
	priority_queue<pair<int,pair<int,int>>> pq;
	set<pair<int,int>> s;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	s.insert({n-1,n-1});
	pq.push({a[n-1]+b[n-1],{n-1,n-1}});
	while(k>0)
	{
		auto e1=pq.top();
		pq.pop();
		ans.push_back(e1.first);
		int l=e1.second.first,r=e1.second.second;
		if(l>0 && r>0 && s.find({l-1,r})==s.end())
		{
			s.insert({l-1,r});
			pq.push({a[l-1]+b[r],{l-1,r}});
		}
		if(l>0 && r>0 && s.find({l,r-1})==s.end())
		{
			s.insert({l,r-1});
			pq.push({a[l]+b[r-1],{l,r-1}});
		}
		k--;
	}
	return ans;
	// priority_queue<int,vector<int>,greater<int>> pq,pq1,pq2,pq3;
	// for(int i=0;i<n;i++)
	// {
	// 	pq.push(a[i]);
	// 	pq1.push(b[i]);
	// 	if(pq.size()>k)
	// 	{
	// 		pq.pop();
	// 	}
	// 	if(pq1.size()>k)
	// 	{
	// 		pq1.pop();
	// 	}
	// }
	// pq3=pq1;
	// while(!pq.empty())
	// {
	// 	int e1=pq.top();
	// 	pq1=pq3;
	// 	while(!pq1.empty())
	// 	{
	// 		int e2=pq1.top();
	// 		pq1.pop();
	// 		pq2.push(e1+e2);
	// 		if(pq2.size()>k)
	// 		{
	// 			pq2.pop();
	// 		}
	// 	}
	// 	pq.pop();
	// }
	// vector<int> v;
	// while(!pq2.empty())
	// {
	// 	v.push_back(pq2.top());
	// 	pq2.pop();
	// }
	// reverse(v.begin(),v.end());
	// return v;
	// Write your code here.
}
