#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	long ans=1;
	// if(n==0)
	// {
	// 	return 1;
	// }
	int nn=n;
	long xx=x;
	while(nn>0)
	{
		if(nn%2)
		{
			ans=((ans)%m*xx)%m;
			nn--;
		}
		else
		{
			xx=(xx*xx)%m;
			nn=nn/2;
		}
	}
	return ans%m;
	// Write your code here.
}
