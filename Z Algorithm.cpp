int zAlgorithm(string s, string p, int n, int m)
{
	// string tot=p+'$'+s;
	// int i=0,j=m+1;
	// int tl=tot.length();
	// vector<int> z(tl);
	// while(j<tl)
	// {

	// }
	int cnt=0;
	for(int i=0;i<=n-m;i++)
	{
		int j;
		for(j=0;j<m;j++)
		{
			if(p[j]!=s[i+j])
			{
				break;
			}
		}
		if(j==m)
		{
			cnt++;
		}
	}
	return cnt;
	
	// Write your code here
}
