#include <bits/stdc++.h>
void swapifreq(vector<int>& arr1,vector<int>& arr2,int i,int j)
{
	if(arr1[i]>arr2[j])
	{
		swap(arr1[i],arr2[j]);
	}
}
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	//gap method
	int i=0,gap=(n+m)/2+(n+m)%2;
	int j=i+gap;
	while(gap>0)
	{
		i=0; j=i+gap;
		while(j<m+n)
		{
			if(i<m && j>=m)
			{
				swapifreq(arr1,arr2,i,j-m);
			}
			else if(i>=m && j>=m)
			{
				swapifreq(arr2,arr2,i-m,j-m);
			}
			else
			{
				swapifreq(arr1,arr1,i,j);
			}
			i++; j++;
		}
		if(gap==1)
		{
			break;
		}
		gap=(gap/2)+(gap%2);
	}
	for(int k=m;k<n+m;k++)
	{
		arr1[k]=arr2[k-m];
	}
	return arr1;
	//optimised method1
	/*int i=m-1,j=0;
	while(i>=0 && j<n)
	{
		if(arr1[i]>arr2[j])
		{
			swap(arr1[i],arr2[j]);
			i--; j++;
			// i--; j++;
		}
		else
		{
			break;
		}
	}
	sort(arr1.begin(),arr1.begin()+m);
	sort(arr2.begin(),arr2.end());
	for(int k=m;k<n+m;k++)
	{
		arr1[k]=arr2[k-m];
	}
	return arr1;*/
	// Write your code here.
}
