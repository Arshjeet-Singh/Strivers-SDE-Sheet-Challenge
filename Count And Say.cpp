#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	if(n==1)
	{
		return "1";
	}
	string s=writeAsYouSpeak(n-1);
	string s1="";
	int cnt=0;
	for(int i=0;i<s.length();i++)
	{
		cnt++;
		if(i==s.length()-1 || s[i]!=s[i+1])
		{
			s1+=to_string(cnt)+s[i];
			cnt=0;
		}
	}

	// if(n==2)
	// {
	// 	return "11";
	// }
	// string s="11";
	// for(int i=3;i<=n;i++)
	// {
	// 	string t="";
	// 	s+='#';
	// 	int c=1;
	// 	for(int j=1;j<s.length();j++)
	// 	{
	// 		if(s[j]!=s[j-1])
	// 		{
	// 			t+=to_string(c);
	// 			t+=s[j-1];
	// 			c=1;
	// 		}
	// 		else
	// 		{
	// 			c++;
	// 		}
	// 	}
	// 	s=t;
	// }
	return s1;
	// Write your code here.	
}
