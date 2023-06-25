#include <bits/stdc++.h> 
bool possible(vector<int> positions , int n ,  int c,int mid)
{
	int ccnt=1;
	int last=positions[0];
	for(int i=0;i<n;i++)
	{
		if(positions[i]-last>=mid)
		{
			ccnt++;
			last=positions[i];
			if(ccnt==c)
			{
				return true;
			}
		}
	}
	return false;
}
int chessTournament(vector<int> positions , int n ,  int c){
	int l=0,sum=0;
	int maxi=INT_MIN;
	for(int i=0;i<n;i++)
	{
		maxi=max(maxi,positions[i]);
	}
	int h=maxi;
	int ans=-1;
	sort(positions.begin(),positions.end());
	while(l<=h)
	{
		int mid=(l+h)/2;
		if(possible(positions,n,c,mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			h=mid-1;
		}
	}
	return ans;
	// Write your code here
}
