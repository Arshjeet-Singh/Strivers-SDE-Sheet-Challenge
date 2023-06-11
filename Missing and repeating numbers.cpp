#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int rep,mis;
	for(int i=0;i<n;i++)
	{
		int ind=abs(arr[i])-1;
		if(arr[ind]<0)
		{
			rep=ind+1;
		}
		else
		{
			arr[ind]=-arr[ind];
		}
		
	}
	for(int i=0;i<n;i++)
	{
		if(arr[i]>0)
		{
			mis=i+1;
		}
	}
	return {mis,rep};
	// Write your code here 
	
}
