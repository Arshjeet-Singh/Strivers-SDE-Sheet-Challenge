#include<bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	sort(arr.begin(),arr.end());
	vector<vector<int>> ans;
	for(int i=0;i<n;i++)
	{
		if(i!=0 && arr[i]==arr[i-1])
		{
			continue;
		}
		// int ele1=arr[i];
		int j=i+1,k=n-1;
		// int s=K-arr[i];
		while(j<k && j<n && k>=0)
		{
			if(arr[j]+arr[k]+arr[i]==K)
			{
				vector<int> v={arr[i],arr[j],arr[k]};
				// v.push_back(arr[i]);
				// v.push_back(arr[j]);
				v.push_back(arr[k]);
				ans.push_back(v);
				j++; k--;
				while(j<k && arr[j]==arr[j-1])
				{
					j++;
				}
				while(j<k && arr[k]==arr[k+1])
				{
					k--;
				}
			}
			else if(arr[i]+arr[j]+arr[k]<K)
			{
				j++;
			}
			else
			{
				k--;
			}

		}
	}
	if(ans.size()==0)
	{
		vector<int> v;
		v.push_back(-1);
	}
	return ans;
	// Write your code here.
}
