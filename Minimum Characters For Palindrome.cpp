
int minCharsforPalindrome(string str) {
	int i=0;
	int j=str.length()-1;
	int trim=j;
	int res=0;
	while(i<j)
	{
		if(str[i]==str[j])
		{
			i++; j--;
		}
		else
		{
			res++;
			i=0;
			j=--trim;
		}
	}
	return res;
	// Write your code here.
	
}
