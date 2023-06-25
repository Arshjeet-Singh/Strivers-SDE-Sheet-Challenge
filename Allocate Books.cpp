#include <bits/stdc++.h> 
bool possible(int n, int m,long long int mid,vector<int> &time)
{
	long long int sum=0;
	long long int cnt=1;
	for(int i=0;i<m;i++)
	{
		if(sum+time[i]<=mid)
		{
			sum+=time[i];
		}
		else
		{
			cnt++;
			if(cnt>n || time[i]>mid)
			{
				return false;
			}
			sum=time[i];
		}
	}
	return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{
	// if(m<n)
	// {
	// 	return -1;
	// }
	int maxi=INT_MIN;
	long long su=0;
	for(int i=0;i<m;i++)
	{
		// maxi=max(time[i],maxi);
		su+=time[i];
		// maxi=max(time[i],maxi);
	}
	long long int l=0,h=su;
	long long ans=-1;
	// sort(time.begin(),time.end());
	while(l<=h)
	{
		long long int mid=(l+h)/2;
		if(possible(n,m,mid,time))
		{
			ans=mid;
			h=mid-1;
			
		}
		else
		{
			l=mid+1;
		}
	}
	return ans;	
	// Write your code here.
}
