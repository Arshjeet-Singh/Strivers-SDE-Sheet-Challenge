double median(vector<int>& a, vector<int>& b) {
	if(b.size()<a.size())
	{
		return median(b, a);
	}
	int n1=a.size(),n2=b.size();
	int l=0,h=a.size();
	while(l<=h)
	{
		// int l1,l2,r1,r2;
		int cut1=l+(h-l)/2;
		int cut2=(n1+n2+1)/2 -cut1;
		// if(cut1==0)
		// {
		// 	l1=INT_MIN;
		// }
		// else
		// {
		// 	l1=a[cut1-1];
		// }
		// if(cut2==0)
		// {
		// 	l2=INT_MIN;
		// }
		// else
		// {
		// 	l2=b[cut2-1];
		// }
		// if(cut1==n1)
		// {
		// 	r1=INT_MAX;
		// }
		// else
		// {
		// 	r1=a[cut1];
		// }
		// if(cut2==n2)
		// {
		// 	r2=INT_MAX;
		// }
		// else
		// {
		// 	r2=a[cut2];
		// }
		  int l1 = cut1 == 0 ? INT_MIN : a[cut1 - 1];

        int l2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];

        int r1 = cut1 == n1 ? INT_MAX : a[cut1];

        int r2 = cut2 == n2 ? INT_MAX : b[cut2]; 
		if(l1<=r2 && l2<=r1)
		{
			if((n1+n2)%2==0)
			{
				return (max(l1,l2)+min(r1,r2))/2.0;
			}
			else
			{
				return max(l1,l2);
			}
		}
		else if(l1>r2)
		{
			h=cut1-1;
		}
		else
		{
			l=cut1+1;
		}
	}
	return 0.0;
	// int i=0,j=0;
	// int n=a.size(),m=b.size();
	// int c=(n+m)/2,d=(n+m)/2+1;
	// int k=0;
	// int e1=0,e2=0;
	// while(i<n && j<n)
	// {
	// 	if(a[i]<=b[j])
	// 	{
	// 		k++;
	// 		if(k==c)
	// 		{
	// 			e1=a[i];
	// 		}
	// 		if(k==d)
	// 		{
	// 			e2=a[i];
	// 		}
	// 		i++;
			
	// 	}
	// 	else
	// 	{
	// 		k++;
	// 		if(k==c)
	// 		{
	// 			e1=b[j];
	// 		}
	// 		if(k==d)
	// 		{
	// 			e2=b[j];
	// 		}
	// 		j++; 
	// 	}
	// }
	// while(i<n)
	// {
	// 	k++;
	// 	if(k==c)
	// 		{
	// 			e1=a[i];
	// 		}
	// 		if(k==d)
	// 		{
	// 			e2=a[i];
	// 		}
	// 		i++;
			
	// }
	// while(j<n)
	// {
	// 	k++;
	// 	if(k==c)
	// 		{
	// 			e1=b[j];
	// 		}
	// 		if(k==d)
	// 		{
	// 			e2=b[j];
	// 		}
	// 		j++; 
	// }
	// // cout<<e1<<"e1"<<e2<<"e2"<<endl;
	// if((n+m)%2==1)
	// {
	// 	return e1;
	// }
	// else
	// {
	// 	return (e1+e2)/2.0;
	// }
	// Write your code here.
}
