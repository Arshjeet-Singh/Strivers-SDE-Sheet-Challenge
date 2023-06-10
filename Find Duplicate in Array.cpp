#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	int i=0;
	for(int i=0;i<n;i++)
	{
		int ind=abs(arr[i]);
		if(arr[ind]<0)
		{
			return ind;
		}
		arr[ind]=-arr[ind];
	}
	return -1;
	// Write your code here.
}
