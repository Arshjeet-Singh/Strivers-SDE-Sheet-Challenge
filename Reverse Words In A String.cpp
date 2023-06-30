#include<bits/stdc++.h>
string reverseString(string &str){
	string s="",ans="";
	stack<string> st;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]!=' ')
		{
			s+=str[i];
		}
		if(str[i]==' ' || i==str.size()-1)
		{
			if(s.size())
			{
				st.push(s);
				s.clear();
			}
		}
	}
	while(!st.empty())
	{
		ans+=st.top();
		if(st.size())
		{
			ans+=' ';
		}
		st.pop();
	}
	return ans;
	// int i=0;

	// while(i<str.size())
	// {
	// 	bool f=0;
	// 	if(str[i]==' ' || i==str.size()-1)
	// 	{
	// 		while(i<str.size() && str[i]==' ')
	// 		{
	// 			// f=1;
	// 			i++;
	// 		}
	// 		ans.insert(0,s);
	// 		// if(i!=str.size()-1)
	// 		// {
	// 		// 	ans.insert(0," ");
	// 		// }
			
	// 		s="";
	// 		// continue;
	// 	}
	// 	else
	// 	{
	// 		s+=str[i];
	// 		i++;
	// 	}
		
	// }
	return ans;
	// Write your code here.	
}
