#include<bits/stdc++.h>
void help(int ind,vector<int> &arr, int n, int target,vector<int> v,vector<vector<int>> &ans)
{
	int s=0;
	for(int i=0;i<v.size();i++)
	{
		s+=v[i];
	}
	if(s==target)
	{
		ans.push_back(v);
		return;
	}
	for(int i=ind;i<n;i++)
	{
		if(i!=ind && arr[i]==arr[i-1])
		{
			continue;
		}
		v.push_back(arr[i]);
		help(i+1,arr,n,target,v,ans);
		v.pop_back();
	}
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	vector<vector<int>> ans;
	vector<int> v;
	sort(arr.begin(),arr.end());
	help(0,arr,n,target,v,ans);
	return ans;
	// Write your code here.
}
