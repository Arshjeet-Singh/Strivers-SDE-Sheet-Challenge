#include <bits/stdc++.h> 
class temp{
	public:
	int height;
	int leftindex;
	int rightindex;
	temp(int h,int li,int ri)
	{
		height=h;
		leftindex=li;
		rightindex=ri;
	}
};

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
	int maxih=0;
	queue<temp> q;
	if(N>=1)
	{
		temp t(0,0,N-1);
		q.push(t);
	}
	unordered_map<int,int> mp;
	for(int i=0;i<N;i++)
	{
		mp[inorder[i]]=i;
	}
	for(int i=0;i<N;i++)
	{
		temp t=q.front();
		q.pop();
		maxih=max(t.height,maxih);
		int li=t.leftindex;
		int ri=t.rightindex;
		int rootind=mp[levelOrder[i]];
		if(rootind>=li+1)
		{
			temp lst(t.height+1,li,rootind-1);
			q.push(lst);
		}
		if(rootind<=ri-1)
		{
			temp rst(t.height+1,rootind+1,ri);
			q.push(rst);
		}
	}
	return maxih;
	// Write your code here.
}
