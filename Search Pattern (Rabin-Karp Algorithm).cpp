vector<int> stringMatch(string text, string pattern) {
	int n=text.size();
	int m=pattern.length();
	int d=256;
	int j,p=0,t=0,h=1;
	vector<int> ans;
	int q=19;
	for(int i=0;i<m-1;i++)
	{
		h=(h*d)%q;
	}
	for(int i=0;i<m;i++)
	{
		p=(d*p +pattern[i])%q;
		t=(d*t+text[i])%q;
	}
	for(int i=0;i<=n-m;i++)
	{
		if(p==t)
		{
			for(j=0;j<m;j++)
			{
				if(pattern[j]!=text[i+j])
				{
					break;
				}
			}
			if(j==m)
			{
				ans.push_back(i+1);
			}
		}
		if(i<n-m)
		{
			t=(d*(t-text[i]*h)+text[i+m])%q;
			if(t<0)
			{
				t+=q;
			}
		}
	}
	// int ind=0,i=0;
	// vector<int> ans;
	// while(i<n)
	// {
	// 	char ch=pattern[ind];
	// 	if(text[i]==ch)
	// 	{
	// 		int trav=ind;
	// 		int st=i;
	// 		int tr=i;
	// 		while(tr<n && trav<m && text[tr]==pattern[trav])
	// 		{
	// 			tr++; trav++;
	// 		}
	// 		if(trav==m)
	// 		{
	// 			ans.push_back(st+1);
	// 		}
	// 	}
	// 	i++;
	// }
	return ans;
	// Write your code here.
}
