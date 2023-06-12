#include <bits/stdc++.h>
// int cnt=0; 
void merge(vector<int> &arr, int l,int mid,int h)
{
	int left=l,right=mid+1;
	vector<int> temp;
	while(left<=mid && right<=h)
	{
		if(arr[left]<=arr[right])
		{
			temp.push_back(arr[left]);
			left++;
		}
		else
		{
			temp.push_back(arr[right]);
			right++;
		}
	}
	while(left<=mid)
	{
		temp.push_back(arr[left]);
		left++;
	}
	while(right<=h)
	{
		temp.push_back(arr[right]);
		right++;
	}
	for(int i=l;i<=h;i++)
	{
		arr[i]=temp[i-l];
	}
}
int cntpair(vector<int> &arr, int l,int mid,int h)
{
	int right=mid+1,cnt=0;
	for(int i=l;i<=mid;i++)
	{
		while(right<=h && arr[i] > 2*arr[right])
		{
			right++;
		}
		cnt+=(right-(mid+1));
	}
	return cnt;
}
int mergesort(vector<int> &arr, int l,int h)
{
	int cnt=0;
	if(l>=h)
	{
		return cnt;
	}
	
	int mid=(l+h)/2;
	cnt+=mergesort(arr,l, mid);
	cnt+=mergesort(arr,mid+1,h);	
	
	cnt+=cntpair(arr,l,mid,h);
	merge(arr,l,mid,h);
	return cnt;
}
int reversePairs(vector<int> &arr, int n){
	return mergesort(arr,0,n-1);
	// return cnt;
	// Write your code here.	
}
