#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	int n=matrix.size();
	int m=matrix[0].size();
	vector<int> rlist,clist;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(matrix[i][j]==0)
			{
				rlist.push_back(i);
				clist.push_back(j);
			}
		}
	}
	for(int i=0;i<rlist.size();i++)
	{
		for(int j=0;j<m;j++)
		{
			matrix[rlist[i]][j]=0;
		}
	}
	for(int i=0;i<clist.size();i++)
	{
		for(int j=0;j<n;j++)
		{
			matrix[j][clist[i]]=0;
		}
	}
	// Write your code here.
}
